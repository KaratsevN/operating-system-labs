//
// Created by main on 09.09.2019.
//
#include <sys/types.h>
#include <unistd.h>
#include <iostream>


int main() {
    uid_t uid = getuid();
    gid_t gid = getgid();
    pid_t pid = getpid();
    pid_t ppid = getppid();
    std::cout << "User id: " << uid << std::endl;
    std::cout << "Group id:" << gid << std::endl;
    std::cout << "PID: " << pid << std::endl;
    std::cout << "PPID(parents):" << ppid << std::endl;
    return 0;
}