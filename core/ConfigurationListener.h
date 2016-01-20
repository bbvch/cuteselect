#ifndef CONFIGURATIONLISTENER_H
#define CONFIGURATIONLISTENER_H

#include <QString>

class ConfigurationListener
{
public:
  virtual ~ConfigurationListener() = default;

  virtual void setBackgroundColor(QString value) = 0;

};


#endif // CONFIGURATIONLISTENER_H
