#include "demoscene.h"

#include <osg/ShapeDrawable>
#include <osg/StateSet>
#include <osg/Material>

DemoScene::DemoScene() :
	root{new osg::Geode}
{
	//Create a simple scene with a pretty cylinder

	osg::Cylinder* cylinder = new osg::Cylinder( osg::Vec3( 0.f, 0.f, 0.f ), 0.25f, 0.5f );
	osg::ShapeDrawable* sd = new osg::ShapeDrawable( cylinder );
	sd->setColor( osg::Vec4( 0.8f, 0.5f, 0.2f, 1.f ) );
	root->addDrawable(sd);

	osg::StateSet* stateSet = root->getOrCreateStateSet();
	osg::Material* material = new osg::Material;
	material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );
	stateSet->setAttributeAndModes( material );
	stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );
}
