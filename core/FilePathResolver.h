#ifndef FILEPATHRESOLVER_H
#define FILEPATHRESOLVER_H

#include <QString>

class FilePathResolver
{
public:
  virtual ~FilePathResolver() = default;

  virtual QString resolve(QString path) const = 0;

};


#endif
