#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
//https://www.eolymp.com/uk/problems/27
int main()
{
    //Циклические сдвиги
    int n, m, l = 0;
    bool d[100];
    bool h = false;
    cin >> n;
    m = n;
    while (true)
    {
        d[l] = n % 2;
        if (d[l] == 0)
            h = true;
        n /= 2;
        l++;
        if (n < 2)
        {
            d[l] = n;
            if (d[l] == 0)
                h = true;
            l++;
            break;
        }
    }
    if(h)
    {
        int j,max=0,t,it;
        for (int i = l - 1; i >= 0; i--)
        {
            j = i;
            t = 0;
            it = l - 1;
            do
            {
                t += d[j] * pow(2,it);
                j--;
                it--;
                if (j < 0)
                    j = l - 1;
            } while (i != j);
            if (t > max)
                max = t;
        }
        m = max;
    }
    cout << m;
    return 0;   
}