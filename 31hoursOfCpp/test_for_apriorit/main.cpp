#include <iostream>
#include <vector>
using namespace  std;

/*
bool searchMatrix(vector<vector<int>>& m, int t)
{
    //оскільки нам точно відомо, що на вході прямокутна сітка:
    size_t width{m[0].size()};
    size_t height{m.size()};
    size_t y{0};//індекси для пошуку
    size_t x{width-1};
    //йдемо з верхнього правого кутку і порівнюємо поточне значення з шуканим
    while (y < height && x >= 0) {
        if (m[y][x] == t) //якщо дорівнює - то знайшли
        {
            return true;
        }
        else if (m[y][x] > t) //якщо шукане значення менше - то йдемо у сторону зменшення (ліворуч)
        {
            --x;
        }
        else //якщо шукане значення більше - то йдемо у сторону збільшення (вниз)
        {
            ++y;
        }
    }
    //впринципі, можна було починати і з нижнього лівого кутку
    //головне, щоб в одному з напрямків було все за зростанням,
    //а в іншому - за спаданням

    //часова складність:
    //оскільки ми рухаємось по горизонталі, або по вертикалі, то, відповідні
    //максимальні пройдені відстані = ширині/висоті вхіднгої сітки
    //а отже максимальна кількість дій - це пройтися повністю вшир і вздовж сітки =>
    //=> O(m + n) (де m і n це відповідно ширина та довжина сітки)
    return false;
}
*/
#include <bits/stdc++.h> 
bool cmpInt(std::pair<int, int> i1, std::pair<int, int> i2) 
{ 
    return (i1.first > i2.first); 
} 
std::vector<int> find_pa_times(const std::vector<std::pair<int, int>>& classes)
{
    vector<int> ans;
    auto p=classes;
    std::sort(p.begin(),p.end(),cmpInt);
    for (auto x : p) 
        cout << "[" << x.first << ", " << x.second << "] "; 

    //ідея в тому, щоб відсортувати пари за часом кінця;
    //потім передивляємось, який з класів закінчується раніше
    //там і робимо оголос
    //і всі класи, які попали під оголос видаляються з "p"

    //ans.push_back(std::pair<int, int>{1,1});
    return { vector<int>{}};
}
int main()
{
    /*vector<vector<int>> m {
        {10	,12,	13	,21,	32	,34,	43	,51,	67	,69,	90	,101,	133},
        {16	,21,	23	,26,	40	,54,	65	,67,	68	,71,	99	,110,	150},
        {21	,23,	31	,33,	54	,58,	74	,77,	97	,98	,110	,111,	150},
        {32	,46,	59	,65,	74	,88,	99	,103	,113	,125	,137	,149,	159},
        {53	,75,	96	,115	,124	,131	,132	,136	,140	,156	,156	,157,	161},
        {84	,86,	98	,145	,146	,151	,173	,187	,192	,205	,206	,208,	219},
        {135	,141	,153	,165	,174	,181	,194	,208	,210	,223	,236	,249,	258},
        {216	,220	,222	,225	,234	,301	,355	,409	,418	,446	,454	,460,	541}
    };
    cout<<""<<searchMatrix(m,132);
    */
    
}