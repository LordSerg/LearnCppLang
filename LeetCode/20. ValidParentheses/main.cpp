#include <iostream>
#include <string>
#include <stack>
#include <map>
/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/
bool isValid(std::string s)
{
    if(s.size()%2==1)
        return false;
    std::stack<char> stk;
    std::map<char,char> mp{{')','('},{']','['},{'}','{'}};
    for(auto ch : s)
    {
        if(ch=='('||ch=='{'||ch=='[')
            stk.push(ch);
        else
        {
            if(stk.empty())
                return false;
            if(mp[ch]!=stk.top())
                return false;
            else
                stk.pop();
        }
    }
    return stk.empty();
}
int main()
{
    std::cout<<isValid("()")<<std::endl;
    std::cout<<isValid("()[]{}")<<std::endl;
    std::cout<<isValid("(]")<<std::endl;
    return 0;
}