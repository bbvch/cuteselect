#ifndef CONFIGURATIONLISTENER_H
#define CONFIGURATIONLISTENER_H

#include <QString>

class ConfigurationListener
{
public:
  virtual ~ConfigurationListener() = default;

  virtual void setBackgroundColor(QString value) = 0;
  virtual void addImage(QString filename) = 0;

};


#endif // CONFIGURATIONLISTENER_H
