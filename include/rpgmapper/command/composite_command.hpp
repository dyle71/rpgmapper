/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018-2019, Oliver Maurhart, dyle71@gmail.com
 */

#ifndef RPGMAPPER_MODEL_COMMAND_COMPOSITE_COMMAND_HPP
#define RPGMAPPER_MODEL_COMMAND_COMPOSITE_COMMAND_HPP

#include <QString>

#include <rpgmapper/command/command.hpp>
#include <rpgmapper/command/commands.hpp>


namespace rpgmapper::model::command {


/**
 * A CompositeCommand is a command which is aggregated by several sub-commands.
 */
class CompositeCommand : public Command {

    /**
     * The list of sub-commands.
     */
    Commands commands;

public:
    
    /**
     * Constructor.
     */
    explicit CompositeCommand() = default;

    /**
     * Destructor.
     */
    ~CompositeCommand() override = default;

    /**
     * Add another command to the list of sub-commands.
     *
     * @param   command     the next sub-command to be executes.
     */
    void addCommand(CommandPointer command);

    /**
     * Returns the number of commnands so far collected.
     *
     * @return  the number of sub-commands.
     */
    unsigned long size() const {
        return commands.size();
    }

    /**
     * Returns a human readable description of this single command.
     *
     * @return  a string describing the command.
     */
    QString getDescription() const override;

    /**
     * Executes all commands.
     */
    void execute() override;

    /**
     * Undoes all commands.
     */
    void undo() override;

protected:

    /**
     * Delete all sub-commands from the list.
     */
    void clearCommands();
};


}


#endif
