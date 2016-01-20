#ifndef CONFIGURATIONLISTENER_MOCK_H
#define CONFIGURATIONLISTENER_MOCK_H

#include <ConfigurationListener.h>

#include <gmock/gmock.h>

class ConfigurationListener_Mock :
    public ConfigurationListener
{
public:
  MOCK_METHOD1(setBackgroundColor, void(QString));

};

#endif // CONFIGURATIONLISTENER_MOCK_H
