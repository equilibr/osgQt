#include <QApplication>
#include <QMainWindow>

#include <osg/Camera>
#include <osg/ShapeDrawable>
#include <osg/StateSet>
#include <osg/Material>
#include <osgGA/TrackballManipulator>

#include "QtOSGWidget.h"
#include "QtOSGMouseHandler.h"

void setupOSG(QtOSGWidget * widget)
{
	osgViewer::Viewer * viewer = widget->getViewer().get();

	osg::Cylinder* cylinder    = new osg::Cylinder( osg::Vec3( 0.f, 0.f, 0.f ), 0.25f, 0.5f );
	osg::ShapeDrawable* sd = new osg::ShapeDrawable( cylinder );
	sd->setColor( osg::Vec4( 0.8f, 0.5f, 0.2f, 1.f ) );
	osg::Geode* geode = new osg::Geode;
	geode->addDrawable(sd);

	osg::StateSet* stateSet = geode->getOrCreateStateSet();
	osg::Material* material = new osg::Material;
	material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );
	stateSet->setAttributeAndModes( material );
	stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );

	// create a main camera and attach a graphics context to it
	osg::Camera* camera = viewer->getCamera();
	camera->setClearColor( osg::Vec4( 0.9f, 0.9f, 1.f, 1.f ) );

	double aspectRatio = widget->width();
	aspectRatio /= widget->height();
	camera->setProjectionMatrixAsPerspective( 30, aspectRatio, 1, 1000 );

	// attach a camera to the viewer
	viewer->setSceneData(geode);
	osgGA::TrackballManipulator* manipulator = new osgGA::TrackballManipulator;
	manipulator->setAllowThrow( false );
	viewer->setCameraManipulator(manipulator);
//	viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);
}

int main(int argc, char** argv)
{
	QApplication qapp(argc, argv);
	QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);

	QMainWindow window;

	QtOSGWidget widget(&window);
	QtOSGMouseHandler h(&widget);

	window.setCentralWidget(&widget);
	window.show();

	setupOSG(&widget);

	return qapp.exec();
}
