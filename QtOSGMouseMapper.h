#ifndef QTOSGMOUSEMAPPER_H
#define QTOSGMOUSEMAPPER_H

#include <QtEvents>

#include "QtOSGWidget.h"

namespace QtOSG
{

	class MouseMapper : public QObject
	{
			Q_OBJECT
		public:
			MouseMapper(Widget * parent)
				: QObject(parent)
			{
				if (parent)
					parent->installEventFilter(this);
			}

			~MouseMapper()
			{
				if (parent())
					parent()->removeEventFilter(this);
			}

		protected:
			bool eventFilter(QObject *obj, QEvent *event) override;
	};

}

#endif // QTOSGMOUSEMAPPER_H
