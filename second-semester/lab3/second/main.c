#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {

    pid_t pid, ppid;
    pid = fork();
    double x = 0;
    double y = 0;

    if(argv[1] == NULL || argv[2] == NULL){
        printf("Error");
        _exit(1);
    }

    //Да простит меня Тюменцев Е.А.

    switch(pid) {
        case -1:
            perror("fork");
            _exit(1);
        case 0:
            pid = getpid();
            ppid = getppid();
            while (y < 0.4999999) {
                printf("Pid = %d, Ppid = %d, ctg(%5.3f) = %f\n", (int) pid, (int) ppid, y, 1 / tan(y));
                y += atof(argv[2]);
            }
            exit(0);
        default:
            pid = getpid();
            ppid = getppid();
            while (x < 0.5) {
                printf("\tPid = %d, Ppid = %d, tg(%5.3f) = %f\n", (int) pid, (int) ppid, x, tan(x));
                x += atof(argv[1]);
            }
            exit(0);
            return 0;
    }
    //The Chemical Brothers -- Got Glint?
}