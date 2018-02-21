/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#ifndef RPGMAPPER_MODEL_COMMAND_REMOVE_MAP_HPP
#define RPGMAPPER_MODEL_COMMAND_REMOVE_MAP_HPP

#include <rpgmapper/command/atlas_command.hpp>


namespace rpgmapper {
namespace model {
namespace command {


class RemoveMap : public AtlasCommand {

    QString mapName;
    QString regionName;

public:

    RemoveMap(AtlasPointer & atlas, QString const & regionName, QString const & mapName);

    ~RemoveMap() override = default;

    void execute() override;

    QString getDescription() const override;

    void undo() override;
};


}
}
}


#endif
