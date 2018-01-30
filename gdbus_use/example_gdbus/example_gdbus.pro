TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Building.c \
    dbusServer.c \
#    dbusClient.c

HEADERS += \
    Building.h \
    dbusServer.h \
#    dbusClient.h

OTHER_FILES += \
    Building.xml


INCLUDEPATH += \
    /usr/include/glib-2.0 \
    /usr/lib/x86_64-linux-gnu/glib-2.0/include \
    /usr/include/gio-unix-2.0

LIBS += \
    -lgio-2.0    \
    -lgmodule-2.0   \
    -lgthread-2.0   \
    -lrt    \
    -lpthread   \
    -lgobject-2.0   \
    -lglib-2.0 \

