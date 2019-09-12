#include "QtOSGWidget.h"

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

void QtOSGWidget::resizeGL(int w, int h)
{
	const int _x = x();
	const int _y = y();

	graphicsWindow.get()->getEventQueue()->windowResize(_x, _y, w, h);
	graphicsWindow.get()->resized(_x, _y, w, h);
	viewer.get()->getCamera()->setViewport(0, 0, w, h);
}

void QtOSGWidget::paintGL()
{
	viewer.get()->frame();
}
