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

#include "osgGA/GUIEventAdapter"
#include <QHash>

namespace osgQt
{
	using osgKey = osgGA::GUIEventAdapter::KeySymbol;

	constexpr int unknownKey = 0;

	const QHash<int,int> initializeModifierKeys()
	{
		QHash<int,int> map;

		//For most modifier keys Qt does not differentiate between left and righ
		//The OSG left version is arbitrary selected

		map.insert(Qt::Key::Key_Shift,			osgKey::KEY_Shift_L);
//		map.insert(Qt::Key::Key_Shift,			osgKey::KEY_Shift_R);
		map.insert(Qt::Key::Key_Control,		osgKey::KEY_Control_L);
//		map.insert(Qt::Key::Key_Control,		osgKey::KEY_Control_R);
		map.insert(Qt::Key::Key_CapsLock,		osgKey::KEY_Caps_Lock);
//		map.insert(Qt::Key::Key_Shift,			osgKey::KEY_Shift_Lock);

		map.insert(Qt::Key::Key_Meta,			osgKey::KEY_Meta_L);
//		map.insert(Qt::Key::Key_Meta,			osgKey::KEY_Meta_R);
		map.insert(Qt::Key::Key_Alt,			osgKey::KEY_Alt_L);
//		map.insert(Qt::Key::Key_Alt,			osgKey::KEY_Alt_R);
		map.insert(Qt::Key::Key_Super_L,		osgKey::KEY_Super_L);
		map.insert(Qt::Key::Key_Super_R,		osgKey::KEY_Super_R);
		map.insert(Qt::Key::Key_Hyper_L,		osgKey::KEY_Hyper_L);
		map.insert(Qt::Key::Key_Hyper_R,		osgKey::KEY_Hyper_R);

		return map;
	}

	const QHash<int,int> initializeKeypadKeys()
	{
		QHash<int,int> map;

		//Mappings from OSG keys to OSG keypad keys

		//For some OSG keypad keys there is no corresponding OSG key
		//Theese lines are left commented out with with the closest OSG key

		//DO NOT UNCOMMENT THEM since those key values are already used!!!

		map.insert(osgKey::KEY_Space,		osgKey::KEY_KP_Space);
		map.insert(osgKey::KEY_Tab,			osgKey::KEY_KP_Tab);
		map.insert(osgKey::KEY_Return,		osgKey::KEY_KP_Enter);
		map.insert(osgKey::KEY_F1,			osgKey::KEY_KP_F1);
		map.insert(osgKey::KEY_F2,			osgKey::KEY_KP_F2);
		map.insert(osgKey::KEY_F3,			osgKey::KEY_KP_F3);
		map.insert(osgKey::KEY_F4,			osgKey::KEY_KP_F4);

		//Keys with direct mappings
		for (int key = 0; key <= osgKey::KEY_Begin - osgKey::KEY_Home; ++key)
			map.insert(osgKey::KEY_Home + key, osgKey::KEY_KP_Home + key);

		map.insert(osgKey::KEY_Insert,			osgKey::KEY_KP_Insert);
		map.insert(osgKey::KEY_Delete,			osgKey::KEY_KP_Delete);
		map.insert(osgKey::KEY_Equals,			osgKey::KEY_KP_Equal);
		map.insert(osgKey::KEY_Asterisk,		osgKey::KEY_KP_Multiply);
		map.insert(osgKey::KEY_Plus,			osgKey::KEY_KP_Add);
//		map.insert(osgKey::KEY_Comma,			osgKey::KEY_KP_Separator);
		map.insert(osgKey::KEY_Minus,			osgKey::KEY_KP_Subtract);
//		map.insert(osgKey::KEY_Period,			osgKey::KEY_KP_Decimal);
		map.insert(osgKey::KEY_Slash,			osgKey::KEY_KP_Divide);

		//Keypad numbers
		for (int key = 0; key <= 9; ++key)
			map.insert(osgKey::KEY_0 + key, osgKey::KEY_KP_0 + key);

		return map;
	}

