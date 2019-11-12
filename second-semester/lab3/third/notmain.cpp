#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[], char *envp[]) {
    cout << "PID текущего процесса: " << getpid() << " PPID текущего процесса: " << getppid() << endl;
    execv("2", argv);
    return 0;
}