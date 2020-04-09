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
	QtOSGMouseMapper.cpp \
	demosupport.cpp \
	demowindow.cpp \
	main.cpp \
	QtOSGWidget.cpp

HEADERS += \
	QtOSGMouseMapper.h \
	QtOSGWidget.h \
	demosupport.h \
	demowindow.h

FORMS +=
