/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#ifndef RPGMAPPER_MAINWINDOW_HPP
#define RPGMAPPER_MAINWINDOW_HPP


#include <memory>

#include <QFileDialog>
#include <QMainWindow>
#include <QSettings>

#include <rpgmapper/atlas.hpp>
#include "aboutdialog.hpp"
#include "logdialog.hpp"
#include "mappropertiesdialog.hpp"


class Ui_mainwindow;


namespace rpgmapper {
namespace view {


class MainWindow : public QMainWindow {

    Q_OBJECT

    std::shared_ptr<Ui_mainwindow> ui;
    rpgmapper::model::AtlasPointer atlas;

    AboutDialog * aboutDialog = nullptr;
    QFileDialog * loadAtlasDialog = nullptr;
    LogDialog * logDialog = nullptr;
    MapPropertiesDialog * mapPropertiesDialog = nullptr;
    QFileDialog * saveAtlasDialog = nullptr;

    QStringList recentAtlasFileNames;
    QString recentAtlasFolderName;
    int maximumRecentAtlasFiles = 10;
    QList<QAction *> recentFileLoadActions;

public:

    MainWindow();

    rpgmapper::model::AtlasPointer getAtlas();

    rpgmapper::model::AtlasPointer const getAtlas() const;

    void setAtlas(rpgmapper::model::AtlasPointer atlas);

public slots:

    void enableActions();

protected:

    void closeEvent(QCloseEvent * event) override;

    void showEvent(QShowEvent * event) override;

private:

    void addRecentFileName(QString const & fileName);

    void centerWindow();

    void connectActions();

    void clearRecentFileActions();

    void createRecentFileActions();

    void loadAtlas(QString const & fileName);

    void loadSettings();

    void showAboutDialog();

    void saveAtlas(QString const & fileName);

    void saveSettings();

    void saveSettingsRecentFiles(QSettings & settings);

    void saveSettingsWindow(QSettings & settings);

    void setupDialogs();

private slots:

    void clearListOfRecentFiles();

    void load();

    void loadRecentFile();

    void save();

    void saveAs();

};


}
}


#endif







#if 0

class MainWindow : public QMainWindow {

    Q_OBJECT

    class Impl;
    std::shared_ptr<MainWindow::Impl> impl;

public:

    MainWindow();

public slots:

    void editAtlasProperties();

    void editMapProperties();

    void editRegionProperties();

    void deleteMap();

    void deleteRegion();

    void newMap();

    void newRegion();

    void resetAtlas();

    void showCoordinates(int x, int y);

    void visibleMinimap(bool bView);

    void visibleStructure(bool bView);

    void visibleTiles(bool bView);

protected:

    void closeEvent(QCloseEvent * cEvent) override;

    void showEvent(QShowEvent * cEvent) override;

private slots:

    void changedAtlas();

};


}
}


#endif