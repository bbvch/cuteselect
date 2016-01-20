#ifndef CONTEXT_H
#define CONTEXT_H

#include <Configuration.h>

#include <QSharedPointer>
#include <QBuffer>

class Context
{
public:
  QBuffer configurationFileContent;
  Configuration application;
};

#endif // CONTEXT_H
