#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

char* getUserName();
char* concat(char *s1, char *s2);

int main(int argc, char *argv[], char *envp[]) {
    printf("PID: %d , PPID: %d\n", getpid(), getppid());
    // NON DEANON
    char* whoami = getUserName();
    char* buffer = concat("/home/", whoami);
    buffer = concat(buffer, "/git/operating-system-labs/second-semester/lab3/second/main.out");
    execv("/git/operating-system-labs/second-semester/lab3/second/main.out", argv);
    return 0;
}

char *getUserName() {
  uid_t uid = geteuid();
  struct passwd *pw = getpwuid(uid);
  if (pw)
  {
    return pw->pw_name;
  }
  return "";

}

char* concat(char *s1, char *s2) {

        size_t len1 = strlen(s1);
        size_t len2 = strlen(s2);                      

        char *result = (char*)malloc(len1 + len2 + 1);

        if (!result) {
            fprintf(stderr, "malloc() failed: insufficient memory!\n");
            return NULL;
        }

        memcpy(result, s1, len1);
        memcpy(result + len1, s2, len2 + 1);    

        return result;
    }