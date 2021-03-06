/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018-2019, Oliver Maurhart, dyle71@gmail.com
 */

#ifndef RPGMAPPER_VIEW_RESOURCEVIEWDIALOG_HPP
#define RPGMAPPER_VIEW_RESOURCEVIEWDIALOG_HPP

#include <memory>

#include <QDialog>
#include <QFileDialog>
#include <QIcon>
#include <QTreeWidgetItem>

#include <rpgmapper/resource/resource_collection_pointer.hpp>
#include <rpgmapper/resource/resource_pointer.hpp>
#include <rpgmapper/resource/resource_type.hpp>


// fwd
class Ui_resourcesViewDialog;


namespace rpgmapper::view {


/**
* This dialog shows all the current resources.
*/
class ResourcesViewDialog : public QDialog {

    Q_OBJECT
    
    std::shared_ptr<Ui_resourcesViewDialog> ui;            /**< The User Interface as created by the uic. */
    
    QTreeWidgetItem * localResourcesRootNode = nullptr;    /**< Tree node for the local resources */
    QTreeWidgetItem * userResourcesRootNode = nullptr;     /**< Tree node for the user resources */
    QTreeWidgetItem * systemResourcesRootNode = nullptr;   /**< Tree node for the system resources */
    
    unsigned int updateCounter = 0;                        /**< Current update run. */
    
    QFileDialog * saveDialog = nullptr;                    /**< Save color palette dialog. */
    
    QString lastFolderUsed;                                /**< Last folder of save operation. */

public:
    
    /**
     * Constructor.
     *
     * @param   parent      Parent QWidget instance.
     */
    explicit ResourcesViewDialog(QWidget * parent);
    
    /**
     * Returns the last folder selected by the user for a save operation.
     *
     * @return  the last folder selected by the user.
     */
    QString getLastUsedFolder() const {
        return lastFolderUsed;
    }

public slots:
    
    /**
     * Sets the last folder for save resource operations.
     *
     * @param   folder      the folder to select on resource save.
     */
    void setLastFolderUsed(QString folder);
    
    /**
     * Reinit view of used resources.
     */
    void updateResourcesView();

protected:
    
    /**
     * The dialog received a show event.
     *
     * @param   event       the show event involved.
     */
    void showEvent(QShowEvent * event) override;
    
private:
    
    /**
     * Removes all resource items in the view with an update counter been too less.
     *
     * @param   node            node to start.
     */
    void dropResources(QTreeWidgetItem * node = nullptr);
    
    /**
     * Retrieves the icon for a resource type.
     *
     * @param   type        the resource type.
     * @return  the icon for this resource type.
     */
    QIcon getIconForResourceType(rpgmapper::model::resource::ResourceType type) const;
    
    /**
     * Returns the category node under the root node (and create one if not existing).
     *
     * @param   rootNode        the root node under which to create the category.
     * @param   type            the resource type (== category).
     * @return  a tree widget item holding the category node.
     */
    QTreeWidgetItem * ensureCategoryNode(QTreeWidgetItem * rootNode, rpgmapper::model::resource::ResourceType type);
    
    /**
     * Searches a path under a root node tree widget item.
     *
     * @param   rootNode            the root node item to search underneath.
     * @param   path                the resource path to search.
     * @return  the tree widget item, or nullptr if not found.
     */
    QTreeWidgetItem * findResource(QTreeWidgetItem * rootNode, QString path) const;
    
    /**
     * Checks if the node has been updated just recently.
     *
     * @param   node        the item in the view to check.
     * @return  true, if the node has just been update.
     */
    bool isUpdated(QTreeWidgetItem * node) const;

    /**
     * Inserts and/or updates a single resource under the given root node.
     *
     * @param   rootNode        the root node under which the resource is/should be located.
     * @param   resource        the resource.
     */
    void insertResource(QTreeWidgetItem * rootNode, rpgmapper::model::resource::ResourcePointer const & resource);
    
    /**
     * Inserts and/or updates all resources of a resource collection.
     *
     * @param   rootNode        the root node to insert the resources under.
     * @param   resources       the resources to add.
     */
    void insertResources(QTreeWidgetItem * rootNode,
            rpgmapper::model::resource::ResourceCollectionPointer const & resources);

private slots:
    
    /**
     * The user selected an item.
     */
    void currentItemChanged();
    
    /**
     * Saves the current resource.
     */
    void saveCurrentResource();
};


}


#endif
