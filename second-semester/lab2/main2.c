//
// Created by main on 04.11.2019.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <zconf.h>
#include <sys/mman.h>

int open_file();

int main(int argc, char *argv[]) {
    struct db{
        int id;
        char firstname[30];
        char lastname[30];
        char lastlastname[30];
        int birth;
    };
    struct db data[10];
    struct db *ptr = &data;
    struct db *currptr = &data;
    void *src;
    int fd = open_file();
    int length = 10*sizeof(struct db);
    int button = -1;
    int idcount = 0;
    int id;
    char name[30];
    char lastname[30];
    char lastlastname[30];
    int birth;
    /* fuck off like command pattern style
    typedef int (*f)();*/

    close(fd);
    ptr = mmap(NULL, length, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

    currptr = ptr;

    printf("Choose operation: 1 -\n");
    while(button != 0) {
        scanf("%i", &button);
        switch (button) {
            case 1:
                printf("Write name: ");
                scanf("%s", name);
                printf("Write lastname: ");
                scanf("%s", lastname);
                printf("Write lastlastname: ");
                scanf("%s", lastlastname);
                printf("Write birth: ");
                scanf("%i", &birth);
                while(birth < 1900 || birth > 2014){
                    printf("Write birth: ");
                    scanf("%s", birth);
                }
                if(idcount == 0){
                    currptr ->id = 0;
                } else {
                    currptr -> id = idcount;
                    currptr++;
                }
                strncpy(currptr->firstname, name, 30);
                strncpy(currptr->lastname, lastname, 30);
                strncpy(currptr->lastlastname, lastlastname, 30);
                currptr -> birth = birth;
                idcount++;
                currptr++;
                break;


        }
    }

    munmap((void *)ptr, length);
    return 0;
}

int open_file() {
    int fdescr = open("db.txt", O_RDWR | O_CREAT, 0666);
    if(fdescr ==-1){
        printf("Can't open or create file!\n");
        _exit(2);
    }
    return fdescr;
}
