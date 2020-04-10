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
	src/osgQtKeyboardMapper.cpp \
	src/osgQtMouseMapper.cpp \
	src/osgQtWidget.cpp \
	test/demosupport.cpp \
	test/demowindow.cpp \
	test/main.cpp

HEADERS += \
	src/osgQtKeyboardMapper.h \
	src/osgQtMouseMapper.h \
	src/osgQtWidget.h \
	test/demosupport.h \
	test/demowindow.h

FORMS +=
