/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#ifndef RPGMAPPER_MODEL_LAYER_TEXT_LAYER_HPP
#define RPGMAPPER_MODEL_LAYER_TEXT_LAYER_HPP


#include <rpgmapper/layer/layer.hpp>


namespace rpgmapper {
namespace model {


class TextLayer;
using TextLayerPointer = QSharedPointer<TextLayer>;

class TextLayer : public Layer {

Q_OBJECT

public:

    explicit TextLayer(rpgmapper::model::Map * map, QObject * parent = nullptr);

    ~TextLayer() override = default;

    void draw(QPainter & painter, int tileSize) const override;

    QJsonObject getJsonObject() const override;
};



}
}


#endif
