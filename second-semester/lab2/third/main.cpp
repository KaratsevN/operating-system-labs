#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <ctime>

void listing(const char* path) {
	DIR *d = opendir(path);
	struct dirent* p;
	int len;
	
	std::string line;

	while (p=readdir(d)) {
		line = "";
		char *buf;
	        struct tm *tm_ptr;
		char *timebuf = (char*)malloc(20);
		len = strlen(path) + strlen(p->d_name) + 2;
		
		buf = (char *)malloc(len);
		if (buf) {
			struct stat statbuf;

			snprintf(buf, len, "%s/%s", path, p->d_name);
			stat(buf, &statbuf);
			// права
			if (statbuf.st_mode & S_IWRITE) {line += "w";}
			if (statbuf.st_mode & S_IREAD) {line += "r";}
			if (S_ISDIR(statbuf.st_mode)) {line += "d";}
			if (S_ISLNK(statbuf.st_mode)) {line += "l";}
			if (S_ISREG(statbuf.st_mode)) {line += "'reg'";}
			if (S_ISCHR(statbuf.st_mode)) {line += "c";}
			if (S_ISBLK(statbuf.st_mode)) {line += "b";}
			if (S_ISFIFO(statbuf.st_mode)) {line += "f";}
			if (S_ISSOCK(statbuf.st_mode)) {line += "s";}
			// user and group id
			line +="\t\t";
			line += (int)statbuf.st_uid;
			line += "\t" + (int)statbuf.st_gid;
			// time
			std::cout << line;
			tm_ptr = gmtime(&statbuf.st_mtime);
			printf("%02d/%02d ", tm_ptr->tm_mon+1, tm_ptr->tm_mday);
			printf("%02d:%02d:%02d ",tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
			//strftime(timebuf, 20, "%b %d %H:%M", ptm);
			// size , name
			std::cout << (statbuf.st_size)/(1024) << "Kb " ;
			//std::cout<< p->d_name << std::endl;
			line = "";
			//line += (int)(statbuf.st_size)/(1024) + "Kb ";
			line += p->d_name;
			line += "\n";
			std::cout << line;


		}
		free(buf);
		free(timebuf);

	}
}


int main(int argc, char *argv[]) {
	char* path = argv[1];
	if (argv[1]!=NULL){ listing(path); }
	else { listing("."); }
	return 0;
}
