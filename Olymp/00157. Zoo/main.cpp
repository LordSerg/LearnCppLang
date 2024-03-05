#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
//https://www.eolymp.com/uk/problems/157
int f(int k)
{
    if (k == 2)
        return 0;
    return f(k - 1) + 2 * (k - 2);
}
int main()
{
    //Зоопарк
    int k;//количество клеток
    int n;//количество способов рассадить мартышек
    cin >> k;
    n=f(k);
    cout << n;
    return 0;
}