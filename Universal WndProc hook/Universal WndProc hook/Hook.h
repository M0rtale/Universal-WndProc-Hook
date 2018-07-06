#pragma once
#include <iostream>
#include <Windows.h>


namespace Hook
{
	extern LONG_PTR oriWndProc;

	extern bool KeyListener[256]; // corresponding indeces will be set true when message is posted to WndProc

	LRESULT __stdcall WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}