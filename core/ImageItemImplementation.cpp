/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#include "ImageItemImplementation.h"

ImageItemImplementation::ImageItemImplementation(const ImageItemImplementation &original) :
  _path{original._path},
  _label{original._label},
  _value{original._value}
{
}

ImageItemImplementation::ImageItemImplementation(QString path, QString label, QString value) :
  _path{path},
  _label{label},
  _value{value}
{
}

QString ImageItemImplementation::path() const
{
  return _path;
}

QString ImageItemImplementation::label() const
{
  return _label;
}

QString ImageItemImplementation::value() const
{
  return _value;
}
