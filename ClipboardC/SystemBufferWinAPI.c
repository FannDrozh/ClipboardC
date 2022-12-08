#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

/*������� 0 (����� ������� ����� ����������� word � ���������� WinAPI, ��������� ��������� ����� ������)*/
//int main()
//{
//	LPWSTR Message = L"�����-�� �����";
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
//	MessageBox(NULL, Mess, L"����������  ������� ������", MB_OK);
//	return 0;
//}

/*������� 1 (������ ����������� �� ���������� ������ ������)*/
//LPWSTR ClipboardOutputText();
//
//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
//{
//	while (TRUE)
//	{
//		LPSTR Data = ClipboardOutputText();
//		TCHAR Alert[] = L"���������� ��������� �����, ���������� ��������� �����: ";
//		TCHAR third[512];
//		swprintf(third, sizeof third, L"%s%s", Alert, Data);
//		if (*Data != 0)
//		{
//			MessageBox(NULL, &third, L"��������!!! ���������!!!", MB_OK, MB_ICONWARNING);
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

/*������� 2 (��� ����������� ����� � ��������� ����� ������ �������� � ����� �� ��������� �������� (1 - ����, 2 - ��� � �.�.))*/
LPWSTR ClipboardOutputText();
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	while (TRUE)
	{
		LPSTR Data = ClipboardOutputText();
		TCHAR third[1024];
		/*sprintf(third, "%s%s", Data, L"����");
		if (*Data != 0) 
		{
			MessageBox(NULL, &third, L"����������� �����: ", MB_OK, MB_ICONWARNING);
			ClipboardInputText(Data);
		}*/
		Text(Data);
		Sleep(1000);
	}
	return 0;
}
int ClipboardInputText(LPWSTR buffer)
{
	DWORD len;
	HANDLE hMem;
	len = wcslen(buffer) + 1;

	hMem = GlobalAlloc(GMEM_MOVEABLE, len * sizeof(LPWSTR));
	memcpy(GlobalLock(hMem), buffer, len * sizeof(LPWSTR));
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMem);
	CloseClipboard();
	return 0;
}
TCHAR* ClipboardOutputText()
{
	TCHAR* Mess = NULL;
	OpenClipboard(NULL);
	HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT);
	Mess = (TCHAR*)GlobalLock(hClipboardData);
	GlobalUnlock(hClipboardData);
	CloseClipboard();
	EmptyClipboard();
	return Mess;
}
Text(TCHAR* Data)
{
	int i = 0;
	TCHAR third[1024];
	char* m = calloc(100, sizeof(char));
	while (Data[i])
	{
		if (Data[i] == '1')
		{
			sprintf(m, "%s%s", m, L"����");
			MessageBoxW(NULL, L"����", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '2')
		{
			sprintf(m, "%s%s", m, L"���");
			MessageBoxW(NULL, L"���", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '3')
		{
			sprintf(m, "%s%s", m, L"���");
			MessageBoxW(NULL, L"���", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '4')
		{
			sprintf(m, "%s%s", m, L"������");
			MessageBoxW(NULL, L"������", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '5')
		{
			sprintf(m, "%s%s", m, L"����");
			MessageBoxW(NULL, L"����", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '6')
		{
			sprintf(m, "%s%s", m, L"�����");
			MessageBoxW(NULL, L"�����", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '7')
		{
			sprintf(m, "%s%s", m, L"����");
			MessageBoxW(NULL, L"����", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '8')
		{
			sprintf(m, "%s%s", m, L"������");
			MessageBoxW(NULL, L"������", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '9')
		{
			sprintf(m, "%s%s", m, L"������");
			MessageBoxW(NULL, L"������", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '0')
		{
			sprintf(m, "%s%s", m, L"����");
			MessageBoxW(NULL, L"����", NULL, MB_OK | MB_ICONWARNING);
		}
		i++;
	}
	swprintf(third, sizeof(third), L"%s ", m);
	ClipboardInputText(third);
}