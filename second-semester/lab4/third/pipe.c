// C program to demonstrate use of fork() and pipe() 
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
  
int main(int argc, char *argv[]) {
    int fd1[2];
    int fd2[2];
    char string[100];
    pid_t p; 
  
    if (pipe(fd1)==-1) { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    }

    if (pipe(fd2)==-1) { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    }

    p = fork(); 
  
    if (p < 0) { 
        fprintf(stderr, "fork Failed" ); 
        return 1; 
    } 
    //parent process
    else if (p > 0) {
        close(fd1[0]);
        write(fd1[1], argv[1], strlen(argv[1])); 
        close(fd1[1]);
        printf("Parent wrote\n");
 
        wait(NULL); 
  
        close(fd2[1]); 
        read(fd2[0], string, 100); 
        printf("Parent string: %s\n", string); 
        close(fd2[0]);
    } 
    // child process 
    else {
        char child_string[100]; 
        close(fd1[1]);

        read(fd1[0], child_string, 100);
        printf("Child string: %s\n", child_string);

        close(fd1[0]); 
        close(fd2[0]); 

        write(fd2[1], child_string, strlen(child_string)); 
        printf("Child wrote\n");
        close(fd2[1]);
        exit(0); 
    } 
} 