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

#include "osgQtKeyboardMapper.h"

#include <QMap>

namespace osgQt
{
	const QMap<int,int> initializeKey()
	{
		QMap<int,int> map;

		return map;
	}

	const QMap<int,int> initializeUnmodifiedKey()
	{
		QMap<int,int> map;

		return map;
	}

	//Maps to convert the key values
	static const QMap<int,int> keyMap = initializeKey();
	static const QMap<int,int> unmodifiedKeyMap = initializeUnmodifiedKey();

	int key(const QKeyEvent * e)
	{
		return 0;
	}

	int unmodifiedKey(const QKeyEvent * e)
	{
		return 0;
	}

}

using namespace osgQt;

bool KeyboardMapper::eventFilter(QObject * obj, QEvent * event)
{
	Widget * o = static_cast<Widget *>(obj);

	switch (event->type())
	{
		case QEvent::KeyPress:
		case QEvent::KeyRelease:
		{
			const QKeyEvent * e = static_cast<QKeyEvent *>(event);

			const int key = osgQt::key(e);
			const int unmodifiedKey = osgQt::unmodifiedKey(e);

			switch (event->type())
			{
				case QEvent::KeyPress:
					o->getGraphicsWindow().get()->getEventQueue()->keyPress(key, unmodifiedKey);
					break;

				case QEvent::KeyRelease:
					o->getGraphicsWindow().get()->getEventQueue()->keyRelease(key, unmodifiedKey);
					break;

				default:
					break;
			}

			o->update();
			return true;
		}

		default:
			//Standard event processing
			return QObject::eventFilter(obj, event);
	}
}
