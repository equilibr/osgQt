QT += core gui widgets opengl

TARGET = osgQt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

LIBS += -losg
LIBS += -losgViewer
LIBS += -losgGA

DESTDIR = ../bin


SOURCES += \
	demoscene.cpp \
	demowindow.cpp \
	main.cpp \
	QtOSGWidget.cpp \
	QtOSGMouseHandler.cpp

HEADERS += \
	QtOSGWidget.h \
	QtOSGMouseHandler.h \
	demoscene.h \
	demowindow.h

FORMS +=
