#include "Hook.h"

LONG_PTR Hook::oriWndProc = NULL; //instantiate
bool Hook::KeyListener[256] = {};

LRESULT __stdcall Hook::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) // WndProc wrapper
{ // this will be called each time WndProc is called.
	switch (uMsg) // Each keystroke will PostMessage with uMsg down and wParam the key.
	{
	case WM_LBUTTONDOWN:
		Hook::KeyListener[VK_LBUTTON] = true;
		break;
	case WM_LBUTTONUP:
		Hook::KeyListener[VK_LBUTTON] = false;
		break;
	case WM_RBUTTONDOWN:
		Hook::KeyListener[VK_RBUTTON] = true;
		break;
	case WM_RBUTTONUP:
		Hook::KeyListener[VK_RBUTTON] = false;
		break;
	case WM_MBUTTONDOWN:
		Hook::KeyListener[VK_MBUTTON] = true;
		break;
	case WM_MBUTTONUP:
		Hook::KeyListener[VK_MBUTTON] = false;
		break;
	case WM_XBUTTONDOWN:
	{
		if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1)
		{
			Hook::KeyListener[VK_XBUTTON1] = true;
		}
		else if (GET_XBUTTON_WPARAM(wParam) == XBUTTON2)
		{
			Hook::KeyListener[VK_XBUTTON2] = true;
		}
		break;
	}
	case WM_XBUTTONUP:
	{
		if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1)
		{
			Hook::KeyListener[VK_XBUTTON1] = false;
		}
		else if (GET_XBUTTON_WPARAM(wParam) == XBUTTON2)
		{
			Hook::KeyListener[VK_XBUTTON2] = false;
		}
		break;
	}
	case WM_KEYDOWN:
		Hook::KeyListener[wParam] = true;
		break;
	case WM_KEYUP:
		Hook::KeyListener[wParam] = false;
		break;
	default:
		break;
	}

	return CallWindowProcW((WNDPROC)Hook::oriWndProc, hWnd, uMsg, wParam, lParam); // Call the original Function
}