#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <cstdlib>
#include <sys/stat.h>

using namespace std;

int remove(string path);

int remove_lifehack(string path);

int main()
{
    int a;
    string path;

    cout << "Введите путь к директории: ";
    cin >> path;
    remove(path);
    //remove_lifehack(path);
    cout << endl
         << "Complete!";
    cin >> a;

    return 0;
}

int remove_lifehack(string path){
    //username deanone :0
    string newpath = "/home/nikita/git/operating-system-labs/second-semester/lab2/second/main.sh " + path;
    system(newpath.c_str());
}

int remove(string path){
    DIR *d = opendir(path.c_str());
    int path_len = strlen(path.c_str());
    int r = -1;

    if (d) {
        struct dirent *p;
        r = 0;
        while (!r && (p = readdir(d))) {
            int r2 = -1;
            char *buf;
            int len;
            if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, "..")) {
                continue;
            }
            len = path_len + strlen(p->d_name) + 2;
            buf = (char *)malloc(len);

            if (buf) {
                struct stat statbuf;
                snprintf(buf, len, "%s/%s", path, p->d_name);
                if (!stat(buf, &statbuf)) {
                    if (S_ISDIR(statbuf.st_mode)) {
                        r2 = remove(buf);
                    }
                    else {
                        r2 = unlink(buf);
                    }
                }
                free(buf);
            }
            r = r2;
        }
        closedir(d);
    }
    if (!r) {
        r = rmdir(path.c_str());
    }
    return r;
}