/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#ifndef RPGMAPPER_MODEL_ATLAS_HPP
#define RPGMAPPER_MODEL_ATLAS_HPP


#include <memory>
#include <set>

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QSharedPointer>

#include <rpgmapper/region.hpp>


namespace rpgmapper {
namespace model {

class Atlas : public QObject {

    Q_OBJECT

    class Impl;
    std::shared_ptr<Impl> impl;

public:

    explicit Atlas(QObject * parent = nullptr);

    bool applyJsonObject(QJsonObject json);

    RegionPointer createRegion(QString const & name);

    std::set<QString> getAllMapNames() const;

    std::set<QString> getAllRegionNames() const;

    QJsonObject getJsonObject() const;

    QString const & getName() const;

    RegionPointer const & getRegion(QString const & name) const;

    Regions const & getRegions() const;

    bool hasChanged() const;

    virtual bool isValid() const { return true; }

    void removeRegion(QString const & name);

    void resetChanged();

    void setName(QString const & name);

signals:

    void changed();

    void regionCreated(QString name);

    void regionRemoved(QString name);

};

class InvalidAtlas final : public Atlas {
public:
    InvalidAtlas() : Atlas{nullptr} {}
    bool isValid() const override { return false; }
};

using AtlasPointer = QSharedPointer<Atlas>;


}
}


#endif







#if 0









/*
    Map createMap();

    Region createRegion();

    Map & getCurrentMap();

    Region & getCurrentRegion();

    Map const & getMap(rpgmapper::model::mapid_t mapId) const;

    Maps const & getMaps() const;

    Region const & getRegion(rpgmapper::model::regionid_t regionId) const;

    Regions const & getRegions() const;

    void load(QJsonObject const & json) override;

    bool isModified() const override;

    QString toJson(QJsonDocument::JsonFormat format = QJsonDocument::Indented) const;

    void save(QJsonObject & json) const override;

    void setModified(bool modified) override;
*/
public slots:

/*
    void deleteMap(rpgmapper::model::mapid_t mapId);

    void deleteRegion(rpgmapper::model::regionid_t regionId);

    void setCurrentMap(rpgmapper::model::mapid_t mapId);

    void setCurrentRegion(rpgmapper::model::regionid_t regionId);
*/
private slots:

/*
    void changedMapName();

    void changedRegionName();
*/
/*
    void createdMap(rpgmapper::model::mapid_t mapId);

    void createdRegion(rpgmapper::model::regionid_t regionId);

    void deletedMap(rpgmapper::model::mapid_t mapId);

    void deletedRegion(rpgmapper::model::regionid_t regionId);

    void selectedMap(rpgmapper::model::mapid_t mapId);

    void selectedRegion(rpgmapper::model::regionid_t regionId);
*/
private:
/*
    void clear();

    void init();
*/
};

#endif

