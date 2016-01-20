#ifndef CONFIGURATIONLOADERIMPLEMENTATION_H
#define CONFIGURATIONLOADERIMPLEMENTATION_H

#include "ConfigurationLoader.h"
#include "Configuration.h"

#include <QIODevice>
#include <QSharedPointer>

class ConfigurationLoaderImplementation :
    public ConfigurationLoader
{
public:
  QSharedPointer<Configuration> load(QIODevice *data) const override;

};

#endif // CONFIGURATIONLOADER_H
