#ifndef DEMOSUPPORT_H
#define DEMOSUPPORT_H

#include <osg/Geode>

#include "QtOSGWidget.h"

namespace QtOsgDemo
{
	osg::Geode * createScene();
	void setupCameraManipulator(QtOSG::Widget * widget);
	void setupCamera(QtOSG::Widget * widget);
}

#endif // DEMOSUPPORT_H
