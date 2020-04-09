#include "demowindow.h"

#include "QtOSGMouseMapper.h"

DemoWindow::DemoWindow(QWidget *parent) :
	QMainWindow(parent),
	widget{new QtOSG::Widget(this)}
{
	//There is only a single widget to show - the OSG widget
	setCentralWidget(widget);

	//For the demo:
	//Setup the camera so it will be pleasant to look into
	QtOsgDemo::setupCamera(widget);

	//For the demo:
	//Setup a camera manipulator.
	//Since the manipulator reacts on mouse events the mouse handler should be installed.
	QtOsgDemo::setupCameraManipulator(widget);

	//Setup a mouse mapper that translates Qt mouse events to OSG mouse events.
	//This handler is a simple event translator and can be used whenever the OSG view
	//	should react to mouse events.
	new QtOSG::MouseMapper(widget);

	//Set the scene the main widget should display.
	//This should be after the camera setup - otherwise the camera manipulator
	//	will reset.
	widget->setSceneData(QtOsgDemo::createScene());

	//By default the rendered OSG view will only be updated when the widget is resized.
	//If a mouse handler is installed the view will also be updated when a mouse event is recieved
}
