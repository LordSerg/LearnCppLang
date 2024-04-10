#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
/*
Given a string containing just the characters '(' and ')', 
return the length of the longest valid (well-formed) parentheses substring.
*/
#if 0
//my solution:
struct aboba
{
    char ch{};
    int i{};
};

int longestValidParentheses(std::string s)
{
    std::vector<bool> keke(s.size());
    std::stack<aboba>stk;
    for(int i{};i<s.size();++i)
    {
        if(s[i]=='(')
            stk.push(aboba('(',i));
        else// if(s[i]==')')
        {
            if(!stk.empty())
            {
                if(stk.top().ch=='(')
                {
                    keke[stk.top().i]=true;
                    keke[i]=true;
                    stk.pop();
                }
            }
        }
    }
    // for(auto i:keke)
    //     std::cout<<i<<" ";
    int maxLength{};
    int curLength{};
    for(int i{};i<keke.size();++i)
    {
        if(keke[i]==true)
            curLength++;
        else
        {
            if(curLength>maxLength)
                maxLength=curLength;
            curLength=0;
        }
    }
    if(curLength>maxLength)
            maxLength=curLength;
        curLength=0;
    return maxLength;
}
#endif

//clever solution:
int longestValidParentheses(std::string s) {
    int n=s.size();
    std::stack<int>st;
    //for () -1 act as an base index
    st.push(-1);
    int maxx=0;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if(!st.empty())
            {
                maxx=std::max(maxx,i-st.top());
            }
            else
            {
                st.push(i);
            }
        }
    }
    return maxx;
}
int main()
{
    std::string s{"))))())()()(()"};
    std::cout<<s <<" has "<< longestValidParentheses(s)<< " valid parentheses"<<std::endl;
    // longestValidParentheses(s);
    return 0;
}