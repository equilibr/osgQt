#include "demowindow.h"

#include <QTimer>

DemoWindow::DemoWindow(QWidget *parent) :
	QMainWindow(parent),
	widget{new QtOSGWidget(this, true)}
{
	//For the demo:
	//There is only a single widget to show
	setCentralWidget(widget);

	//For the demo:
	//Setup the camera so it will be pleasant to look into
	setupCamera();

	//Set the scene the main widget should display.
	//This should be after the camera setup - otherwise the camera manipulator
	//	will reset.
	widget->setSceneData(scene.sceneRoot());

	//By default the rendered OSG view will only be updated when the
	// camera manipulator processes a mouse event or when the widget is resized
}

void DemoWindow::setupCamera()
{
	widget->getCamera()->setClearColor( osg::Vec4( 0.9f, 0.9f, 1.f, 1.f ) );

	//Calculate the projection aspect ration based on the current widget dimentions
	double aspectRatio = widget->width();
	aspectRatio /= widget->height();
	widget->getCamera()->setProjectionMatrixAsPerspective(30, aspectRatio, 1, 1000);

	widget->getViewer()->getCameraManipulator()->setHomePosition(
	{-2,0,1},
	{0,0,0},
	{0,0,1});
}
