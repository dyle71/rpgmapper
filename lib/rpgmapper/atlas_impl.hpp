/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#ifndef RPGMAPPER_MODEL_ATLAS_IMPL_HPP
#define RPGMAPPER_MODEL_ATLAS_IMPL_HPP


#include <rpgmapper/atlas.hpp>
#include "nameable.hpp"

using namespace rpgmapper::model;

namespace rpgmapper {
namespace model {

class Atlas::Impl final : public Nameable {

    Atlas * atlas = nullptr;
    bool changed = false;
    Regions regions;

public:

    explicit Impl(Atlas * atlas);

    Impl(Impl const &) = delete;

    bool applyJsonObject(QJsonObject const & json) override;

    void clear() override;

    RegionPointer createRegion(QString const & name);

    std::set<QString> getAllMapNames() const;

    std::set<QString> getAllRegionNames() const;

    QJsonObject getJsonObject() const override;

    RegionPointer const & getRegion(QString const & name) const;

    Regions const & getRegions() const { return regions; }

    bool hasChanged() const { return changed; }

    void init();

    bool removeRegion(QString const & name);

    void resetChanged();

    void setName(QString const & name) override;

private:

    bool applyJsonRegionsArray(QJsonArray const & jsonRegions);

};

}
}


#endif