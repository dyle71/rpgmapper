/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018-2019, Oliver Maurhart, dyle71@gmail.com
 */

#ifndef RPGMAPPER_MODEL_COMMAND_SET_MAP_ORIGINHPP
#define RPGMAPPER_MODEL_COMMAND_SET_MAP_ORIGINHPP

#include <QString>

#include <rpgmapper/command/command.hpp>
#include <rpgmapper/coordinate_system.hpp>
#include <rpgmapper/map_pointer.hpp>


// fwd
namespace rpgmapper::model { class Map; }


namespace rpgmapper::model::command {


/**
 * This command lets the maps origin move around.
 */
class SetMapOrigin : public Command {
    
    rpgmapper::model::Map * map = nullptr;        /**< the map to modify. */
    CoordinatesOrigin newOrigin;                  /**< the new origin of the map. */
    CoordinatesOrigin oldOrigin;                  /**< the maps old origin. */

public:
    
    /**
     * Constructor.
     *
     * @param   map             the map to modify.
     * @param   origin          the new origin of the map.
     */
    SetMapOrigin(rpgmapper::model::Map * map, rpgmapper::model::CoordinatesOrigin origin);
    
    /**
     * Constructor.
     *
     * @param   map             the map to modify.
     * @param   origin          the new origin of the map.
     */
    SetMapOrigin(rpgmapper::model::MapPointer map, rpgmapper::model::CoordinatesOrigin origin)
        : SetMapOrigin{map.data(), origin} {}
    
    /**
     * Destructor.
     */
    ~SetMapOrigin() override = default;
    
    /**
     * Executes this command.
     */
    void execute() override;
    
    /**
     * Returns a human readable string for this command.
     *
     * @return  a string describing this command.
     */
    QString getDescription() const override;
    
    /**
     * Undoes the command.
     */
    void undo() override;
};


}


#endif
