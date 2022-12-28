/*
 * Copyright (C) 2016 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Thomas Voß <thomas.voss@canonical.com>
 *
 */

#include "property_store.h"

#include <QProcess>

std::string util::AndroidPropertyStore::get(const std::string& key) const
{
    QProcess getprop;
    QString exec("/usr/bin/getprop");
    QStringList params;
    params << QString::fromUtf8(key.data());

    getprop.start(exec, params);
    getprop.waitForFinished(); // sets current thread to sleep and waits for pingProcess end
    QString output(getprop.readAllStandardOutput());

    return output.toStdString();
}
