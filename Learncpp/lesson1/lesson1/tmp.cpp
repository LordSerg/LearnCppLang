#include <iostream>

void printBottles(int a,int b, int flag = 0)
{
    if (flag == 0)
        std::cout << "[" << a << "," << b << "]->";
    else
        std::cout << "[" << a << "," << b << "] (" << flag<<")" << std::endl;

}
int main()
{
    int capasityA=5;
    int capasityB=3;
    int a{ 0 };//перша пляшка (на capasityA галонів)
    int b{ 0 };//друга пляшка (на capasityB налони)
    int k{ 0 };
    //задача: чи будь-яку кількість рому можна буде набрати, якщо всього є дві пляшки [capasityA,capasityB]?
    //...скількома методами
    std::cout << "there are two bottles:\n1) capasity = " << capasityA << ";\n2) capasity = " << capasityB << ";\n\n";
    //нехай максимальна ємність завжди у першої пляшки
    if(capasityB>capasityA)
    {
        capasityA += capasityB;
        capasityB = capasityA - capasityB;
        capasityA -= capasityB;
    }
    
    for (int i{1}; i <= capasityA; i++)
    {//i = скільки треба галонів рому
        //алгоритм через наповнення capasityB-галонової пляшки
        std::cout << "Make " << i<<" gallons\n";
        a = 0;
        b = 0;
        k = 0;
        while (true)
        {
            k++;
            printBottles(a, b);
            if (b == 0)
                b = capasityB;
            else if (a == capasityA)
            {
                a = 0;
            }
            else if (b > 0 && a < capasityA)
            {
                a += b;
                if (a > capasityA)
                {
                    b = a - capasityA;
                    a = capasityA;
                }
                else
                    b = 0;
            }
            if (a == i)
            {
                if (b != 0)
                {
                    k++;
                    printBottles(a, b);
                    b = 0;
                }
                printBottles(a, b, k);
                break;
            }
        }
        //алгоритм через наповнення capasityA-галонової пляшки
        a = 0;
        b = 0;
        k = 0;
        while (true)
        {
            k++;
            printBottles(a, b);
            if (a == 0)
                a = capasityA;
            else if (b == capasityB)
                b = 0;
            else if (a>0&&b<capasityB)
            {
                b += a;
                if (b > capasityB)
                {
                    a = b - capasityB;
                    b = capasityB;
                }
                else
                    a = 0;
            }
            if (a == i)
            {
                if (b != 0)
                {
                    k++;
                    printBottles(a, b);
                    b = 0;
                }
                printBottles(a, b, k);
                break;
            }
        }
    }
}