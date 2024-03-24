#include <iostream>
#include <string>
#include <vector>
/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string ""
*/
std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    std::string answer = strs[0];
    for(int i{1};i<strs.size();++i)
    {
        int j{};
        for(;j<strs[i].size();++j)
        {
            if(strs[i][j]!=answer[j])
            {
                if(j!=0)
                    break;
                else
                    return "";
                break;
            }
        }
        answer = strs[i].substr(0,j);
    }
    return answer;
}
int main()
{
    std::vector<std::string> aboba = {"ab", "a"};
    std::cout<<longestCommonPrefix(aboba)<<std::endl;
    return 0;
}