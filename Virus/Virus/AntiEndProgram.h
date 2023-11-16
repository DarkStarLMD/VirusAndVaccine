#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <TlHelp32.h>
#include <stdio.h>
#include <comdef.h>

using namespace std;

DWORD GetProcId(const char* procName)
{
    DWORD procId = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 procEntry;
        procEntry.dwSize = sizeof(procEntry);

        if (Process32First(hSnap, &procEntry))
        {
            do
            {
                _bstr_t b(procEntry.szExeFile);
                const char* procEntry1 = b;

                if (!_stricmp(procEntry1, procName))
                {
                    procId = procEntry.th32ProcessID;
                    break;
                }
            } while (Process32Next(hSnap, &procEntry));
        }
    }
    CloseHandle(hSnap);
    return procId;
}

void ScanAndEnd() 
{
    if (GetProcId("Taskmgr.exe"))
    {
        system("taskkill/IM Taskmgr.exe");
    }

    if (GetProcId("x64dbg.exe"))
    {
        system("taskkill/IM x64dbg.exe");
    }
}