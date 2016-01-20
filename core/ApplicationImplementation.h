#ifndef APPLICATIONIMPLEMENTATION_H
#define APPLICATIONIMPLEMENTATION_H

#include "Application.h"

class ApplicationImplementation :
    public Application
{
  Q_OBJECT

  Q_PROPERTY(QString backgroundColor MEMBER backgroundColor CONSTANT)

public:
  ApplicationImplementation(const Configuration &configuration);

private:
  const QString backgroundColor;

};

#endif // APPLICATIONIMPLEMENTATION_H
