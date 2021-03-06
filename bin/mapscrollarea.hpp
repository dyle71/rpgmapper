/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018-2019, Oliver Maurhart, dyle71@gmail.com
 */

#ifndef RPGMAPPER_VIEW_MAPSCROLLAREA_HPP
#define RPGMAPPER_VIEW_MAPSCROLLAREA_HPP

#include <QScrollArea>

#include "mapwidget.hpp"


namespace rpgmapper::view {


/**
 * This scroll area contains a MapWidget and acts as a viewport onto a map.
 */
class MapScrollArea : public QScrollArea {

    Q_OBJECT
    
    QPoint mousePosition;               /**< The position where the user pressed the right mouse on the map. */
    bool mouseButtonDown = false;       /**< The user has pressed the right mouse button. */
    
    float horizontalPositionFactor = 0.5;    /**< Horizontal position factor. */
    float verticalPositionFactor = 0.5;      /**< Vertical position factor. */

public:

    /**
     * Constructor
     * @param   parent          Parent QWidget instance.
     * @param   mapWidget       The map widget contained.
     */
    explicit MapScrollArea(QWidget * parent, MapWidget * mapWidget);
    
    /**
     * Gets the contained map widget rendered.
     *
     * @return  the contained map widget rendering a map.
     */
    MapWidget * getMapWidget() {
        return dynamic_cast<MapWidget *>(widget());
    }

public slots:
    
    /**
     * The map widget has resized itself.
     */
    void mapResized();

protected:
    
    /**
     * Special handling of mouse move events.
     *
     * @param   event       the mouse move event.
     */
    void mouseMoveEvent(QMouseEvent * event) override;
    
    /**
     * The user pressed a mouse button on the map.
     *
     * @param   event       the mouse press event.
     */
    void mousePressEvent(QMouseEvent * event) override;
    
    /**
     * The user release a mouse button on the map.
     *
     * @param   event       the mouse press event.
     */
    void mouseReleaseEvent(QMouseEvent * event) override;
    
    /**
     * Mouse wheel event happend.
     *
     * @param   event       the user triggerd a mouse wheel event.
     */
    void wheelEvent(QWheelEvent * event) override;
    
    
private slots:
    
    /**
     * Adjust horizontal position factor.
     */
    void adjustHorizontalFactor();
    
    /**
     * Adjust vertical position factor.
     */
    void adjustVerticalFactor();

signals:

    /**
     * Requests to decrease the map zoom level.
     */
    void decreaseZoom();
    
    /**
     * Requests to increase the map zoom level.
     */
    void increaseZoom();
};


}


#endif
