#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

1<=n<=8
*/
#if 0
//slow solution
std::vector<std::string> generateParenthesis(int n)
{
    /*
    +-
    */
    /*
    ++--
    +-+-
    */
    /*
    +++---
    ++-+--
    +-++--
    ++--+-
    +-+-+-
    */
    /*
    ++++----
    +++-+---
    ++-++---
    +++--+--
    ++-+-+--
    +++---+-
    ++-+--+-
    +-++--+-
    ++--+-+-
    +-+-+-+-
    +-+++---
    +-++-+--
    +-+-++--
    */
    if(n==1)
        return std::vector<std::string>{"()"};
    std::vector<std::string> answer = generateParenthesis(n-1);
    int curSize = answer.size();
    for(int i{};i<curSize;++i)
    {
        answer.push_back(answer[i]+"()");
        answer.push_back("()"+answer[i]);
        answer.push_back("("+answer[i]+")");

        for(int j=answer[0].size()-2;j>=0;j-=2)
        {
            //answer.push_back("+"+answer[i]+"-");
            answer.push_back(answer[i].substr(0,j)+"("+answer[i].substr(j,answer[0].size()-j)+")");
        }
    }
    answer.erase(answer.begin(),answer.begin()+curSize);
    //deleting dublicants
    std::sort(answer.begin(),answer.end());
    answer.erase(std::unique(answer.begin(),answer.end()),answer.end());
    return answer;
}
#endif
//fast solution
void solK(std::vector<std::string>& ans, std::string str, int open, int close, int n) 
{
    if (str.size() == 2 * n) { 
        ans.push_back(str);
        return;
    }

    if (open < n) {
        solK(ans, str + '(', open + 1, close, n);
    }

    if (close < open) {
        solK(ans, str + ')', open, close + 1, n);
    }
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans;
    solK(ans, "", 0, 0, n); 

    return ans;
}
int main()
{
    std::vector<std::string> a = generateParenthesis(4);
    for(auto it : a)
    {
        std::cout<<it<<"\n";
    }
    return 0;
}
/*
++--+-
1)++--+-+-
2)++--++--
3)+++--+--
4)+++--+--


++--++--
*/