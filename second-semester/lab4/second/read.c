#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char buffer[100] = "";
    int fd;
    const char name[11] = "fifofile";

    if ((fd = open(name, O_RDONLY)) < 0)
    {
        printf("Can\'t open FIFO file");
        unlink(name);
        _exit(1);
    }

    read(fd, buffer, sizeof(buffer));
    printf("%s\n", buffer);
   
    unlink(name);
    close(fd);
    return 0;
}
