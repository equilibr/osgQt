#include "QtOSGWidget.h"
#include "QtOSGMouseHandler.h"

#include <osgGA/TrackballManipulator>

QtOSGWidget::QtOSGWidget(
		osgViewer::Viewer * viewer,
		osg::Camera * camera,
		QWidget * parent)
	:
	QOpenGLWidget(parent),
	viewer(viewer),
	graphicsWindow(
		viewer->setUpViewerAsEmbeddedInWindow(
			x(),
			y(),
			width(),
			height()))

{
	viewer->setCamera(camera);
	camera->setGraphicsContext( graphicsWindow.get() );
}

void QtOSGWidget::setupDefaultCameraManipulator()
{
	//Setup a camera manupulator
	osgGA::TrackballManipulator* manipulator = new osgGA::TrackballManipulator;
	manipulator->setAllowThrow( false );
	viewer->setCameraManipulator(manipulator);

	//Setup a mouse handler for the camera manupulator
	new QtOSGMouseHandler(this);
}

void QtOSGWidget::resizeGL(int w, int h)
{
	const int _x = x();
	const int _y = y();

	graphicsWindow->getEventQueue()->windowResize(_x, _y, w, h);
	graphicsWindow->resized(_x, _y, w, h);
	viewer->getCamera()->setViewport(0, 0, w, h);
}

void QtOSGWidget::paintGL()
{
	viewer->frame();
}
