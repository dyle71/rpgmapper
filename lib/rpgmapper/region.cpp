/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#include <rpgmapper/atlas.hpp>
#include "region_impl.hpp"

using namespace rpgmapper::model;


Region::Region(QString const & name, Atlas * atlas) : QObject{atlas} {
    impl = std::make_shared<Region::Impl>(atlas, this);
    impl->setName(name);
}

bool Region::addMap(QSharedPointer<rpgmapper::model::Map> & map) {

    if (!map->isValid()) {
        return false;
    }
    if (findMap(map->getName())->isValid()) {
        return false;
    }

    auto added = impl->addMap(map);
    connectMapSignals(map);
    emit mapAdded(getName(), map->getName());
    return added;
}


bool Region::applyJSON(QJsonObject const & json) {
    return impl->applyJSON(json);
}


void Region::changedMapName(QString nameBefore, QString nameAfter) {
    auto map = findMap(nameBefore);
    if (!map->isValid()) {
        return;
    }
    impl->removeMap(nameBefore);
    impl->addMap(map);
    emit mapNameChanged(getName(), nameBefore, std::move(nameAfter));
}


void Region::changedNumeralForAxis(QString mapName) {
    emit mapNumeralForAxisChanged(getName(), mapName);
}


void Region::connectMapSignals(QSharedPointer<rpgmapper::model::Map> & map) {
    if (!map->isValid()) {
        return;
    }
    connect(map.data(), &Map::nameChanged, this, &Region::changedMapName);
    connect(map.data(), &Map::numeralForAxisChanged, this, &Region::changedNumeralForAxis);
    connect(map.data(), &Map::resized, this, &Region::resizedMap);
}


QSharedPointer<rpgmapper::model::Map> & Region::createMap(QString const & mapName) {
    auto & map = impl->createMap(mapName);
    if (map->isValid()) {
        connectMapSignals(map);
        emit mapCreated(getName(), mapName);
    }
    return map;
}


void Region::disconnectMapSignals(QSharedPointer<rpgmapper::model::Map> & map) {
    if (!map->isValid()) {
        return;
    }
    disconnect(map.data());
}


Atlas * Region::getAtlas() {
    return impl->getAtlas();
}


Atlas const * Region::getAtlas() const {
    return impl->getAtlas();
}


QSharedPointer<rpgmapper::model::Map> & Region::findMap(QString const & mapName) {
    return impl->findMap(mapName);
}


QString Region::getInvalidCharactersInName() {
    return Region::Impl::getInvalidCharactersInName();
}


QJsonObject Region::getJSON(rpgmapper::model::io::Content & content) const {
    return impl->getJSON(content);
}

Maps const & Region::getMaps() const {
    return impl->getMaps();
}


std::set<QString> Region::getMapNames() const {
    return impl->getMapNames();
}


QString const & Region::getName() const {
    return impl->getName();
}


ResourceDBPointer & Region::getResourceDB() {
    return getAtlas()->getResourceDB();
}


ResourceDBPointer const & Region::getResourceDB() const {
    return getAtlas()->getResourceDB();
}

bool Region::isNameValid(QString name) {
    return Region::Impl::isNameValid(name);
}


QSharedPointer<rpgmapper::model::Region> const & Region::null() {
    static QSharedPointer<rpgmapper::model::Region> nullRegion{new InvalidRegion};
    return nullRegion;
}


void Region::resizedMap(QString mapName) {
    emit mapResized(getName(), mapName);
}


void Region::removeMap(QString const & mapName) {
    auto map = findMap(mapName);
    if (!map->isValid()) {
        return;
    }
    impl->removeMap(mapName);
    disconnectMapSignals(map);
    emit mapRemoved(getName(), mapName);
}


void Region::setName(QString const & name) {
    auto nameBefore = impl->getName();
    if (name == nameBefore) {
        return;
    }
    impl->setName(name);
    emit nameChanged(nameBefore, name);
}
