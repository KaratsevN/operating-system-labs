#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
//#include <io.h>
#include <stdlib.h>
int main(int argc, char **argv){
    
    int fd;

    if ((fd = open("myfile.txt", O_RDONLY)) < 0) {
        printf("Can\'t open file\n");
        _exit(-1);
    }

    int size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET); 
    char *buffer = (char*) malloc(sizeof(char) * size);
    // = malloc(size);
    read(fd, buffer, size);
    printf("%s", buffer);

    if(close(fd) < 0) {
        printf("Can\'t close file\n");
    }

    return 0;
}