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
		printf("Enter the task number (1, 10, 19):\nChoice:"); scanf_s("%d%*c", &choice);
	} while (choice != 1 && choice != 10 && choice != 19);
	return choice;
}

char choiceLetter()
{
	char let;
	printf("Enter the letter:\n");
	scanf_s("%c", &let);
	return let;
}
void registrReplacement(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == toupper(str[i]))
			str[i] = tolower(str[i]);
}
void letterMet(char* str, char letter)
{
	int counter = 0;
	char* nmb = strchr(str, letter);
	while (nmb != NULL)
	{
		counter++;
		nmb = strchr(nmb + 1, letter);
	}
	printf("The letter '%c' met %d once!\n", letter, counter);
}

bool chekPalindrom(char* mas)
{
	int len = strlen(mas);
	for (int i = 0; i < len / 2; i++)
		if (mas[i] != mas[len - i - 1])
			return false;
	return true;
}
void findLenAndPalindrom(char* str)
{
	printf("\n");
	char mas[20] = { 0 };
	
	bool flag = true;

	char* s1 = str;
	char* s2 = strchr(str, ' ');

	while (s1 != NULL && s2 != NULL)
	{
		if (s2 - s1 <= 0)
		{
			s1 = s2 + 1;
			s2 = strchr(s2 + 1, ' ');
			continue;
		}
		strncpy_s(mas, s1, s2 - s1);

		if (chekPalindrom(mas))
			printf("%s - Palindrom\n", mas);
		else
		{
			printf("%s(%d) - No palindrom\n", mas, strlen(mas));
			if (strlen(mas) % 2 != 0)
			{
				flag = false;
				printf("Not every word that is not a palindrome has an even length.\n");
				break;

			}
		}

		s1 = s2 + 1;
		s2 = strchr(s2 + 1, ' ');
	}
	if (s2 == NULL)
	{
		strncpy_s(mas, s1, s2 - s1);
		if (chekPalindrom(mas))
			printf("%s - Palindrom\n", mas);
		else
		{
			printf("%s(%d) - No palindrom\n", mas, strlen(mas));
			if (strlen(mas) % 2 != 0)
			{
				flag = false;
				printf("Not every word that is not a palindrome has an even length.\n");
			}
		}
	}
	if (flag)
		printf("Every word that is not a palindrome has an even length.\n");
}

void recurringSymbol(char* wrd1, char* wrd2, char* c)
{
	for (int i = 0; wrd1[i] != '\0'; i++)
	{
		int counter1 = 0;
		char* nmb1 = strchr(wrd1, wrd1[i]);
		while (nmb1 != NULL)
		{
			counter1++;
			if (counter1 == 2)
				break;
			nmb1 = strchr(nmb1 + 1, wrd1[i]);
		}
		
		if (counter1 == 1)
		{
			int counter2 = 0;

			char* nmb2 = strchr(wrd2, wrd1[i]);
			while (nmb2 != NULL)
			{
				counter2++;
				if (counter2 == 2)
					break;
				nmb2 = strchr(nmb2 + 1, wrd1[i]);
			}
			if (counter2 == 1)
				printf("%c\n", wrd1[i]);
		}
	}
}

int main()
{
	switch (askUserNumberTask())
	{
	case 1:
	{
		char str[256];
		printf("Enter the line:\n"); gets_s(str);
		char letter = choiceLetter();
		
		registrReplacement(str);
		letterMet(str, letter);
		break;
	}
	case 10:
	{
		char str[256];
		printf("Enter the line:\n"); gets_s(str);

		registrReplacement(str);
		findLenAndPalindrom(str);
		break;
	}
	case 19:
	{
		char wrd1[17], wrd2[17], c[17];
		printf("Enter the first word: "); gets_s(wrd1);
		printf("Enter the second word: "); gets_s(wrd2);

		registrReplacement(wrd1); registrReplacement(wrd2);
		recurringSymbol(wrd1, wrd2, c);
		break;
	}
	}

	return 0;
}