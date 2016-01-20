#ifndef APPLICATIONFACTORY_H
#define APPLICATIONFACTORY_H

#include "Application.h"
#include "ConfigurationLoader.h"

#include <QSharedPointer>
#include <QIODevice>

class ApplicationFactory
{
public:
  ApplicationFactory(const ConfigurationLoader &configurationLoader);

  QSharedPointer<Application> produce(QIODevice *data);

private:
  const ConfigurationLoader &configurationLoader;

};

#endif // APPLICATIONFACTORY_H
