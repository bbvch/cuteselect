#ifndef FILEPATHRESOLVERIMPLEMENTATION_H
#define FILEPATHRESOLVERIMPLEMENTATION_H

#include "FilePathResolver.h"

#include <QString>
#include <QDir>

class FilePathResolverImplementation :
    public FilePathResolver
{
public:
  FilePathResolverImplementation();

  void setBase(QString value);
  QString resolve(QString path) const override;

private:
  QDir base{""};

};

#endif
