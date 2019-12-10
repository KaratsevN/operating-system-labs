#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	char yesorno = NULL;
	if (argv[1] == NULL || argv[2] == NULL) {
		printf("Please input 2 arguments!");
		return 0;
	}
	if (!CopyFile(argv[1], argv[2], true)) {
		printf("This file is already exist. Continue? y/n : ");
		scanf("%c", &yesorno);
		if (yesorno == 'y') {
			CopyFile(argv[1], argv[2], false);
		} else {
			printf("File don't copy((");
		}
	}
	return 0;
}