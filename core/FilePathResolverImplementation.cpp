/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

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
