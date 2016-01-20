#ifndef CONFIGURATION_MOCK_H
#define CONFIGURATION_MOCK_H

#include <Configuration.h>

#include <gmock/gmock.h>

class Configuration_Mock :
    public Configuration
{
public:
  MOCK_CONST_METHOD0(backgroundColor, QString());

};

#endif // CONFIGURATION_MOCK_H
