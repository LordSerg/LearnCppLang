// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;
int main()
{
	setlocale(0, "russian");
	int age, growth;
	cout << "Input your age";
	cin >> age;
	//printf(age);
	cout << "Input your growth";
	cin >> growth;
	if (age < 18)
		cout << "You are a child";
	else if (age < 60)
		cout << "You are ";
	system("pause");
    return 0;
}

