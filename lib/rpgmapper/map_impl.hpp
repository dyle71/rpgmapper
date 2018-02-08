/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#ifndef RPGMAPPER_MODEL_MAP_IMPL_HPP
#define RPGMAPPER_MODEL_MAP_IMPL_HPP


#include <rpgmapper/map.hpp>
#include "nameable.hpp"

using namespace rpgmapper::model;


namespace rpgmapper {
namespace model {


class Map::Impl final : public Nameable {

    QString name;
    Region * region = nullptr;

public:

    explicit Impl(Region * region);

    Impl(Impl const & ) = delete;

    bool applyJsonObject(QJsonObject const & json) override;

    QJsonObject getJsonObject() const override ;

    Region * getRegion() { return region; }
};

}
}


#endif
