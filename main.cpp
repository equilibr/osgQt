#include <QApplication>
#include <QMainWindow>

#include <osg/ShapeDrawable>
#include <osg/StateSet>
#include <osg/Material>

#include "QtOSGWidget.h"


osg::Geode * setupScene()
{
	//Create a simple scene with a pretty cylinder

	osg::Geode * root = new osg::Geode;

	osg::Cylinder* cylinder    = new osg::Cylinder( osg::Vec3( 0.f, 0.f, 0.f ), 0.25f, 0.5f );
	osg::ShapeDrawable* sd = new osg::ShapeDrawable( cylinder );
	sd->setColor( osg::Vec4( 0.8f, 0.5f, 0.2f, 1.f ) );
	root->addDrawable(sd);

	osg::StateSet* stateSet = root->getOrCreateStateSet();
	osg::Material* material = new osg::Material;
	material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );
	stateSet->setAttributeAndModes( material );
	stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );

	return root;
}

void setupCamera(QtOSGWidget & widget)
{
	//Setup the camera so it will be pleasant to look into

	widget.getCamera()->setClearColor( osg::Vec4( 0.9f, 0.9f, 1.f, 1.f ) );

	double aspectRatio = widget.width();
	aspectRatio /= widget.height();
	widget.getCamera()->setProjectionMatrixAsPerspective( 30, aspectRatio, 1, 1000 );
}

osg::ref_ptr<osg::Geode> setupDemo(QtOSGWidget & widget)
{
	osg::Geode * root = setupScene();
	setupCamera(widget);
	widget.setSceneData(root);

	return root;
}

int main(int argc, char** argv)
{
	QApplication qapp(argc, argv);

#	ifdef _WIN32
	//This MUST be executed before the main window is created, otherwise the software OpenGL
	//	rendered might be chosen and OSG will fail with obscure errors.
	//For reference, see:
	//	https://doc.qt.io/qt-5/windows-requirements.html#dynamically-loading-graphics-drivers
	QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
#	endif

	QMainWindow window;

	//Create a widget that wraps osgViewer::GraphicsWindowEmbedded
	//This constructor will create a view and a camera, setup a camera trackball manipulator
	//	and install a filter to translate Qt mouse events to OSG mouse events to be able
	//	to use the manupulator.
	QtOSGWidget widget(&window);

	//Setup a demo scene and a projection matrix to have something to play with
	//This can also be invoked after window.show() with the same effect
	setupDemo(widget);

	window.setCentralWidget(&widget);
	window.show();

	//Run the Qt application.
	//By default the rendered OSG view will only be updated when the
	// camera manipulator processes a mouse event or when the widget is resized
	return qapp.exec();
}
