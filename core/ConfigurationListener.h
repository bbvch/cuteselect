#ifndef CONFIGURATIONLISTENER_H
#define CONFIGURATIONLISTENER_H

#include "ImageItem.h"

#include <QString>

class ConfigurationListener
{
public:
  virtual ~ConfigurationListener() = default;

  virtual void setBackgroundColor(QString value) = 0;
  virtual void setRelativeWidth(double value) = 0;
  virtual void setRelativeHeight(double value) = 0;
  virtual void addImage(ImageItem *item) = 0;

};


#endif // CONFIGURATIONLISTENER_H
