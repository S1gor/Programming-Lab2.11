#include<iostream>
#include<string.h>

//ЗАДАНИЕ:
//1.Определить, сколько раз в тексте встречается заданная буква.
//10.Выяснить, верно ли, что каждое слово, не являющее палиндромом, имеет четную длину.
//19.Даны два слова.Найти только те символы слов, которые встречаются в обоих словах только один раз.

int askUserNumberTask()
{
	int choice;
	do {
		printf("Введите номер задания (1, 10, 19):\nВыбор:"); scanf_s("%d%*c", &choice);
	} while (choice != 1 && choice != 10 && choice != 19);
	return choice;
}

char choiceLetter()
{
	char let;
	printf("Введите букву:\n");
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
		printf("Введите строку:\n"); gets_s(str);
		char letter = choiceLetter();

		int counter = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (strstr(str, "и"))
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