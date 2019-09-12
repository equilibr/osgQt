QT += core gui widgets opengl

TARGET = osgQt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

win: {
#Change this to point to where osg is installed
INCLUDEPATH += /include/
LIBS += -L./libs/
}

LIBS += -losg
LIBS += -losgViewer
LIBS += -losgGA
LIBS += -losgWidget

DESTDIR = ../bin


SOURCES += \
	main.cpp \
	QtOSGWidget.cpp \
	QtOSGMouseHandler.cpp

HEADERS += \
	QtOSGWidget.h \
	QtOSGMouseHandler.h

FORMS +=
