/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

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
