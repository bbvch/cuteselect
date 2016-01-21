#ifndef CONTEXT_H
#define CONTEXT_H

#include <Configuration.h>

#include <QSharedPointer>
#include <QBuffer>
#include <QtTest/QSignalSpy>

class Context
{
public:
  QBuffer configurationFileContent;
  Configuration configuration;
  QSignalSpy quitSpy{&configuration, SIGNAL(quit(QString))};
};

#endif // CONTEXT_H
