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
            while(y <= 1){
                printf("Pid = %d, Ppid = %d, ctg(%f) = %f\n", (int)pid, (int)ppid, y, 1/tan(y));
                //printf("ctg(%f)=%f", y);
                //printf("%f\n", 1/tan(y));
                y += atof(argv[2]);
            }
//            printf(" CHILD: Это процесс-потомок!\n");
//            printf(" CHILD: Мой PID -- %d\n", getpid());
//            printf(" CHILD: PID моего родителя -- %d\n",
//                   getppid());
//            printf(" CHILD: Введите мой код возврата
//                           (как можно меньше):");
//            scanf(" %d");
//            printf(" CHILD: Выход!\n");
            exit(0);
        default:
            pid = getpid();
            ppid = getppid();
            //printf("My pid = %d, my ppid = %d\n", (int)pid, (int)ppid);
            while(x <= 1){
                printf("\tPid = %d, Ppid = %d, tg(%f) = %f\n", (int)pid, (int)ppid, x, tan(x));
//                printf("tg(%f) = %f", x);
//                printf("%f\n",tan(x));
                x += atof(argv[1]);
            }
            exit(0);
//            printf("PARENT: Это процесс-родитель!\n");
//            printf("PARENT: Мой PID -- %d\n", getpid());
//            printf("PARENT: PID моего потомка %d\n",pid);
//            printf("PARENT: Я жду, пока потомок
//            не вызовет exit()...\n");
//            wait();
//            printf("PARENT: Код возврата потомка:%d\n",
//                   WEXITSTATUS(rv));
//            printf("PARENT: Выход!\n");
    }
// Печатаем значения PID, PPID и вычисленное значение
// переменной а (в каждом из процессов)
//    printf("My pid = %d, my ppid = %d, result = %d\n",
//           (int) pid, (int) ppid, a);
    return 0;
}