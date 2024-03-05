#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
//https://www.eolymp.com/uk/problems/2
int main()
{
    //цифры
    char x[20];
    int n=0;
    cin.getline(x, 20);
    while (x[0] == '\0')
        cin.getline(x, 20);
    while (x[n] != '\0')
        n++;
    cout << n;
    return 0;   
}