/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#ifndef CONFIGURATIONLOADERIMPLEMENTATION_H
#define CONFIGURATIONLOADERIMPLEMENTATION_H

#include "ConfigurationLoader.h"
#include "ConfigurationListener.h"
#include "FilePathResolver.h"

#include <QIODevice>
#include <QSharedPointer>

class ConfigurationLoaderImplementation :
    public ConfigurationLoader
{
public:
  ConfigurationLoaderImplementation(ConfigurationListener &listener, const FilePathResolver &pathResolver);

  void load(QIODevice *data) const override;

private:
  ConfigurationListener &listener;
  const FilePathResolver &pathResolver;

};

#endif // CONFIGURATIONLOADER_H
