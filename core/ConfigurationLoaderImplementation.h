#ifndef CONFIGURATIONLOADERIMPLEMENTATION_H
#define CONFIGURATIONLOADERIMPLEMENTATION_H

#include "ConfigurationLoader.h"
#include "ConfigurationListener.h"

#include <QIODevice>
#include <QSharedPointer>

class ConfigurationLoaderImplementation :
    public ConfigurationLoader
{
public:
  ConfigurationLoaderImplementation(ConfigurationListener &listener);

  void load(QIODevice *data) const override;

private:
  ConfigurationListener &listener;

};

#endif // CONFIGURATIONLOADER_H
