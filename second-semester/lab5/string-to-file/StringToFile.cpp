#include <windows.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	HANDLE hFile;

	if (argv[1] == NULL || argv[2] == NULL) {
		printf("Please input 2 arguments!");
		return 0;
	}
	//StringToFile.exe what where
	hFile = CreateFile(argv[1], GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	SetFilePointer(hFile, 0, 0, FILE_END);
	WriteFile(hFile, argv[2], strlen(argv[2]), 0, 0);

	CloseHandle(hFile);
	return 0;
}