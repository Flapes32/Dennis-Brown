#include <stdio.h>
#include <Windows.h>

int main(int argc, char** argv)
{
	STARTUPINFO supinfo;
	PROCESS_INFORMATION procsinformation;

	ZeroMemory(&supinfo, sizeof(supinfo));

	supinfo.cb = sizeof(supinfo);

	ZeroMemory(&procsinformation, sizeof(procsinformation));

	if (!CreateProcess(L"C:\\Users\\Asus\\source\\repos\\Zadanie1\\x64\\Debug\\TASK1.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &supinfo, &procsinformation))
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
	}

	WaitForSingleObject(procsinformation.hProcess, INFINITE);


	return 0;
}
