/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */

#include <QGridLayout>

#include "recentcolorswidget.hpp"

using namespace rpgmapper::view;


RecentColorsWidget::RecentColorsWidget(QWidget * parent) : QWidget{parent} {
    
    auto layout = new QGridLayout{this};
    layout->setMargin(0);
    layout->setSpacing(0);
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 8; ++j) {
            auto index = i * 8 + j;
            colorWidgets[index] = new ColorWidget{Qt::white, index, this};
            connect(colorWidgets[index], &ColorWidget::selectedChanged, this, &RecentColorsWidget::colorSelectedChange);
            layout->addWidget(colorWidgets[index], i, j);
        }
    }
}


void RecentColorsWidget::colorSelectedChange(int id, bool selected) {
    
    if ((id < 0) || (id >= 2 * 8)) {
        return;
    }
    
    if ((selectedIndex != id) && selected && (selectedIndex != -1)) {
        colorWidgets[selectedIndex]->setSelected(false);
    }
    
    if (selected) {
        selectedIndex = id;
    }
}

