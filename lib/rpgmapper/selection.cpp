/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#include <rpgmapper/selection.hpp>

using namespace rpgmapper::model;


Selection::Selection(QObject * parent) : QObject(parent) {
    atlas = AtlasPointer{new InvalidAtlas{}};
    map = MapPointer{new InvalidMap{}};
    region = RegionPointer{new InvalidRegion{}};
}


void Selection::setAtlas(AtlasPointer atlas) {
    this->atlas = atlas;
    emit newAtlas();
}


void Selection::selectMap(MapPointer map) {
    if (this->map->getName() != map->getName()) {
        return;
    }
    this->map = map;
    emit mapSelected(map->getName());
}


void Selection::selectRegion(RegionPointer region) {
    if (this->region->getName() != region->getName()) {
        return;
    }
    this->region = region;
    emit regionSelected(region->getName());
}




















#if 0


#include <QJsonArray>

// rpgmapper
#include <rpgmapper/field.hpp>

using namespace rpgmapper::model;


// ------------------------------------------------------------
// code


/**
 * Load a tile from json.
 *
 * @param   cJSON       the json instance to load from
 */
Field rpgmapper::model::loadFromJson(QJsonObject const & cJSON) {

    Field cField{{0, 0}, {}};

    // TODO: split in smaller logical parts, make decouling

    if (cJSON.contains("position") && cJSON["position"].isObject()) {
        auto cJSONPosition = cJSON["position"].toObject();
        if (cJSONPosition.contains("x") && cJSONPosition["x"].isDouble()) {
            cField.cPosition.setX(cJSONPosition["x"].toInt());
        }
        if (cJSONPosition.contains("y") && cJSONPosition["y"].isDouble()) {
            cField.cPosition.setY(cJSONPosition["y"].toInt());
        }
    }

    if (cJSON.contains("tiles") && cJSON["tiles"].isArray()) {

        auto cJSONTiles = cJSON["tiles"].toArray();
        for (auto && cJSONTile : cJSONTiles) {

            Tile cTile;
            for (auto && iter : cJSONTile.toArray()) {

                QString sName;
                QString sValue;
                auto cJSONAttribute = iter.toObject();
                if (cJSONAttribute.contains("setName") && cJSONAttribute["setName"].isString()) {
                    sName = cJSONAttribute["setName"].toString();
                }
                if (cJSONAttribute.contains("value") && cJSONAttribute["value"].isString()) {
                    sValue = cJSONAttribute["value"].toString();
                }
                cTile[sName] = sValue;
            }
            cField.cTiles.push_back(cTile);
        }
    }

    return cField;
}


/**
 * Save a tile to json.
 *
 * @param   cField       the tile to save
 */
QJsonObject rpgmapper::model::saveToJson(Field const & cField) {

    QJsonObject cJSON;

    // TODO: split in smaller logical parts make a decoupling

    QJsonObject cJSONPosition;
    cJSONPosition["x"] = cField.cPosition.x();
    cJSONPosition["y"] = cField.cPosition.y();
    cJSON["position"] = cJSONPosition;

    QJsonArray cJSONTiles;
    for (auto const & cTile : cField.cTiles) {

        QJsonArray cJSONAttributes;
        for (auto const & cPair : cTile) {
            QJsonObject cJSONAttribute;
            cJSONAttribute["name"] = cPair.first;
            cJSONAttribute["value"] = cPair.second;
            cJSONAttributes.append(cJSONAttribute);
        }
        cJSONTiles.append(cJSONAttributes);
    }
    cJSON["tiles"] = cJSONTiles;

    return cJSON;
}


#endif