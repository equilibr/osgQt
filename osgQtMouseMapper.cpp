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

#include "osgQtMouseMapper.h"

using namespace osgQt;

bool MouseMapper::eventFilter(QObject * obj, QEvent * event)
{
	static auto convertButton =
			[](Qt::MouseButton b) -> unsigned int
	{
		switch (b)
		{
			case Qt::LeftButton:
				return 1;
			case Qt::MiddleButton:
				return 2;
			case Qt::RightButton:
				return 3;
			default:
				return 0;
		}
	};

	Widget * o = static_cast<Widget *>(obj);

	switch (event->type())
	{
		case QEvent::MouseButtonPress:
		case QEvent::MouseButtonDblClick:
		case QEvent::MouseButtonRelease:
		case QEvent::MouseMove:
		{
			const QMouseEvent * e = static_cast<QMouseEvent *>(event);

			switch (event->type())
			{
				case QEvent::MouseButtonPress:
					o->getGraphicsWindow().get()->getEventQueue()->mouseButtonPress(
								e->x(),
								e->y(),
								convertButton(e->button()));
					break;

				case QEvent::MouseButtonDblClick:
					o->getGraphicsWindow().get()->getEventQueue()->mouseDoubleButtonPress(
								e->x(),
								e->y(),
								convertButton(e->button()));
					break;

				case QEvent::MouseButtonRelease:
					o->getGraphicsWindow().get()->getEventQueue()->mouseButtonRelease(
								e->x(),
								e->y(),
								convertButton(e->button()));
					break;

				case QEvent::MouseMove:
					o->getGraphicsWindow().get()->getEventQueue()->mouseMotion(
								e->x(),
								e->y());
					break;

				default:
					break;
			}

			o->update();
			break;
		}

		case QEvent::Wheel:
		{
			const QWheelEvent * e = static_cast<QWheelEvent *>(event);

			o->getGraphicsWindow().get()->getEventQueue()->mouseScroll(
						(e->delta() > 0)
						? osgGA::GUIEventAdapter::SCROLL_UP
						: osgGA::GUIEventAdapter::SCROLL_DOWN
						);

			o->update();
			break;
		}

		default:
			return QObject::eventFilter(obj, event);
	}

	//Standard event processing
	return QObject::eventFilter(obj, event);
}
