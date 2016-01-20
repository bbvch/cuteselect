#include "ApplicationFactory.h"

#include "ApplicationImplementation.h"

ApplicationFactory::ApplicationFactory(const ConfigurationLoader &aConfigurationLoader) :
  configurationLoader{aConfigurationLoader}
{
}

QSharedPointer<Application> ApplicationFactory::produce(QIODevice *data)
{
  const auto config = configurationLoader.load(data);
  return QSharedPointer<Application>(new ApplicationImplementation(*config));
}
