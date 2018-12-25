/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */

#include <rpgmapper/layer/layer_stack.hpp>
#include <rpgmapper/resource/resource_db.hpp>

#include "shape_tile.hpp"

using namespace rpgmapper::model::layer;
using namespace rpgmapper::model::resource;
using namespace rpgmapper::model::tile;

#if defined(__GNUC__) || defined(__GNUCPP__)
#   define UNUSED   __attribute__((unused))
#else
#   define UNUSED
#endif


ShapeTile::ShapeTile() : Tile() {
    getAttributes()["type"] = "shape";
}


ShapeTile::ShapeTile(Tile::Attributes & attributes) : Tile{attributes} {
    getAttributes()["type"] = "shape";
}


bool ShapeTile::operator==(const Tile & rhs) const {
    return getAttributes() == rhs.getAttributes();
}


void ShapeTile::draw(QPainter & painter, int tileSize) {
    QRect rect{0, 0, tileSize, tileSize};
}


QString ShapeTile::getPath() const {
    
    auto const & attributes = getAttributes();
    
    auto pair = attributes.find("path");
    if (pair == attributes.end()) {
        return QString::null;
    }
    
    return (*pair).second;
}


rpgmapper::model::resource::ResourcePointer ShapeTile::getShape() const {
    
    auto path = getPath();
    if (path.isEmpty()) {
        return ResourcePointer{};
    }
    return ResourceDB::getResource(path);
}


bool ShapeTile::isPlaceable(float x, float y, rpgmapper::model::layer::LayerStack const * layerStack) const {
    
    if (!layerStack) {
        return false;
    }
    return true;
}


bool ShapeTile::place(float x, float y, LayerStack * layerStack) {
    
    if (!isPlaceable(x, y, layerStack)) {
        throw std::runtime_error{"Tile is not placeable on this position on the given layer stack."};
    }
    return true;
}