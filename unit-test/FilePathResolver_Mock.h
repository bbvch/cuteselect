#ifndef FILEPATHRESOLVER_MOCK_H
#define FILEPATHRESOLVER_MOCK_H

#include <FilePathResolver.h>

#include <gmock/gmock.h>

class FilePathResolver_Mock :
    public FilePathResolver
{
public:
  MOCK_CONST_METHOD1(resolve, QString(QString path));

};

#endif // FILEPATHRESOLVER_MOCK_H
