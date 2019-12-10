#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argv[1] == NULL) { 
		printf("Argument required!");
		return 0;
	}
	DeleteFile(argv[1]);
	return 0;
}