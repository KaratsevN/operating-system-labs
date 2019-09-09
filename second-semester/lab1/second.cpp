//
// Created by main on 09.09.2019.
//

//#include <sys/types.h>
//#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[], char *envp[]) {
    for(int i = 1; i < argc; i++) {
        std::cout << i << " argument is: " << argv[i] << std::endl;
    }
    std::cout << "Total arguments: " << argc - 1 << std::endl;
    int i;
    while(envp[i] != 0){
        std::cout << envp[i] << std::endl;
        i++;
    }
    return 0;
}