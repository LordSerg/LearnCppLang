#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
//https://www.eolymp.com/uk/problems/75
int main()
{
    //пираты и монеты
    int a;//кол-во монет, которые взял первый пират
    int m;//кол-во монет
    cin >> a >> m;
    int n;//кол-во пиратов
    n = ((-1)*(2 * a + 1) + sqrt((2 * a - 1) * (2 * a - 1) + 8 + 8 * m)) / 2;
    cout << n;
    return 0;
}