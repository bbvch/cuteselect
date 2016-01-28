/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

#ifndef CONFIGURATIONLISTENER_MOCK_H
#define CONFIGURATIONLISTENER_MOCK_H

#include <ConfigurationListener.h>

#include <gmock/gmock.h>

class ConfigurationListener_Mock :
    public ConfigurationListener
{
public:
  MOCK_METHOD1(setBackgroundColor, void(QString));
  MOCK_METHOD1(setRelativeWidth, void(double));
  MOCK_METHOD1(setRelativeHeight, void(double));
  MOCK_METHOD1(addImage, void(ImageItem*));

};

#endif // CONFIGURATIONLISTENER_MOCK_H
