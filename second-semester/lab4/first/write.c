#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    
    int fd;
    size_t size;

    umask(0);

    if ((fd = open("myfile.txt", O_WRONLY | O_CREAT, 0666)) < 0) {
        printf("Can\'t open file\n");
        _exit(-1);
    }

    size = write(fd, argv[1], strlen(argv[1]));

    // if (size != 14){
    // /* Если записалось меньшее количество байт,
    // сообщаем об ошибке */
    // printf("Can\'t write all string\n");
    // exit(-1);
    // }

    if(close (fd) < 0) {
        printf("Can\'t close file\n");
    }

    close(fd);
    return 0;
}