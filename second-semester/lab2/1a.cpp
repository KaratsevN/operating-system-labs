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
	}*ptr, *tmpptr, *superTmpPtr;

struct A* Finding(struct A* ptr,struct A* endptr, int key){
	struct A* tmpptr = ptr;

	return tmpptr;
}

void PrintAll(struct A* ptr,struct A* endptr){
	struct A* tmpptr = ptr;
		 cout << "\n\nФамилия    Имя      Отчество  Год   Ключ\n";
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
	char ch, c[100];
	
	
	

	fd = open("file.txt", O_RDWR | O_CREAT, 0666);
	if( fd == -1) {
	/* Если файл открыть не удалось, выдаем сообщение об ошибке и завершаем работу */
		printf("File open failed!\n");
		exit(1);
	}
	length = 20*sizeof(struct A);
	ftruncate(fd,length);
	ptr = (struct A*)mmap(NULL, length, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	close(fd);
	if ( ptr == MAP_FAILED ){
/* Если отобразить файл не удалось, сообщаем об ошибке и завершаем работу */
	printf("Mapping failed!\n");
	exit(2);
	}
	tmpptr = ptr;
	while (tmpptr->key !=NULL) {tmpptr++;}
	PrintAll(ptr, tmpptr);
	cout << "\n\n";
	while(true){
		int flag = 0;
		PrintAll(ptr,tmpptr);
		cout << "Меню:\n1.Вывод записей с заданным ключом\n2.Вывод записей с одинаковым значением полей\n3.Вывод записей с значением года рождения в заданном диапазоне\n4.Выход.\nВвод: ";
		cin >> ch;

		if (ch == '4'){
				flag = 1;
				break;
		 } else if (ch == '1'){
				int k;
				cout << "Введите ключ записи: ";
				cin >> k;
				cout << "Фамилия    Имя      Отчество  Год   Ключ\n";
				struct A* tmpptr1 = ptr;
				while (tmpptr1 != tmpptr){
					if (tmpptr1->key == k) {
						cout << tmpptr1->secondName << " " << tmpptr1->firstName << " " << tmpptr1->patronyc
						<< " " << tmpptr1->birthYear << "  " << tmpptr1->key << "\n";
					}
					tmpptr1++;
				}
		} else if (ch == '2'){
				int flag = 0;
				cout << "Фамилия    Имя      Отчество  Год   Ключ\n";
				for (struct A* currPtr = ptr; currPtr != tmpptr; currPtr++){
					for (struct A* superTmpPtr1 = (currPtr+1); superTmpPtr1 < tmpptr; superTmpPtr1++){
						/*cout << currPtr->key << " "<<superTmpPtr1->key<<"||"<<currPtr->firstName<<" "<<superTmpPtr1->firstName
						<<"||"<<currPtr->patronyc<<" "<<superTmpPtr1->patronyc
						<<"||"<<currPtr->birthYear<<" "<<superTmpPtr1->birthYear<<"||"<<currPtr->secondName<<" "<<superTmpPtr1->secondName<<" ||"<<flag <<"\n\n";*/
						if ( ((currPtr->key) == (superTmpPtr1->key)) && ( strcmp(currPtr->firstName, superTmpPtr1->firstName) == 0 ) 
						&& ( strcmp(currPtr->patronyc, superTmpPtr1->patronyc) == 0 ) && ((currPtr->birthYear) == (superTmpPtr1->birthYear)) 
						&& ( strcmp(currPtr->secondName, superTmpPtr1->secondName) == 0 )) {
							if (flag == 0) {
								cout<< currPtr->secondName << " " << currPtr->firstName << " " << currPtr->patronyc
								<< " " << currPtr->birthYear << "  " << currPtr->key << "\n";
								cout<< superTmpPtr1->secondName << " " << superTmpPtr1->firstName << " " << superTmpPtr1->patronyc
								<< " " << superTmpPtr1->birthYear << "  " << superTmpPtr1->key << "\n";
								flag = 1;
							} else {
								cout<< superTmpPtr1->secondName << " " << superTmpPtr1->firstName << " " << superTmpPtr1->patronyc
								<< " " << superTmpPtr1->birthYear << "  " << superTmpPtr1->key << "\n";
							}
						}
					}
					flag = 0;
				}
		} else if (ch == '3'){
				int left, right, i=0;
				cout << "Введите левую границу диапазона: ";
				cin >> left;
				cout << "Введите правую границу диапазона: ";
				cin >> right;
				superTmpPtr = ptr;
				cout << "Фамилия    Имя      Отчество  Год   Ключ\n";
				while (superTmpPtr != tmpptr){
					if (superTmpPtr->birthYear <= right && superTmpPtr->birthYear >=left) {
						cout<< superTmpPtr->secondName << " " << superTmpPtr->firstName << " " << superTmpPtr->patronyc
						<< " " << superTmpPtr->birthYear << "  " << superTmpPtr->key << "\n";
					}
					superTmpPtr++;
				}
		} 
	}
/* Прекращаем отображать файл в память, записываем содержимое отображения на диск и
освобождаем память. */
	munmap((void *)ptr, length);
	return 0;
}