	const QHash<int,int> initializeKeys()
	{
		QHash<int,int> map;

		//The ASCII symbols from space to @ and the symbols betwen the letters
		//	have a one-to-one mapping between Qt and OSG
		for (int key = 0x20; key <= 0x40; ++key)
			map.insert(key,key);

		for (int key = 0x5B; key <= 0x60; ++key)
			map.insert(key,key);

		for (int key = 0x7B; key <= 0x7E; ++key)
			map.insert(key,key);

		//For the letters Qt uses upper-case ASCII and OSG uses lower-case ascii
		for (int key = 0x41; key <= 0x5A; ++key)
			map.insert(key, 0x20 + key);

		//Main function keys
		for (int key = 0; key < 35; ++key)
			map.insert(Qt::Key_F1 + key, osgKey::KEY_F1 + key);

		//All other keys have unstructured mappings between Qt and OSG
		//The following code is written in the order of
		//	the OSG GUIEventAdapter::KeySymbol enumeration

		//For some OSG keys there is no corresponding Qt key
		//Theese lines are left commented out with with the closest Qt key

		//DO NOT UNCOMMENT THEM since those Qt key values are already used!!!

		map.insert(Qt::Key::Key_Backspace,		osgKey::KEY_BackSpace);
		map.insert(Qt::Key::Key_Tab,			osgKey::KEY_Tab);
//		map.insert(Qt::Key::Key_Enter,			osgKey::KEY_Linefeed);
		map.insert(Qt::Key::Key_Clear,			osgKey::KEY_Clear);
		map.insert(Qt::Key::Key_Return,			osgKey::KEY_Return);
		map.insert(Qt::Key::Key_Enter,			osgKey::KEY_Return);
		map.insert(Qt::Key::Key_Pause,			osgKey::KEY_Pause);
		map.insert(Qt::Key::Key_ScrollLock,		osgKey::KEY_Scroll_Lock);
		map.insert(Qt::Key::Key_SysReq,			osgKey::KEY_Sys_Req);
		map.insert(Qt::Key::Key_Escape,			osgKey::KEY_Escape);
		map.insert(Qt::Key::Key_Delete,			osgKey::KEY_Delete);

		map.insert(Qt::Key::Key_Home,			osgKey::KEY_Home);
		map.insert(Qt::Key::Key_Left,			osgKey::KEY_Left);
		map.insert(Qt::Key::Key_Up,				osgKey::KEY_Up);
		map.insert(Qt::Key::Key_Right,			osgKey::KEY_Right);
		map.insert(Qt::Key::Key_Down,			osgKey::KEY_Down);
		map.insert(Qt::Key::Key_Back,			osgKey::KEY_Prior);
		map.insert(Qt::Key::Key_PageUp,			osgKey::KEY_Page_Up);
		map.insert(Qt::Key::Key_Forward,		osgKey::KEY_Next);
		map.insert(Qt::Key::Key_PageDown,		osgKey::KEY_Page_Down);
		map.insert(Qt::Key::Key_End,			osgKey::KEY_End);
//		map.insert(Qt::Key::Key_Home,			osgKey::KEY_Begin);

		map.insert(Qt::Key::Key_Select,			osgKey::KEY_Select);
		map.insert(Qt::Key::Key_Print,			osgKey::KEY_Print);
		map.insert(Qt::Key::Key_Execute,		osgKey::KEY_Execute);
		map.insert(Qt::Key::Key_Insert,			osgKey::KEY_Insert);
		map.insert(Qt::Key::Key_Undo,			osgKey::KEY_Undo);
		map.insert(Qt::Key::Key_Redo,			osgKey::KEY_Redo);
		map.insert(Qt::Key::Key_Menu,			osgKey::KEY_Menu);
		map.insert(Qt::Key::Key_Search,			osgKey::KEY_Find);
		map.insert(Qt::Key::Key_Find,			osgKey::KEY_Find);
		map.insert(Qt::Key::Key_Stop,			osgKey::KEY_Cancel);
		map.insert(Qt::Key::Key_Cancel,			osgKey::KEY_Cancel);
		map.insert(Qt::Key::Key_Help,			osgKey::KEY_Help);
//		map.insert(Qt::Key::Key_Pause,			osgKey::KEY_Break);
		map.insert(Qt::Key::Key_Mode_switch,	osgKey::KEY_Mode_switch);
		map.insert(Qt::Key::Key_NumLock,		osgKey::KEY_Num_Lock);

		//Append the modifier keys to simplify the regular key lookup
		map.unite(initializeModifierKeys());

		return map;
	}

	//Hashes to convert the key values
	static const QHash<int,int> modifierKeys = initializeModifierKeys();
	static const QHash<int,int> keypadKeys = initializeKeypadKeys();
	static const QHash<int,int> keys = initializeKeys();

	int key(const QKeyEvent * e)
	{
		return  keys.value(e->key(), unknownKey);
	}

	int unmodifiedKey(const QKeyEvent * e, int key)
	{
		const Qt::KeyboardModifiers modifyiers = e->modifiers();

		//The modifier keys themselves are returned as-is
		int result = modifierKeys.value(e->key(), unknownKey);
		if (result != unknownKey)
			return result;

		//Keypad keys are converted
		if (e->modifiers().testFlag(Qt::KeypadModifier))
			result = keypadKeys.value(key, unknownKey);
		if (result != unknownKey)
			return result;

		//When shift is pressed the appropriate keys are converted to upper case
		//This is actually a hack for a few reasons:
		// 1. The OSG key enumeration does not declares upper case leters
		// 2. Usually, when shift is pressed with caps-lock active a lower case letter is returned

		if (modifyiers.testFlag(Qt::ShiftModifier) && (key >= osgKey::KEY_A) && (key <= osgKey::KEY_Z))
			return key - 0x20;

		return key;
	}

}

using namespace osgQt;

bool KeyboardMapper::eventFilter(QObject * obj, QEvent * event)
{
	Widget * o = static_cast<Widget *>(obj);
	const QEvent::Type eventType= event->type();

	switch (eventType)
	{
		case QEvent::KeyPress:
		case QEvent::KeyRelease:
		{
			const QKeyEvent * e = static_cast<QKeyEvent *>(event);
			const int key = osgQt::key(e);

			if (key == unknownKey)
				//There is no mapping to OSG for this key event
				break;

			const int unmodifiedKey = osgQt::unmodifiedKey(e, key);

			if (eventType == QEvent::KeyPress)
				o->getGraphicsWindow().get()->getEventQueue()->keyPress(key, unmodifiedKey);
			else
				o->getGraphicsWindow().get()->getEventQueue()->keyRelease(key, unmodifiedKey);

			o->update();
			return true;
		}

		default:
			break;
	}

	//Standard event processing
	return QObject::eventFilter(obj, event);
}
