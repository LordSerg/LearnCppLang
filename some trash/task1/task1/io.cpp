#include <iostream>
int readNumber()
{
	std::cout << "Input integer: ";
	int a;
	std::cin >> a;
	return a;
}
void writeAnswer(int chislo)
{
	std::cout << "Sum of those two numbers is " << chislo << std::endl;
}