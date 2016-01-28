#
# (C) Copyright 2016
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	GPL-3.0+
#

TEMPLATE = subdirs

SUBDIRS = \
  core \
  feature-test \
  application \
    unit-test

OTHER_FILES += \
    COPYING \
    README.md
