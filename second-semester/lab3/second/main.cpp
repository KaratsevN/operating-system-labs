#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid, ppid;
    int a = 0;
    pid = fork();
    if (pid == -1 || argv[1] == NULL || argv[2] == NULL){
        cout << "Error!";
    }
    else if (pid == 0) {
        cout << endl;
        pid = getpid();
        ppid = getppid();
        for (double x = 0; x <= 1; x+=atof(argv[2])) {
            if (x > 0.5) { exit(0); }
            cout << "PID: " << pid << " PPID: " << ppid << " ctg(" << x << ") = " << 1/tan(x)<< endl;
        }
    }
    else {
        pid = getpid();
        ppid = getppid();
        for (double x = 0; x <= 1; x+=atof(argv[1])) {
            if (x > 0.5) { exit(0); }
            cout << "PID: " << pid << " PPID: " << ppid << " tg(" << x << ") = " << tan(x)<< endl;
        }
    }

    return 0;
}
 