/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */

#include <utility>

#include <rpgmapper/resource.hpp>
#include <rpgmapper/resource_collection.hpp>

using namespace rpgmapper::model;


void ResourceCollection::addResource(QString name, QByteArray const & data) {
    addResource(QSharedPointer<Resource>{new rpgmapper::model::Resource{std::move(name), data}});
}


void ResourceCollection::addResource(QSharedPointer<Resource> resource) {
    if (resource->getData().isEmpty()) {
        throw std::runtime_error("Refused to add empty resource to resource DB.");
    }
    resources[resource->getName()] = resource;
}