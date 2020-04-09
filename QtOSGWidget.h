#ifndef QTOSGWIDGET_H
#define QTOSGWIDGET_H

#include <QOpenGLWidget>

#include <osg/ref_ptr>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>

class QtOSGWidget : public QOpenGLWidget
{
	Q_OBJECT

	public:
		explicit
		QtOSGWidget(QWidget* parent = nullptr, bool setupCameraManipulator = false)
			: QtOSGWidget(new osgViewer::Viewer, new osg::Camera, parent)
		{
			if (setupCameraManipulator)
				setupDefaultCameraManipulator();
		}

		explicit
		QtOSGWidget(
				osg::ref_ptr<osgViewer::Viewer> & viewer,
				osg::ref_ptr<osg::Camera> & camera,
				QWidget* parent = nullptr)
			: QtOSGWidget(viewer.get(), camera.get(), parent) {}

		QtOSGWidget(
				osgViewer::Viewer * viewer,
				osg::Camera * camera,
				QWidget* parent = nullptr);

		osg::ref_ptr<osg::Camera> getCamera() { return viewer->getCamera(); }
		osg::ref_ptr<osgViewer::Viewer> & getViewer() { return viewer; }
		osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> & getGraphicsWindow() { return graphicsWindow; }

		//Helper function to set the scene root
		template<class T> void setSceneData( const osg::ref_ptr<T> & node )
		{ setSceneData(node.get()); }

		void setSceneData(osg::Node * node)
		{
			viewer->setSceneData(node);
		}

		void setupDefaultCameraManipulator();
	protected:
		virtual void resizeGL(int w, int h) override;
		virtual void paintGL() override;

		osg::ref_ptr<osgViewer::Viewer> viewer = nullptr;
		osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> graphicsWindow = nullptr;

};

#endif // QTOSGWIDGET_H
