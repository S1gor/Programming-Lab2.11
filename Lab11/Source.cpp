#include<iostream>
#include<string.h>

//�������:
//1.����������, ������� ��� � ������ ����������� �������� �����.
//10.��������, ����� ��, ��� ������ �����, �� �������� �����������, ����� ������ �����.
//19.���� ��� �����.����� ������ �� ������� ����, ������� ����������� � ����� ������ ������ ���� ���.

int askUserNumberTask()
{
	int choice;
	do {
		printf("������� ����� ������� (1, 10, 19):\n�����:"); scanf_s("%d%*c", &choice);
	} while (choice != 1 && choice != 10 && choice != 19);
	return choice;
}

int main()
{
	system("chcp 1251"); system("cls");

	switch (askUserNumberTask())
	{
	case 1:
	{
		char str[256];
		printf("������� ������:\n"); gets_s(str);

		char* search_char = (char*)memchr(str, '�', strlen(str));
		break;
	}
	case 10:
	{

		break;
	}
	case 19:
	{

		break;
	}
	}



	return 0;
}