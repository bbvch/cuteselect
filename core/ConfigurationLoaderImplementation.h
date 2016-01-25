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
