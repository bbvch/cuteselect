#ifndef CONTEXT_H
#define CONTEXT_H

#include <Application.h>

#include <QSharedPointer>
#include <QBuffer>

class Context
{
public:
  QBuffer configurationFileContent;
  QSharedPointer<Application> application;
};

#endif // CONTEXT_H
