#ifndef CONFIGURATIONLOADER_H
#define CONFIGURATIONLOADER_H

#include "Configuration.h"

#include <QSharedPointer>
#include <QIODevice>

class ConfigurationLoader
{
public:
  virtual ~ConfigurationLoader() = default;
  virtual QSharedPointer<Configuration> load(QIODevice *data) const = 0;

};

#endif // CONFIGURATIONLOADER_H
