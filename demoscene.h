#ifndef DEMOSCENE_H
#define DEMOSCENE_H

#include <osg/Geode>

class DemoScene
{
	public:
		DemoScene();

		osg::Geode * sceneRoot() const { return root; }

	private:
		osg::Geode * root;
};

#endif // DEMOSCENE_H
