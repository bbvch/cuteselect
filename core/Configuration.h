#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QString>

class Configuration
{
public:
  virtual ~Configuration() = default;

  virtual QString backgroundColor() const = 0;

};

#endif // CONFIGURATION_H
