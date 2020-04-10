/*
MIT License

Copyright (c) 2020 Sergey Tomilin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef QTOSGWIDGET_H
#define QTOSGWIDGET_H

#include <QOpenGLWidget>

#include <osg/ref_ptr>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>

namespace osgQt
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
