/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#ifndef CONFIGURATIONLOADER_H
#define CONFIGURATIONLOADER_H

#include <QSharedPointer>
#include <QIODevice>

class ConfigurationLoader
{
public:
  virtual ~ConfigurationLoader() = default;
  virtual void load(QIODevice *data) const = 0;

};

#endif // CONFIGURATIONLOADER_H
