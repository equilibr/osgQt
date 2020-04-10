#include "demosupport.h"

#include <osg/ShapeDrawable>
#include <osg/StateSet>
#include <osg/Material>
#include <osgGA/DriveManipulator>

osg::Geode * osgQtDemo::createScene()
{
	//Create a simple scene with a pretty cylinder
	osg::Geode * root = new osg::Geode;

	osg::Cylinder* cylinder = new osg::Cylinder( osg::Vec3( 0.f, 0.f, 0.f ), 0.25f, 0.5f );
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

void osgQtDemo::setupCameraManipulator(osgQt::Widget *widget)
{
	//Setup a camera manupulator

	osgGA::DriveManipulator * manipulator = new osgGA::DriveManipulator;

	widget->getViewer()->setCameraManipulator(manipulator);
	widget->getViewer()->getCameraManipulator()->setHomePosition(
	{-2,0,1},
	{0,0,0},
	{0,0,1});
}

void osgQtDemo::setupCamera(osgQt::Widget *widget)
{
	widget->getCamera()->setClearColor( osg::Vec4( 0.9f, 0.9f, 1.f, 1.f ) );

	//Calculate the projection aspect ration based on the current widget dimentions
	double aspectRatio = widget->width();
	aspectRatio /= widget->height();
	widget->getCamera()->setProjectionMatrixAsPerspective(30, aspectRatio, 1, 1000);
}
