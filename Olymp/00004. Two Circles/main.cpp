#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
//https://www.eolymp.com/uk/problems/4
int main()
{
    //Две окружности
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (x1 == x2 && y1 == y2 && r1 == r2)
        cout << "-1";
    else if (((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) > (r1 + r2) * (r1 + r2)
        || ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) < (r1 - r2) * (r1 - r2))
        cout << "0";
    else if (((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) == (r1 + r2) * (r1 + r2)
        || ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) == (r1 - r2) * (r1 - r2))
        cout << "1";
    else
        cout << "2";
}