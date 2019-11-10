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

struct A
{
	int key;
	int birthYear;
	char firstName[20];
	char lastName[20];
	char lastLastName[20];
} * ptr, *tmpptr, *superTmpPtr;

struct A *Finding(struct A *ptr, struct A *endptr, int key)
{
	struct A *tmpptr = ptr;

	return tmpptr;
}

void print(struct A *ptr, struct A *endptr);

int main()
{
	int fd;		   /* Файловый дескриптор для файла, в котором будет храниться информация*/
	size_t length; /* Длина отображаемой части файла */
	int i;
	char menu, c[100];
	//O_CREAT
	fd = open("file.txt", O_RDWR, 0666);

	if (fd == -1)
	{
		/* Если файл открыть не удалось, выдаем сообщение об ошибке и завершаем работу */
		printf("File open failed!\n");
		exit(1);
	}

	length = 2 * sizeof(struct A);
	ftruncate(fd, length);
	ptr = (struct A *)mmap(0, length,  PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);

	if (ptr == MAP_FAILED)
	{
		printf("Mapping failed!\n");
		exit(2);
	}

	tmpptr = ptr;

	while (tmpptr->key != NULL)
	{
		tmpptr++;
	}

	print(ptr, tmpptr);
	cout << "\n\n";

	while (menu != '4')
	{
		print(ptr, tmpptr);
		cout << "Меню:"
			 << "\n\t1.Вывод записей с заданным ключом"
			 << "\n\t2.Вывод записей с одинаковым значением полей"
			 << "\n\t3.Вывод записей с значением года рождения в заданном диапазоне"
			 << "\n\t4.Выход."
			 << "\nВвод: ";
		cin >> menu;
		switch (menu)
		{
		case '1':
		{
			int k;
			cout << "Введите ключ записи: ";
			cin >> k;
			cout << "Ключ"
				 << "\t\tФамилия"
				 << "\t\tИмя"
				 << "\t\tОтчество"
				 << "\tГод\n";
			struct A *tmpptr1 = ptr;
			while (tmpptr1 != tmpptr)
			{
				if (tmpptr1->key == k)
				{
					cout << tmpptr1->lastName << " " << tmpptr1->firstName << " " << tmpptr1->lastLastName
						 << " " << tmpptr1->birthYear << "  " << tmpptr1->key << "\n";
				}
				tmpptr1++;
			}
			break;
		}
		case '2':
		{
			int flag = 0;
			cout << "Ключ"
				 << "\t\tФамилия"
				 << "\t\tИмя"
				 << "\t\tОтчество"
				 << "\tГод\n";
			for (struct A *currPtr = ptr; currPtr != tmpptr; currPtr++)
			{
				for (struct A *superTmpPtr1 = (currPtr + 1); superTmpPtr1 < tmpptr; superTmpPtr1++)
				{
					if (((currPtr->key) == (superTmpPtr1->key)) && (strcmp(currPtr->firstName, superTmpPtr1->firstName) == 0) && (strcmp(currPtr->lastLastName, superTmpPtr1->lastLastName) == 0) && ((currPtr->birthYear) == (superTmpPtr1->birthYear)) && (strcmp(currPtr->lastName, superTmpPtr1->lastName) == 0))
					{
						if (flag == 0)
						{
							cout << currPtr->lastName << " " << currPtr->firstName << " " << currPtr->lastLastName
								 << " " << currPtr->birthYear << "  " << currPtr->key << "\n";
							cout << superTmpPtr1->lastName << " " << superTmpPtr1->firstName << " " << superTmpPtr1->lastLastName
								 << " " << superTmpPtr1->birthYear << "  " << superTmpPtr1->key << "\n";
							flag = 1;
						}
						else
						{
							cout << superTmpPtr1->lastName << " " << superTmpPtr1->firstName << " " << superTmpPtr1->lastLastName
								 << " " << superTmpPtr1->birthYear << "  " << superTmpPtr1->key << "\n";
						}
					}
				}
				flag = 0;
			}
			break;
		}

		case '3':{
			int left, right, i = 0;
			cout << "Введите левую границу диапазона: ";
			cin >> left;
			cout << "Введите правую границу диапазона: ";
			cin >> right;
			superTmpPtr = ptr;
			cout << "Ключ"
				 << "\t\tФамилия"
				 << "\t\tИмя"
				 << "\t\tОтчество"
				 << "\tГод\n";
			while (superTmpPtr != tmpptr)
			{
				if (superTmpPtr->birthYear <= right && superTmpPtr->birthYear >= left)
				{
					cout << superTmpPtr->lastName << " " << superTmpPtr->firstName << " " << superTmpPtr->lastLastName
						 << " " << superTmpPtr->birthYear << "  " << superTmpPtr->key << "\n";
				}
				superTmpPtr++;
			}
			break;
		}

		case '4':
			break;

		default:
			break;
		}
	}
	munmap((void *)ptr, length);
	return 0;
}

void print(struct A *ptr, struct A *endptr)
{
	struct A *tmpptr = ptr;
	cout << "Ключ"
		 << "\t\tФамилия"
		 << "\t\tИмя"
		 << "\t\tОтчество"
		 << "\t\tГод\n";

	while (tmpptr != endptr)
	{
		cout << tmpptr->key
			 << "\t" << tmpptr->lastName
			 << "\t" << tmpptr->firstName
			 << "\t" << tmpptr->lastLastName
			 << "\t" << tmpptr->birthYear
			 << endl;
		tmpptr++;
	}
}