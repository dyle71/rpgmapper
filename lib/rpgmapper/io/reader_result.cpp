/*
 * This file is part of rpgmapper.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */

#include <utility>

#include <rpgmapper/io/reader_result.hpp>

using namespace rpgmapper::model::io;


ReaderResult::ReaderResult(QSharedPointer<rpgmapper::model::Atlas> & atlas, bool success, QStringList log)
        : Result{success, std::move(log)}, atlas{atlas} {
}
