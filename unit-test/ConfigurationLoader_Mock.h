#ifndef CONFIGURATIONLOADER_MOCK_H
#define CONFIGURATIONLOADER_MOCK_H

#include <ConfigurationLoader.h>

#include <gmock/gmock.h>

class ConfigurationLoader_Mock :
    public ConfigurationLoader
{
public:
  MOCK_CONST_METHOD1(load, QSharedPointer<Configuration>(QIODevice *data));

};

#endif // CONFIGURATIONLOADER_MOCK_H
