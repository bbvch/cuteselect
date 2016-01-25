#include "FilePathResolverImplementation.h"

FilePathResolverImplementation::FilePathResolverImplementation()
{
}

void FilePathResolverImplementation::setBase(QString value)
{
  base = value;
}

QString FilePathResolverImplementation::resolve(QString path) const
{
  return base.absoluteFilePath(path);
}
