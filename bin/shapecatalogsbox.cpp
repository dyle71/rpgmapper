/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018-2019, Oliver Maurhart, dyle71@gmail.com
 */

#include <rpgmapper/resource/resource_db.hpp>
#include <rpgmapper/resource/resource_type.hpp>

#include "shapecatalogsbox.hpp"
#include "shapecatalogwidget.hpp"

using namespace rpgmapper::model::resource;
using namespace rpgmapper::view;


ShapeCatalogsBox::ShapeCatalogsBox(QWidget * parent) : QToolBox{parent} {
}


void ShapeCatalogsBox::addCatalog(rpgmapper::model::resource::ShapeCatalog const * catalog) {
    
    if (!catalog) {
        return;
    }
    
    auto shapeCatalogWidget = new ShapeCatalogWidget{this};
    shapeCatalogWidget->setCatalog(catalog->getPath());
    addItem(shapeCatalogWidget, catalog->getName());
    
    connect(shapeCatalogWidget, SIGNAL(shapeSelected(QString)), this, SIGNAL(shapeSelected(QString)));
}


void ShapeCatalogsBox::applyResources() {

    clear();
    
    auto shapePaths = ResourceDB::getResources(getResourcePrefixForType(ResourceType::shape));
    for (auto const & shapePath : shapePaths) {
        
        auto shape = ResourceDB::getResource(shapePath);
        auto const catalog = dynamic_cast<ShapeCatalog const *>(shape.data());
        addCatalog(catalog);
    }
}


void ShapeCatalogsBox::clear() {
    
    while (count()) {
        delete widget(0);
    }
}
