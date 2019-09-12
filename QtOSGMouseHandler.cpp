#include "QtOSGMouseHandler.h"

bool QtOSGMouseHandler::eventFilter(QObject * obj, QEvent * event)
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

	QtOSGWidget * o = static_cast<QtOSGWidget *>(obj);

	switch (event->type())
	{
		case QEvent::MouseButtonPress:
		case QEvent::MouseButtonRelease:
		case QEvent::MouseMove:
		{
			QMouseEvent * e = static_cast<QMouseEvent *>(event);

			switch (event->type())
			{
				case QEvent::MouseButtonPress:
					o->getGraphicsWindow().get()->getEventQueue()->mouseButtonPress(
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
			QWheelEvent * e = static_cast<QWheelEvent *>(event);

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
