// ConsoleApplicatio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
int* A;
int Q(int i)
{
	int x = 1, j = i;
	while (j % 2 == 0)
	{
		x++;
		j /= 2;
	}
	return x;
}
void PrintA(int n)
{
	for (int i = 0; i < n; i++)
		cout<<A[i]<<" ";
	cout << endl;
}
void sh1(char str[])
{
	cout << str << endl;
}
void sh2(char *str)
{
	cout << str << endl;
}
void sh3(char (&str)[100])
{
	cout << str << endl;
}
int main()
{
	
	/*
	setlocale(LC_ALL, "rus");
	char str[] = "бла - бла - бла";
	sh1(str);
	sh2(str);
	char str2[100] = "бла - бла - бла";
	sh3(str2);
	//Алгоритм Грея:
	int n,p;
	cout << "n = ";
	cin >> n;
	A = new int[n];
	for (int i = 0; i < n; i++)
		A[i] = 0;
	PrintA(n);
	for (int i = 1; i < pow(2,n); i++)
	{
		p = Q(i);
		A[p - 1] = 1 - A[p - 1];
		PrintA(n);
	}
	//


	const int N = 10;
	int k = 1;
	int a[N][N];
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < N - i-1; j++)
		{
			k *= a[i][j];
		}
	}*/
	char str[256];
	char s[100];
	cout << "Str: ";
	cin.getline(str, 256);
	cout << "S: ";
	cin.getline(s, 100);
	string buf[20];
	string bufs[20];
	char* pch = strtok(str, " ");
	int index = 0, ind = 0;
	while (pch != NULL)
	{
		buf[index] = pch;
		cout << pch << " ";
		pch = strtok(NULL, " ");
		index++;
	}
	cout << "\n";
	char* pchs = strtok(s, " ");
	while(pchs!=NULL)
	{
		bufs[ind] = pchs;
		cout << pchs << " ";
		pchs = strtok(NULL, "");
		ind++;
	}
	return 0;
}
