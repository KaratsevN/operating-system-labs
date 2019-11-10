#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    pid_t pid, ppid;
    pid = fork();
    double x = 0;
    double y =0;
// При успешном создании нового процесса с этого места //псевдопараллельно начинают работать два процесса
// Узнаем идентификаторы текущего и родительского процесса // в каждом из процессов
    //pid = getpid();
    ppid = getppid();
    switch(pid) {
        case -1:
            perror("fork"); /* произошла ошибка */
            _exit(1); /*выход из родительского процесса*/
        case 0:
            while(y <= 1){
                printf("tg(%d)=%d\n",y,1/tan(y));
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
            while(x <= 1){
                printf("tg(%d)=%d\n",x,tan(x));
                x += atof(argv[1]);
            }

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