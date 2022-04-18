/*
* Student Name: Yousef Khodroj
* Student ID: 12113351
*/


#include <iostream>

using namespace std;

int length(const char first[]);
int substring(char dest[], const char src[], int start, int noOfChar);
int append(char dest[], const char src[]);
int copy(char dest[], const char src[]);
int at(char src[], int index, char & ch);
int find(const char src[], char ch);

void emptying(char arr[]);

int main() 
{
	char first[100] = {NULL}, second[100] = { NULL }, third[100] = { NULL };
	int len, end, ok;
	char ch = 'a';
	cout << "Enter a string: \n";
	gets_s(first);
	
	len = length(first); 
	end = len / 2;
	ok = substring(second, first, 0, end); 
	ok = substring(third, first, end + 1, len - 1); 

	append(third, second); 
	copy(first, third);
	cout << "\nNew version of string: ";
	cout << endl << first << endl << endl;
	ok = at(first, 3, ch); 
	
	if (ok)
		cout << "The 4th char of the new string is " << ch << endl;
	else
		cout << "The new string has less than 4 char\n";
	ok = find(first, 'a');
	if (ok != -1)
		cout << "The first place a was found is loc " << ok << endl;
	else
		cout << "There was no a in the new string\n";
}

int length(const char first[])
{
	int size = 0;
	for (size; first[size]; size++);
	return size;
}

int substring(char dest[], const char src[], int start, int noOfChar) // check finish
{
	if ((start + noOfChar) < 99) // to be sure of having null at least on last character
	{
		emptying(dest);
		
		int index;

		for (index = 0; noOfChar > 0; start++, index++, noOfChar--)
		{
			dest[index] = src[start];
		}

		return 1;
	}
	
	return 0;
}

int append(char dest[],const char src[])
{
	int startIndex = length(dest);

	if ((startIndex + length(src)) < 99) 
	{
		int srcIndex = 0;
		for (; src[srcIndex]; srcIndex++, startIndex++)
		{
			dest[startIndex] = src[srcIndex];
		}
		dest[startIndex] = '\0';
		return 1;
	}

	return 0;
}

int copy(char dest[], const char src[])
{
	emptying(dest);

	int counter;
	for (counter = 0; src[counter]; counter++)
	{
		dest[counter] = src[counter];
	}

	dest[counter] = '\0';
	
	return 0;
}

int at(char src[], int index, char & ch)
{
	if ((length(src) - 1) >= index) {
		ch = src[index];
		return 1;
	}

	return 0;
}

int find(const char src[], char ch)
{
	for (int counter = 0; src[counter]; counter++)
	{
		if (src[counter] == ch) return counter;
	}
	return -1;
}

void emptying(char arr[])
{
	for (int i = 0; arr[i]; i++)
	{
		arr[i] = NULL;
	}
}
