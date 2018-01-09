/*
 * mainwindow.cpp
 *
 * Copyright (C) 2015-2018 Oliver Maurhart, <dyle71@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


// ------------------------------------------------------------
// incs

// Qt
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QSettings>

// rpgmapper
#include <rpgmapper/common_macros.h>

#include "mainwindow.hpp"

#include "ui_mainwindow.h"


using namespace rpgmapper::view;


// ------------------------------------------------------------
// code


/**
 * ctor
 */
MainWindow::MainWindow() : QMainWindow() {

    ui = new Ui_mainwindow;
    ui->setupUi(this);
    statusBar()->setSizeGripEnabled(true);

    loadSettings();
}


/**
 * dtor
 */
MainWindow::~MainWindow() {
    delete ui;
}


/**
 * centers the window on the desktop with default width and height
 */
void MainWindow::centerWindow() {

    const int nDefaultWidth = 600;
    const int nDefaultHeight = 400;

    QDesktopWidget * cDesktop = qApp->desktop();
    int nX = (cDesktop->width() - nDefaultWidth) / 2;
    int nY = (cDesktop->height() - nDefaultHeight) / 2;

    resize(QSize(nDefaultWidth, nDefaultHeight));
    move(QPoint(nX, nY));
}


/**
 * handle close event
 *
 * @param   cEvent      the event passed
 */
void MainWindow::closeEvent(QCloseEvent* cEvent) {
    QSettings cSettings("rpgmapper", "rpgmapper");
    cSettings.setValue("geometry", saveGeometry());
    cSettings.setValue("windowState", saveState());
    QMainWindow::closeEvent(cEvent);
}


/**
 * load the settings
 */
void MainWindow::loadSettings() {
    QSettings cSettings("rpgmapper", "rpgmapper");
    if (cSettings.contains("geometry")) {
        restoreGeometry(cSettings.value("geometry").toByteArray());
    }
    else {
        centerWindow();
    }
    restoreState(cSettings.value("windowState").toByteArray());
}
