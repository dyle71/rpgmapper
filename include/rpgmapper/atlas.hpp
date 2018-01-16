/*
 * atlas.hpp
 *
 * Copyright (C) 2015-2018 Oliver Maurhart, <dyle71@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef MODEL_ATLAS_HPP
#define MODEL_ATLAS_HPP


// ------------------------------------------------------------
// incs

#include <memory>

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

// rpgmapper
#include "nameable.hpp"
#include "map.hpp"
#include "region.hpp"
#include "types.hpp"


// ------------------------------------------------------------
// decl


namespace rpgmapper {
namespace model {


/**
 * A single atlas holds regions with maps each.
 *
 * Note: copy an Atlas instance is shallow. For a deep copy use the "clone()" method.
 */
class Atlas : public Nameable {


    Q_OBJECT


public:


    /**
     * Ctor.
     *
     * @param   cParent     parent object
     */
    explicit Atlas(QObject * cParent = nullptr);


    /**
     * Creates a new map to this atlas.
     *
     * @return  a reference to the new map
     */
    MapPointer createMap();


    /**
     * Creates a new region to this atlas.
     *
     * @return  a reference to the new region
     */
    RegionPointer createRegion();


    /**
     * Create a json string form this atlas.
     *
     * @param   eJsonFormat     the format for representation
     * @return  a string holding the atlas in json format
     */
    QString json(QJsonDocument::JsonFormat eJsonFormat = QJsonDocument::Indented) const;


    /**
     * Load the atlas from json.
     *
     * @param   cJSON       the json instance to load from
     */
    void load(QJsonObject const & cJSON) override;


    /**
     * Return all the maps managed by this atlas.
     *
     * @return  all maps of this atlas
     */
    Maps & maps();


    /**
     * Return all the maps managed by this atlas.
     *
     * @return  all maps of this atlas
     */
    Maps const & maps() const;


    /**
     * State if the atlas (and any descendants) has changed.
     *
     * @return  true, if the atlas (or any descendants) has changed.
     */
    bool modified() const override;


    /**
     * Set the atlas and all descendants to a new modification state.
     *
     * @param   bModified       the new modification state
     */
    void modified(bool bModified) override;


    /**
     * Return all the regions managed by this atlas.
     *
     * @return  all regions of this atlas
     */
    Regions & regions();


    /**
     * Return all the regions managed by this atlas.
     *
     * @return  all regions of this atlas
     */
    Regions const & regions() const;


    /**
     * Save the atlas to json.
     *
     * @param   cJSON       the json instance to save to
     */
    void save(QJsonObject & cJSON) const override;


private slots:


    /**
     * The id of a map changed.
     *
     * @param   nOldId      the old id
     */
    void changedMapId(Map::id_t nOldId);


    /**
     * The id of a region changed.
     *
     * @param   nOldId      the old id
     */
    void changedRegionId(Region::id_t nOldId);


private:


    /**
     * Reset the atlas to an empty state.
     */
    void clear();


    class Atlas_data;                               /**< internal data type */
    std::shared_ptr<Atlas::Atlas_data> d;           /**< internal data instance */

};


}
}


#endif