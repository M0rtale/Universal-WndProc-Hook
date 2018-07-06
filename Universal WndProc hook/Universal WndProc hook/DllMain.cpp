#include "DllMain.h"


void Start()
{
	//Universal WndProc Hook with SetWindowLongPtr
	// using Hook::KeyListener[VKkey] to get the corresponding keypress
	// a replacement of GetAKeySyncState.
	Hook::oriWndProc = SetWindowLongPtr(0, GWLP_WNDPROC, (LONG_PTR)Hook::WndProc);
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule); // said to increase performance?
		CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(Start), NULL, NULL, NULL); // start another thread running the hooking stuff
		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}