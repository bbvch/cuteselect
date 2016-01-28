#
# (C) Copyright 2016
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	GPL-3.0+
#

QT += xml

INCLUDEPATH += $$PWD/

LIBS += -L../core/
LIBS += -lcore

PRE_TARGETDEPS += ../core/libcore.a
