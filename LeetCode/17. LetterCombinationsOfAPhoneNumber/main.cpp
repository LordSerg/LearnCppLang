#include <iostream>
#include <string>
#include <vector>
#include <map>
/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

2 -> a|b|c
3 -> d|e|f
4 -> g|h|i
5 -> j|k|l
6 -> m|n|o
7 -> p|q|r|s
8 -> t|u|v
9 -> w|x|y|z


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

std::vector<std::string> letterCombinations(std::string digits) 
{
    if(digits.size()==0)
        return std::vector<std::string>();
    
    //map of digits
    std::map<int,std::vector<std::string>> mp={{2 , std::vector<std::string>{"a","b","c"}},
                                               {3 , std::vector<std::string>{"d","e","f"}},
                                               {4 , std::vector<std::string>{"g","h","i"}},
                                               {5 , std::vector<std::string>{"j","k","l"}},
                                               {6 , std::vector<std::string>{"m","n","o"}},
                                               {7 , std::vector<std::string>{"p","q","r","s"}},
                                               {8 , std::vector<std::string>{"t","u","v"}},
                                               {9 , std::vector<std::string>{"w","x","y","z"}}};
    std::vector<std::string> answer;
    if(digits.size()==1)
    {
        return mp[atoi(digits.c_str())];
    }
    else if(digits.size()==2)
    {
        auto a = mp[digits[0]-'0'];
        auto b = mp[digits[1]-'0'];
        for(auto i : a)
            for(auto j:b)
                answer.push_back(i+j);
    }
    else if(digits.size()==3)
    {
        auto a = mp[digits[0]-'0'];
        auto b = mp[digits[1]-'0'];
        auto c = mp[digits[2]-'0'];
        for(auto i : a)
            for(auto j:b)
                for(auto k:c)
                    answer.push_back(i+j+k);
    }
    else if(digits.size()==4)
    {
        auto a = mp[digits[0]-'0'];
        auto b = mp[digits[1]-'0'];
        auto c = mp[digits[2]-'0'];
        auto d = mp[digits[3]-'0'];
        for(auto i : a)
            for(auto j:b)
                for(auto k:c)
                    for(auto l:d)
                        answer.push_back(i+j+k+l);
    }
    return answer;
}
int main()
{
    auto ans = letterCombinations("92");
    for(auto k :ans)
    {
        std:: cout<<k<<" ";
    }
    return 0;
}