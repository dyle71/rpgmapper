/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#include "mapscrollarea.hpp"

using namespace rpgmapper::view;


MapScrollArea::MapScrollArea(QWidget * parent, MapWidget * mapWidget) : QScrollArea{parent} {
    setBackgroundRole(QPalette::Dark);
    setWidget(mapWidget);
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    mapWidget->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}