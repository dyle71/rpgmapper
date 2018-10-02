/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#ifndef RPGMAPPER_MODEL_FIELD_HPP
#define RPGMAPPER_MODEL_FIELD_HPP


#include <map>
#include <vector>

#include <QPoint>
#include <QSharedPointer>
#include <QString>


namespace rpgmapper {
namespace model {

/**
 * Forward declaration of the Field class.
 */
class Field;

/**
 * A FieldPointer is a shared pointer to Field heap instances.
 */
using FieldPointer = QSharedPointer<Field>;

/**
 * A single tile on a field holds key-value pairs.
 *
 * A tile may be:
 *  - "river" - "south-west"
 *  - "wall" - "east"
 *  - "special" - "trapdoor"
 */
using Tile = std::map<QString, QString>;

/**
 * Tiles is a list (vector) of Tiles (aka key-value pairs).
 */
using Tiles = std::vector<Tile>;

/**
 * A Field class has a position and a list of tiles placed on it.
 */
class Field {

    QPoint position;            /**< The fields position. */
    Tiles tiles;                /**< All the tiles placed on the field. */

public:

    /**
     * Create a Field instance at the given position.
     *
     * @param   x   X coordinate.
     * @param   y   Y coordinate.
     */
    explicit Field(int x = 0, int y = 0);

    /**
     * Create a field at the given position.
     *
     * @param   position    Position of the field.
     */
    explicit Field(QPoint const & position);

    /**
     * Returns a single integer identifying the field.
     *
     * @return  an integer while uniquely identifies the field o(n a single map).
     */
    int getIndex() const {
        return getIndex(position);
    }

    /**
     * Converts a position to an integer index value.
     *
     * @param   x       X coordinate.
     * @param   y       Y coordinate.
     * @return  a unique integer to identify the field with a single value (on a single map).
     */
    static int getIndex(int x, int y);

    /**
     * Converts a position to an integer index value.
     *
     * @param   point       Position of the field on a map.
     * @return  the index integer value of the field on the map.
     */
    static int getIndex(QPoint const & point) {
        return getIndex(point.x(), point.y());
    }

    /**
     * Returns true if this is a valid Field.
     *
     * @return  true, for valid fields.
     */
    virtual bool isValid() const {
        return true;
    }

    /**
     * Returns the invalid null Field ("Null object pattern")
     *
     * @return  the invalid null Field.
     */
    static Field const & nullField();
};


/**
 * This class represents the invalid null field ("Null object pattern").
 */
class InvalidField final : public Field {

public:

    /**
     * Constructs an invalid Field.
     */
    InvalidField() : Field(0, 0) {}

    /**
     * The invalid field always return false for isValid().
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
