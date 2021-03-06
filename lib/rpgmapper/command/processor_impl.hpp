/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018-2019, Oliver Maurhart, dyle71@gmail.com
 */

#ifndef RPGMAPPER_MODEL_COMMAND_PROZESSOR_IMPL_HPP
#define RPGMAPPER_MODEL_COMMAND_PROZESSOR_IMPL_HPP

#include <rpgmapper/command/processor.hpp>


namespace rpgmapper::model::command {


/**
 * This class holds the details of a Processor implementation.
 */
class Processor::Impl final {
    
    /**
     * This is the list of commands executed so far.
     */
    std::list<CommandPointer> history;
    
    /**
     * This is the list of commands we have undone recently.
     */
    std::list<CommandPointer> redoList;
    
    /**
     * This field holds the number of introduced changes to the world.
     */
    int changes = 0;

public:

    /**
     * Executes a single command.
     *
     * @param   command     the command to execute.
     */
    void execute(CommandPointer & command);
    
    /**
     * Returns the history of all commands executed.
     *
     * @return  a list of all commands executed. Oldest first.
     */
    std::list<CommandPointer> const & getHistory() const;

    /**
     * Returns the list of all commands recently undone.
     *
     * @return  the list of all undone commands.
     */
    std::list<CommandPointer> const & getUndone() const;

    /**
     * Tells the number of changes applied to the world.
     *
     * @return  how much change all commands introduces.
     */
    int modifications() const {
        return changes;
    }

    /**
     * Redoes the latest command undone.
     */
    void redo();

    /**
     * Resets the number of changes to 0.
     */
    void resetModifications() {
        changes = 0;
    }

    /**
     * Undoes the latest command executed.
     */
    void undo();

private:

    /**
     * Runs a single command.
     *
     * @param   command     the command to execute.
     */
    void runCommand(CommandPointer & command);
};


}


#endif
