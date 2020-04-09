#ifndef QTOSGWIDGET_H
#define QTOSGWIDGET_H

#include <QOpenGLWidget>

#include <osg/ref_ptr>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>

namespace QtOSG
{

	class Widget : public QOpenGLWidget
	{
			Q_OBJECT

		public:
			explicit
			Widget(QWidget* parent = nullptr)
				: Widget(new osgViewer::Viewer, new osg::Camera, parent)
			{}

			explicit
			Widget(
					osg::ref_ptr<osgViewer::Viewer> & viewer,
					osg::ref_ptr<osg::Camera> & camera,
					QWidget* parent = nullptr)
				: Widget(viewer.get(), camera.get(), parent) {}

			Widget(
					osgViewer::Viewer * viewer,
					osg::Camera * camera,
					QWidget* parent = nullptr);

			osg::ref_ptr<osg::Camera> getCamera() { return viewer->getCamera(); }
			osg::ref_ptr<osgViewer::Viewer> & getViewer() { return viewer; }
			osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> & getGraphicsWindow() { return graphicsWindow; }

			void setMainCamera(osg::Camera * camera);

			//Helper function to set the scene root
			template<class T> void setSceneData( const osg::ref_ptr<T> & node )
			{ setSceneData(node.get()); }

			void setSceneData(osg::Node * node)
			{
				viewer->setSceneData(node);
			}

		protected:
			virtual void resizeGL(int w, int h) override;
			virtual void paintGL() override;

			osg::ref_ptr<osgViewer::Viewer> viewer = nullptr;
			osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> graphicsWindow = nullptr;

	};

}

#endif // QTOSGWIDGET_H
