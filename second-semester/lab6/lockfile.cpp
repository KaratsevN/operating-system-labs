#include <windows.h>
#include <iostream>
#include <string.h>
#include <locale.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[], char *envp[]) {
	setlocale(LC_ALL, "Russian");
	HANDLE hFile = CreateFile(argv[1], GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	LPBY_HANDLE_FILE_INFORMATION info = new _BY_HANDLE_FILE_INFORMATION();

	if (argv[1] == NULL) {
		printf("Please add 2 arg!"); 
		return 0;
	}

	if (!GetFileInformationByHandle(hFile, info)) {
		printf("Error receiving information");
		return 0;
	}

	if (strcmp(argv[2], "-h") == 0) {
		printf("lockfile <имя_файла> [-h] [-s] [-i] [-b n] [-e n]\n\
				<имя_файла> -имя файла для обработки\n\
				[-h] - показать справку по данной утилите\n\
				[-s] - показать размер файла в байтах\n\
				[-i] – вывести информацию о файле\n\
				[-b n] – заблокировать n% содержимого файла в начале файла\n\
				[-e n] – заблокировать n% содержимого файла в конце файла\n");
	} else if (strcmp(argv[2], "-s") == 0) {
		printf("File size: %i byte\n", (int)info->nFileSizeLow);
	} else if (strcmp(argv[2], "-i") == 0) {
		SYSTEMTIME time;
		FileTimeToSystemTime(&info->ftLastWriteTime, &time);
		printf("Date of last modification: %i.%i.%i %i:%i\n", time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute);
		cout << "Serial number of tome: " << info->dwVolumeSerialNumber << endl;
		cout << "Number of file links: " << info->nNumberOfLinks << endl;

	} else if (strcmp(argv[2], "-b") == 0) {
		if (argv[3] == NULL) {
			printf("Please input percent of block file!");
			return 0;
		}
		DWORD percent = ((int)info->nFileSizeLow * atoi(argv[3])) / 100;
		LockFile(hFile, 0, 0, percent, 0);
	} else if (strcmp(argv[2], "-e") == 0) {
		if (argv[3] == NULL) {
			printf("Please input percent of block file!");
			return 0;
		}
		DWORD position = ((int)info->nFileSizeLow * atoi(argv[3])) / 100;
		DWORD start = (int)info->nFileSizeLow - position;
		LockFile(hFile, start, 0, position, 0);

	}

	CloseHandle(hFile);
	return 0;
}