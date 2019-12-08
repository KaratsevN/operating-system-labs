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
    int fd;
    const char name[11] = "fifofile";

    (void)umask(0);

    if (mknod(name, S_IFIFO | 0666, 0) < 0)
    {
        printf("Can\'t create FIFO file");
        _exit(1);
    }

    if ((fd = open(name, O_WRONLY)) < 0)
    {
        printf("Can\'t open FIFO file");
        _exit(1);
    }
    
    write(fd, argv[1], strlen(argv[1]));
    
    close(fd);
    return 0;
}