#include <iostream>
#include <string>
#include <unordered_map>
/*Given a roman numeral, convert it to an integer.

I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

*/

int romanToInt(std::string s) 
{
    std::unordered_map <std::string,int> r_to_i {{"I",1},
                                                 {"IV",4},
                                                 {"V",5},
                                                 {"IX",9},
                                                 {"X",10},
                                                 {"XL",40},
                                                 {"L",50},
                                                 {"XC",90},
                                                 {"C",100},
                                                 {"CD",400},
                                                 {"D",500},
                                                 {"CM",900},
                                                 {"M",1000}};
    
    int answer{};
    for(int i{};i<s.size();++i)
    {
        if(i+1<s.size()&&r_to_i[s.substr(i,2)]!=0)
        {
            answer+=r_to_i[s.substr(i,2)];
            ++i;
        }
        else
            answer+=r_to_i[s.substr(i,1)];
    }
    return answer;
}

int main()
{
    std::cout<<"CC to int is "<<romanToInt("CC")<<std::endl;
    return 0;
}