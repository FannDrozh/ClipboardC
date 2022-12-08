#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

/*Задание 0 (Обмен данными между приложением word и программой WinAPI, используя системный буфер обмена)*/
//int main()
//{
//	LPWSTR Message = L"Какой-то текст";
//	ClipboardInputText(Message);
//	ClipboardOutputText();
//}
//
//int ClipboardInputText(LPWSTR buffer)
//{
//	DWORD len;
//	HANDLE hMem;
//	len = wcslen(buffer) + 1;
//
//	hMem = GlobalAlloc(GMEM_MOVEABLE, len * sizeof(LPWSTR));
//	memcpy(GlobalLock(hMem), buffer, len * sizeof(LPWSTR));
//	GlobalUnlock(hMem);
//	OpenClipboard(0);
//	EmptyClipboard();
//	SetClipboardData(CF_UNICODETEXT, hMem);
//	CloseClipboard();
//	return 0;
//}
//
//int ClipboardOutputText()
//{
//	LPWSTR Mess = NULL;
//	OpenClipboard(NULL);
//	HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT);
//	Mess = (LPWSTR)GlobalLock(hClipboardData);
//	GlobalUnlock(hClipboardData);
//	MessageBox(NULL, Mess, L"Содержимое  буффера обмена", MB_OK);
//	return 0;
//}

/*Задание 1 (запрет копирования из системного буфера обмена)*/
//LPWSTR ClipboardOutputText();
//
//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
//{
//	while (TRUE)
//	{
//		LPSTR Data = ClipboardOutputText();
//		TCHAR Alert[] = L"Вынарушили Авторские права, скопировав следующий текст: ";
//		TCHAR third[512];
//		swprintf(third, sizeof third, L"%s%s", Alert, Data);
//		if (*Data != 0)
//		{
//			MessageBox(NULL, &third, L"Внимание!!! Нарушуние!!!", MB_OK, MB_ICONWARNING);
//			ClipboardInputText("");
//		}
//		Sleep(1000);
//	}
//	return 0;
//}
//
//TCHAR* ClipboardOutputText()
//{
//	TCHAR* Mess = NULL;
//	OpenClipboard(NULL);
//	HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT);
//	Mess = (TCHAR*)GlobalLock(hClipboardData);
//	GlobalUnlock(hClipboardData);
//	CloseClipboard();
//	EmptyClipboard();
//	return Mess;
//}
//
//int ClipboardInputText(LPWSTR buffer)
//{
//	DWORD len;
//	HANDLE hMem;
//	len = wcslen(buffer) + 1;
//
//	hMem = GlobalAlloc(GMEM_MOVEABLE, len * sizeof(LPWSTR));
//	memcpy(GlobalLock(hMem), buffer, len * sizeof(LPWSTR));
//	GlobalUnlock(hMem);
//	OpenClipboard(0);
//	EmptyClipboard();
//	SetClipboardData(CF_UNICODETEXT, hMem);
//	CloseClipboard();
//	return 0;
//}

/*Задание 2 (при копировании цифры в системный буфер обмена выводить в буфер ее словесное описание (1 - один, 2 - два и т.д.))*/
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	while (TRUE)
	{
		LPSTR Data = ClipboardOutputText();
		TCHAR Alert[] = L"Вы скопировали цифру ";
		TCHAR third[512];
		swprintf(third, sizeof third, L"%s%s", Alert, Data);
		if (*Data != 0)
		{
			MessageBox(NULL, &third, L"ва", MB_OK, MB_ICONWARNING);
			ClipboardInputText("");
		}
		Sleep(1000);
	}
	return 0;
}