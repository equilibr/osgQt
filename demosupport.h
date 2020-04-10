#ifndef DEMOSUPPORT_H
#define DEMOSUPPORT_H

#include <osg/Geode>

#include "osgQtWidget.h"

namespace osgQtDemo
{
	osg::Geode * createScene();
	void setupCameraManipulator(osgQt::Widget * widget);
	void setupCamera(osgQt::Widget * widget);
}

#endif // DEMOSUPPORT_H
