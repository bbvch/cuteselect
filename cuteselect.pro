#
# (C) Copyright 2016
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	GPL-3.0+
#

TEMPLATE = subdirs

SUBDIRS = \
  core \
  application

CONFIG(debug, debug|release) {
  SUBDIRS += \
    feature-test \
    unit-test
}

application.depends = \
  core

feature-test.depends = \
  core

unit-test.depends = \
  core

OTHER_FILES += \
    COPYING \
    README.md
