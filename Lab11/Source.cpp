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

char choiceLetter()
{
	char let;
	printf("������� �����:\n");
	scanf_s("%c", &let);
	return let;
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
		char letter = choiceLetter();

		int counter = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (strstr(str, "�"))
				counter++;
		}
		printf("%d", counter);

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