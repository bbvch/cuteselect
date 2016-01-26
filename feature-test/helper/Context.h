#ifndef CONTEXT_H
#define CONTEXT_H

#include <Configuration.h>
#include <ItemListImplementation.h>

#include <QSharedPointer>
#include <QBuffer>
#include <QtTest/QSignalSpy>

class Context
{
public:
  QBuffer configurationFileContent;
  QString configurationFilePath{""};
  Configuration configuration{new ItemListImplementation()};
  QSignalSpy quitSpy{&configuration, SIGNAL(quit(QString))};
};

#endif // CONTEXT_H
