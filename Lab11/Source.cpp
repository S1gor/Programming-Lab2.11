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
char registrReplacement(char letter)
{
	if (letter != toupper(letter))
		return toupper(letter);
	else
		return tolower(letter);
}
void letterMet(char* str, char letter, char letter2)
{
	int counter = 0;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == letter || str[i] == letter2)
			counter++;
	printf("Letter '%c(%c)' met %d once.", letter, letter2, counter);
}

bool chekPalindrom(char* mas)
{
	char let;
	for (int i = 0; i < strlen(mas) / 2; i++)
	{
		let = registrReplacement(mas[i]);
		if (mas[i] != mas[strlen(mas) - i - 1] && let != mas[strlen(mas) - i - 1])
			return false;
	}
	return true;
}
void findLenAndPalindrom(char* str)
{
	printf("\n");
	char mas[20] = { 0 };

	int n = 0;
	bool flag = true;
	for (int i = 0; i < strlen(str) + 1; i++)
	{
		mas[n] = str[i];
		if (str[i] == ' ' || str[i] == '\0')
		{
			mas[n] = '\0';
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
			for (int j = 0; j < n; j++)
				mas[j] = ' ';
			n = 0;
			continue;
		}
		n++;
	}
	if (flag)
		printf("Every word that is not a palindrome has an even length\n");
}

void recurringSymbol(char* wrd1, char* wrd2, char* c)
{
	char wrd1_2;
	for (int i = 0; wrd1[i] != '\0'; i++)
	{
		wrd1_2 = registrReplacement(wrd1[i]);
		int counter = 0;
		for (int j = 0; wrd1[j] != '\0'; j++)
			if (wrd1[i] == wrd1[j] || wrd1_2 == wrd1[j])
				counter++;
		if (counter == 1)
		{
			int counter2 = 0;
			for (int k = 0; wrd2[k] != '\0'; k++)
				if (wrd1[i] == wrd2[k] || wrd1_2 == wrd2[k])
				{
					counter2++;
					c[i] = wrd1[i];
				}
			if (counter2 == 1)
				printf("%c\n", c[i]);
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
		char letter2 = registrReplacement(letter);
		
		letterMet(str, letter, letter2);
		break;
	}
	case 10:
	{
		char str[256];
		printf("Enter the line:\n"); gets_s(str);

		findLenAndPalindrom(str);
		break;
	}
	case 19:
	{
		char wrd1[17], wrd2[17], c[17];
		printf("Enter the first word: "); gets_s(wrd1);
		printf("Enter the second word: "); gets_s(wrd2);

		recurringSymbol(wrd1, wrd2, c);
		break;
	}
	}

	return 0;
}