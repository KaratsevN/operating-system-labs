#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <ctype.h>


using namespace std;

	struct A{
		int key;
		int birthYear;
		char firstName[20];
		char secondName[20];
		char patronyc[20];
	}*ptr, *tmpptr;

void PrintAll(struct A* ptr,struct A* endptr){
	struct A* tmpptr = ptr;
		 cout << "Фамилия    Имя      Отчество  Год   Ключ\n";
		 while (tmpptr != endptr){
			cout << tmpptr->secondName << " " << tmpptr->firstName << " " << tmpptr->patronyc
			<< " " << tmpptr->birthYear << "  " << tmpptr->key << "\n";
			tmpptr++;
		 }
	}


int main(void) {
	int fd; /* Файловый дескриптор для файла, в котором будет храниться информация*/
	size_t length; /* Длина отображаемой части файла */
	int i;
	char ch;

	fd = open("file.txt", O_RDWR | O_CREAT, 0666);
	if( fd == -1) {
	/* Если файл открыть не удалось, выдаем сообщение об ошибке и завершаем работу */
		printf("File open failed!\n");
		exit(1);
	}
	length = 100*sizeof(struct A);
	ftruncate(fd,length);
	ptr = (struct A*)mmap(NULL, length, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	close(fd);
	if ( ptr == MAP_FAILED ){
/* Если отобразить файл не удалось, сообщаем об ошибке и завершаем работу */
	printf("Mapping failed!\n");
	exit(2);
	}
	
	tmpptr = ptr;

	while(true){
		PrintAll(ptr, tmpptr);
		int flag = 0;
		cout << "Меню:\n1.Добавление\n2.Изменение поля\n3.Выход.\nВвод: ";
		cin >> ch;
		switch(ch) {
			case '3':
				flag = 1;
				break;
			case '1':
				cout << "Введите Имя: ";
				cin >> tmpptr->firstName;
				cout<< "Введите Фамилию: ";
				cin >> tmpptr->secondName;
				cout<< "Введите Отчество: ";
				cin >> tmpptr->patronyc;
				cout << "Введите ключ: ";
				cin >> tmpptr->key;
				cout << "Введите год рождения: ";
				cin >> tmpptr->birthYear;
				tmpptr++;
				break;
			case '2': 
				char symbol, s[100];
				int k;
				cout << "Введите ключ записи, которую вы хотите изменить: ";
				cin >> k;
				struct A* tmpptr1 = ptr;
				struct A* keyPtr;

				while (tmpptr1 != tmpptr) {
					if (tmpptr1->key == k) {keyPtr = tmpptr1; break;}
					tmpptr1++;				
				}


				while(true) {
					int flag1 = 0;
					cout << "Выберите поля, которые вы хотите изменить:\n1.ФИО\n2.Год рождения\n3.Ключ\n4.Закончить изменение полей\nВвод: ";
					cin >> symbol;
					switch(symbol) {
						case '1':
							cout << "Введите Имя: ";
							cin >> keyPtr->firstName;
							cout<< "Введите Фамилию: ";
							cin >> keyPtr->secondName;
							cout<< "Введите Отчество: ";
							cin >> keyPtr->patronyc;
							break;
						case '2':
							cout << "Введите год рождения: ";
							cin >> keyPtr->birthYear;
							break;
						case '3':
							cout << "Введите ключ: ";
							cin >> keyPtr->key;
							break;
						case '4':
							flag1 = 1;
							break;
					}
					if (flag1 == 1){ flag1 = 0; break; } 
				}
				break;
		}
		if (flag == 1) {break;}
	}
/* Прекращаем отображать файл в память, записываем содержимое отображения на диск и
освобождаем память. */
	munmap((void *)ptr, length);
	return 0;
}

/*void PrintAll(struct A* ptr,struct A* endptr){
	struct A* tmpptr = ptr;
		 while (tmpptr != endptr){
			cout << "Фамилия    Имя      Отчество  Год   Ключ\n" << tmpptr->secondName << " " << tmpptr->firstName << " " << tmpptr->patronyc
			<< " " << tmpptr->birthYear << "  " << tmpptr->key << "\n";
			tmpptr++;
		 }
	}*/
/*A* Finding(A* ptr, A* endptr, int key){
	A* tmpptr = ptr;
	while (tmpptr != (endptr +1)){
		if (tmpptr->key == key) {return tmpptr;}
	}
	return tmpptr;
}*/
	
