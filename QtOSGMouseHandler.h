#ifndef QTOSGMOUSEHANDLER_H
#define QTOSGMOUSEHANDLER_H

#include <QtEvents>

#include "QtOSGWidget.h"

class QtOSGMouseHandler : public QObject
{
	Q_OBJECT
	public:
		QtOSGMouseHandler(QtOSGWidget * parent)
			: QObject(parent)
		{
			if (parent)
				parent->installEventFilter(this);
		}

		~QtOSGMouseHandler()
		{
			if (parent())
				parent()->removeEventFilter(this);
		}

	protected:
		 bool eventFilter(QObject *obj, QEvent *event);
};

#endif // QTOSGMOUSEHANDLER_H
