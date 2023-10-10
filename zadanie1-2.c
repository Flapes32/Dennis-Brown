#include <stdio.h>
#include <Windows.h>

int main(int argc, char** argv)
{
	STARTUPINFO supinfo;
	PROCESS_INFORMATION procsinformation;

	ZeroMemory(&supinfo, sizeof(supinfo));

	supinfo.cb = sizeof(supinfo);

	ZeroMemory(&procsinformation, sizeof(procsinformation));

	if (argc != 2)
	{
		printf("Usage: %s [cmdline]\n", argv[0]);
		return;
	}

	if (!CreateProcess("C:\\Users\\flapes32\\source\\repos\\Zadanie1\\x64\\Debug\\Zadanie1.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startupinfo, &procsinformation))
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
	}

	WaitForSingleObject(procsinformation.hProcess, INFINITE);

	CHandle(procsinformation.hProcess);
	CHandle(procsinformation.hThread);

	return 0;
}