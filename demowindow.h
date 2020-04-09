#ifndef DEMOWINDOW_H
#define DEMOWINDOW_H

#include <QMainWindow>

#include "QtOSGWidget.h"
#include "demoscene.h"

class DemoWindow : public QMainWindow
{
		Q_OBJECT
	public:
		explicit DemoWindow(QWidget *parent = nullptr);

	protected:
		void setupCamera();

		//A widget that wraps osgViewer::GraphicsWindowEmbedded
		//This constructor will create a view and a camera, setup a camera trackball manipulator
		//	and install a filter to translate Qt mouse events to OSG mouse events to be able
		//	to use the manupulator.
		QtOSGWidget * widget;

		//An OSG scene
		DemoScene scene;
};

#endif // DEMOWINDOW_H
