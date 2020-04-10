#include "osgQtWidget.h"

using namespace osgQt;

Widget::Widget(
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
	setMainCamera(camera);
}

void Widget::setMainCamera(osg::Camera *camera)
{
	if (camera == nullptr)
		return;

	viewer->setCamera(camera);
	camera->setGraphicsContext( graphicsWindow.get() );
}

void Widget::resizeGL(int w, int h)
{
	//A sanity check
	if (viewer->getCamera() == nullptr)
		return;

	const int _x = x();
	const int _y = y();

	graphicsWindow->getEventQueue()->windowResize(_x, _y, w, h);
	graphicsWindow->resized(_x, _y, w, h);
	viewer->getCamera()->setViewport(0, 0, w, h);
}

void Widget::paintGL()
{
	viewer->frame();
}
