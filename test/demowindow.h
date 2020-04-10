#ifndef DEMOWINDOW_H
#define DEMOWINDOW_H

#include <QMainWindow>

#include "../src/osgQtWidget.h"
#include "demosupport.h"

class DemoWindow : public QMainWindow
{
		Q_OBJECT
	public:
		explicit DemoWindow(QWidget *parent = nullptr);

	protected:
		//A widget that wraps osgViewer::GraphicsWindowEmbedded
		//This constructor will create a view and a camera, setup a camera trackball manipulator
		//	and install a filter to translate Qt mouse events to OSG mouse events to be able
		//	to use the manupulator.
		osgQt::Widget * widget;
};

#endif // DEMOWINDOW_H
