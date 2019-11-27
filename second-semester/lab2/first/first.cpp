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
	char firstName[20];
	char lastName[20];
	char lastLastName[20];
	int birthYear;

} * ptr, *tmpptr;

void printStruct(struct A *ptr, struct A *endptr);
int testBirth();

int main(void)
{
	int fd;		   /* Файловый дескриптор для файла, в котором будет храниться информация*/
	size_t length; /* Длина отображаемой части файла */
	int i;
	char menu;

	fd = open("file.txt", O_RDWR | O_CREAT, 0666);

	if (fd == -1)
	{
		printf("File open failed!\n");
		exit(1);
	}

	length = 10 * sizeof(struct A);
	ftruncate(fd, length);
	ptr = (struct A *)mmap(0, length, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	close(fd);

	if (ptr == MAP_FAILED)
	{
		printf("Mapping failed!\n");
		exit(2);
	}

	tmpptr = ptr;

	while (menu != '3')
	{
		printStruct(ptr, tmpptr);
		int flag = 0;
		int birth = 0;
		cout << "Меню:"
			 << "\n\t1.Добавление"
			 << "\n\t2.Изменение поля"
			 << "\n\t3.Выход."
			 << "\nВвод: ";
		cin >> menu;
		switch (menu)
		{
		case '1':
			cout << "Введите ключ: ";
			cin >> tmpptr->key;
			cout << "Введите Имя: ";
			cin >> tmpptr->firstName;
			cout << "Введите Фамилию: ";
			cin >> tmpptr->lastName;
			cout << "Введите Отчество: ";
			cin >> tmpptr->lastLastName;
			tmpptr->birthYear = testBirth();
			tmpptr++;
			break;
		case '2':
		{
			char symbol;
			int k;
			cout << "Введите ключ записи, которую вы хотите изменить: ";
			cin >> k;
			struct A *tmpptr1 = ptr;
			struct A *keyPtr;

			while (tmpptr1 != tmpptr)
			{
				if (tmpptr1->key == k)
				{
					keyPtr = tmpptr1;
					break;
				} else{
				tmpptr1++;
				}
			}

			while (symbol != '4')
			{
				cout << "Выберите поля, которые вы хотите изменить:"
					 << "\n\t1.Ключ"
					 << "\n\t2.ФИО"
					 << "\n\t3.Год рождения"
					 << "\n\t4.Закончить изменение полей"
					 << "\nВвод: ";
				cin >> symbol;
				switch (symbol)
				{
				case '1':
					cout << "Введите ключ: ";
					cin >> keyPtr->key;
					break;
				case '2':
					cout << "Введите Имя: ";
					cin >> keyPtr->firstName;
					cout << "Введите Фамилию: ";
					cin >> keyPtr->lastName;
					cout << "Введите Отчество: ";
					cin >> keyPtr->lastLastName;
					break;
				case '3':
					cout << "Введите год рождения: ";
					cin >> keyPtr->birthYear;
					break;
				}
			}
			break;
		}
		}
	}

	munmap((void *)ptr, length);
	return 0;
}

void printStruct(struct A *ptr, struct A *endptr)
{
	struct A *tmpptr = ptr;
	cout << "Ключ"
		 << "\t\tФамилия"
		 << "\t\tИмя"
		 << "\t\tОтчество"
		 << "\tГод\n";

	while (tmpptr != endptr)
	{
		cout << tmpptr->key
			 << "\t\t" << tmpptr->lastName
			 << "\t\t" << tmpptr->firstName
			 << "\t\t" << tmpptr->lastLastName
			 << "\t\t" << tmpptr->birthYear
			 << endl;
		tmpptr++;
	}
}

int testBirth()
{
	int birth = 0;
	while ((birth < 1900) || (birth > 2010))
	{
		cout << "Введите год рождения: ";
		cin >> birth;
	}
	return birth;
}