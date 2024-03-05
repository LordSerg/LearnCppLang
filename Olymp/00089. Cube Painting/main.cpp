#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
//https://www.eolymp.com/uk/problems/89
int main()
{
    //Раскраска кубиков
    int n;//кол-во тестов
    int k;//кол-во кубиков
    int r=0;
    char x[100];
    cin >> n;
    int answ[201];
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        answ[i] = 6 * k;
        for (int j = 0; j < k; j++)
        {
            cin.getline(x, 100);
            while(x[0]=='\0')
                cin.getline(x, 100);
            r = 0;
            while (x[r] != '0' && x[r] != '\0')
            {
                if (x[r] > '0' && x[r] <= '9')
                {
                    answ[i]--;
                    r++;
                    while (x[r]!=' ')
                    {
                        r++;
                    }
                }
                r++;
            }
            answ[i]++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << answ[i] << endl;
    return 0;
}