#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
//#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fd[2];
    int fdd[2];
    char s[5];
    int m = 0;
    int result;

    if (pipe(fd) < 0) {
        printf("ERROR");
        _exit(-1);
    }

    if (pipe(fdd) < 0) {
        printf("ERROR");
        _exit(-1);
    }
    
    int stat_val;
    pid_t child_pid;
    result = fork();

    if (result < 0) {
        printf("Can\'t create child process");
        _exit(-1);
    } else if (result > 0) {
        close(fd[0]);
        write(fd[1], argv[1], strlen(argv[1]));
        printf("Parent Writing \n");
        close(fd[1]);

        child_pid = wait(&stat_val);
        
        if (WIFEXITED(stat_val)) {
            printf("Parent Printing: ");
            close(fdd[1]);
            int k = 0;
            while ((k = read(fdd[0], s, 5)) == 5)
            {
                printf("%s", s);
                memset(s, 0, sizeof(s));
            };
            if (k < 5)
            {
                printf("%s", s);
            }
            printf("\n");
            close(fdd[0]);
        }
    } else {
        printf("Child Writing: ");
        close(fd[1]);
        int k = 0;
        while ((k = read(fd[0], s, 5)) == 5)
        {
            close(fdd[0]);
            write(fdd[1], s, 5);

            printf("%s", s);
            memset(s, 0, sizeof(s));
        };
        if (k < 5)
        {
            write(fdd[1], s, 5);
            printf("%s", s);
        }
        close(fd[0]);
        close(fdd[1]);

        printf("\n");
    }

    return 0;
}
