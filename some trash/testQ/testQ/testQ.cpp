#include <iostream>
using namespace std;
int f(string a, string b)
{
	return (a+b).length()>120;
}
int main() 
{
	int8_t a = 200;
	uint8_t b = 100;
	if (a > b)
		std::cout << "gr";
	else
		std::cout << "ls";
}