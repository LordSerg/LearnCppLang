#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
//easy problems level
int convToArab(char ch)
{
    if (ch == 'I')
        return 1;
    else if (ch == 'V')
        return 5;
    else if (ch == 'X')
        return 10;
    else if (ch == 'L')
        return 50;
    else if (ch == 'C')
        return 100;
    else if (ch == 'D')
        return 500;
    else if (ch == 'M')
        return 1000;
}
int main()
{
    //Римские числа
    char a[100];
    cin.getline(a,100);
    while (a[0] == '\0')
        cin.getline(a, 100);
    int i = 0, x = 0, y = 0;
    bool f = false;
    while (a[i]!='\0')
    {
        if (a[i] == '+')
        {
            f = true;
        }
        else if (!f)
        {//приращение первого числа
            if (x != 0)
            {
                if (convToArab(a[i - 1]) < convToArab(a[i]))
                    x = (x - convToArab(a[i - 1])) + (convToArab(a[i]) - convToArab(a[i - 1]));//convToArab(a[i]) - x;//???
                else
                    x += convToArab(a[i]);
            }
            else
            {
                x += convToArab(a[i]);
            }
        }
        else
        {//приращение второго числа
            if (y != 0)
            {
                if (convToArab(a[i - 1]) < convToArab(a[i]))
                    y = (y - convToArab(a[i - 1])) + (convToArab(a[i]) - convToArab(a[i - 1]));//convToArab(a[i]) - x;//???
                else
                    y += convToArab(a[i]);
            }
            else
            {
                y += convToArab(a[i]);
            }
        }
        i++;
    }
    x += y;
    while (x > 0)
    {
        if (x / 1000 > 0)
        {
            cout << "M";
            x -= 1000;
        }
        else if (x / 100 == 9)
        {
            cout << "CM";
            x -= 900;
        }
        else if (x / 100 == 4)
        {
            cout << "CD";
            x -= 400;
        }
        else if (x / 500 > 0)
        {
            cout << "D";
            x -= 500;
        }
        else if (x / 10 == 9)
        {
            cout << "XC";
            x -= 90;
        }
        else if (x / 10 == 4)
        {
            cout << "XL";
            x -= 40;
        }
        else if (x / 100 > 0)
        {
            cout << "C";
            x -= 100;
        }
        else if (x / 50 > 0)
        {
            cout << "L";
            x -= 50;
        }
        else if (x==9)
        {
            cout << "IX";
            x -= 9;
        }
        else if (x == 4)
        {
            cout << "IV";
            x -= 4;
        }
        else if (x / 10 > 0)
        {
            cout << "X";
            x -= 10;
        }
        else if (x / 5 > 0)
        {
            cout << "V";
            x -= 5;
        }
        else
        {
            cout << "I";
            x--;
        }
    }
    return 0;    
}