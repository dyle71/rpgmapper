/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */

#ifndef RPGMAPPER_MODEL_MAP_HPP
#define RPGMAPPER_MODEL_MAP_HPP

#include <QObject>
#include <QSharedPointer>
#include <QString>

#include <rpgmapper/json/json_io.hpp>
#include <rpgmapper/layer/layer_stack.hpp>
#include <rpgmapper/map_pointer.hpp>
#include <rpgmapper/nameable.hpp>


namespace rpgmapper {
namespace model {


// fwd
class CoordinateSystem;


/**
 * A single map.
 *
 * This is the heart of the rpgmapper. A map is a collection of layers,
 * which in turn define tiles, background, texts, etc. it has a name and
 * a coordinate system attached.
 */
class Map : public Nameable {
    
    Q_OBJECT

    QSharedPointer<CoordinateSystem> coordinateSystem;      /**< the coordinate system of the map */
    LayerStack layerStack;                                  /**< The layer stack of this map. */

public:

    /**
     * Creates a map with a given name inside a region.
     *
     * @param   mapName         the new name of the map.
     */
    explicit Map(QString mapName);

    /**
     * Applies a JSON to this instance.
     *
     * @param   json    the JSON.
     * @return  true, if the found values in the JSON data has been applied.
     */
    bool applyJSON(QJsonObject const & json) override;
    
    /**
     * Gets the coordinate system of the map.
     *
     * @return  the coordinate system of the map.
     */
    QSharedPointer<CoordinateSystem> getCoordinateSystem() {
        return coordinateSystem;
    }
    
    /**
     * Gets the coordinate system of the map (const version).
     *
     * @return  the coordinate system of the map.
     */
    QSharedPointer<CoordinateSystem> const getCoordinateSystem() const {
        return coordinateSystem;
    }
    
    /**
     * Create a JSON structure from ourselves.
     *
     * @return      a valid JSON  structure from ourselves.
     */
    QJsonObject getJSON() const override;
    
    /**
     * Gets the layers of this map.
     *
     * @return  all the layers of this map.
     */
    LayerStack & getLayers() {
        return layerStack;
    }
    
    /**
     * Gets the layers of this map (const version).
     *
     * @return  all the layers of this map.
     */
    LayerStack const & getLayers() const {
        return layerStack;
    }
    
    /**
     * Checks if this is a valid map.
     *
     * @return  returns true, if this is a valid map.
     */
    virtual bool isValid() const {
        return true;
    }

    /**
     * Returns the invalid null map pointer.
     *
     * [null object pattern]
     *
     * @return  an invalid null map.
     */
    static MapPointer const & null();
    
    /**
     * Places the given tile on the specified position.
     *
     * @param   x           X position to place tile.
     * @param   y           Y posiiton to place tile.
     * @param   tile        The tile to place.
     * @return  true, if the map has changed.
     */
    bool place(float x, float y, TilePointer const & tile);
};


/**
 * An invalid Map.
 */
class InvalidMap final : public Map {

public:

    /**
     * Constructor.
     */
    InvalidMap() : Map{QString::Null{}} {
    }

    /**
     * Checks if this is a valid map.
     *
     * @return  always false.
     */
    bool isValid() const override {
        return false;
    }
};


}
}


#endif
