/*
 * region.hpp
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


#ifndef MODEL_REGION_HPP
#define MODEL_REGION_HPP


// ------------------------------------------------------------
// incs

#include <map>
#include <memory>

#include <QJsonObject>

// rpgmapper
#include "nameable.hpp"
#include "types.hpp"


// ------------------------------------------------------------
// decl


namespace rpgmapper {
namespace model {


/**
 * A collection of maps based on a name.
 *
 * Note: copy an Region instance is shallow. For a deep copy use the "clone()" method.
 */
class Region : public Nameable {


    Q_OBJECT


public:


    /**
     * Type of a region's ID.
     */
    typedef int id_t;


    /**
     * Create a new region (factory method).
     *
     * @param   cAtlas      parent object
     * @param   nId         the id of the new region (id < 0 a new will be assigned)
     * @return  a new region
     */
    static RegionPointer create(Atlas * cAtlas, id_t nId = -1);


    /**
     * Return the id of the region.
     *
     * @return  the id of the region
     */
    id_t id() const { return m_nId; }


    /**
     * Load the region from json.
     *
     * @param   cJSON       the json instance to load from
     */
    void load(QJsonObject const & cJSON) override;


    /**
     * Means to order this region among other regions.
     *
     * @return  a value indicating the position of this region among others
     */
    int orderValue() const;


    /**
     * Set the means to order this region among other regions.
     *
     * @param   nOrderValue     a value indicating the position of this region among others
     */
    void orderValue(int nOrderValue);


    /**
     * Save the region to json.
     *
     * @param   cJSON       the json instance to save to
     */
    void save(QJsonObject & cJSON) const override;


public slots:


    /**
     * Reset the region to an empty state.
     */
    void clear();


signals:


    /**
     * The id of the region changed.
     *
     * @param   nOldId      the old id
     */
    void changedId(id_t nOldId);


private:


    /**
     * Ctor.
     *
     * @param   cAtlas      parent object
     * @param   nId     id of the region
     */
    explicit Region(Atlas * cAtlas, Region::id_t nId);


    id_t m_nId;                                     /**< region id */

    class Region_data;                              /**< internal data type */
    std::shared_ptr<Region::Region_data> d;         /**< internal data instance */

};


/**
 * Multiple regions.
 */
typedef std::map<Region::id_t, RegionPointer> Regions;


}
}


#endif