#include <iostream>
#include <cstring>
#include <string>
#include <vector>
//#include <vector>
//#include <cmath>
/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
*/
//p = pattern, s = string
bool no_isMatch(std::string s, std::string p)
{
    bool isDot{p.find('.')!=std::string::npos};
    bool isStar{p.find('*')!=std::string::npos};
    //4 variants:
    //1) p doesn't have neither '.' nor '*' in it
    if(!isStar&&!isDot)
    {
        //check, if p equals to s
        return (strcmp(p.c_str(),s.c_str())==0);
    }
    //2) p have '.' in it, but don't have '*'
    else if(isDot&&!isStar)
    {
        if(p.size()==s.size())
        {
            for(int i{0};i<s.size();++i)
            {
                if(p[i]!='.')
                {
                    if(s[i]!=p[i])
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    //3) p have '*' in it, but don't have '.'
    else if(!isDot&&isStar)
    {
        //every "**" = "*"
        //and remember every "*" position
        std::vector<int> stars{};
        for(int i{};i<p.size()-1;++i)
        {
            if(p[i]=='*'&&p[i+1]=='*')
            {
                //check if there are more of them
                int j{i+1};
                while(j<p.size()&&p[j]=='*')
                    ++j;
                //delete from i to j-1 from p;
                p.erase(i,j-i-1);
                stars.push_back(i);
                //i=0;
            }
            else if(p[i]=='*')
            {
                stars.push_back(i);
            }
        }
        
        /*
        s = aaaaaaaaaaaaaaaqwerty
        p = aaaa*aaaaaqwerty

        p -> {aaaa, aaaaaqwerty}
        foreach p:
            if(s.contains(p))
        */

        for(int i{},j{};i<s.size()&&j<p.size();++i,++j)
        {//i - is for s
        //j - is for p
            if(p[j]!='*')
            {
                if(s[i]!=p[j])
                {
                    return false;
                }
            }
            else
            {
                
            }
        }
    }
    //4) p has both '.' and '*' in it
    else //if(isDot&&isStar)
    {
        //every "**" = "*"
        for(int i{};i<p.size()-1;++i)
        {
            if(p[i]=='*'&&p[i+1]=='*')
            {
                //check if there are more of them
                int j{i+1};
                while(j<p.size()&&p[j]=='*')
                    ++j;
                //delete from i to j from p;
                p.erase(i,j-i-1);
                i=0;
            }
        }

    }
return false;
}

bool isMatch(std::string s, std::string p)
{

    bool isDot{p.find('.')!=std::string::npos};
    bool isStar{p.find('*')!=std::string::npos};
    //1) p doesn't have neither '.' nor '*' in it
    if(!isStar&&!isDot)
    {
        //check, if p equals to s
        return (strcmp(p.c_str(),s.c_str())==0);
    }
    //2) p have '.' in it, but don't have '*'
    else if(isDot&&!isStar)
    {
        if(p.size()==s.size())
        {
            for(int i{0};i<s.size();++i)
            {
                if(p[i]!='.')
                {
                    if(s[i]!=p[i])
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        bool **dp = new bool*[s.size()+1];
        for(int i{};i<s.size()+1;++i)
            dp[i] = new bool[p.size()+1];

        for(int i{};i<s.size()+1;++i)
            for(int j{};j<p.size()+1;++j)
                dp[i][j]=false;
        
        dp[s.size()][p.size()] = true;

        for(int i{static_cast<int>(s.size())};i>=0;--i)
        {
            for(int j{static_cast<int>(p.size())-1};j>=0;--j)
            {
                bool first = (i<s.size()&&
                            (p.at(j)==s.at(i) || p.at(j)=='.'));
                if((j+1) < p.size() && p.at(j+1) == '*')
                {
                    dp[i][j] = dp[i][j+2] || first && dp[i+1][j];
                }
                else
                {
                    dp[i][j] = first && dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];
    }
}

void test(std::string s,std::string p)
{
    std::cout<<"string "<<s<< (isMatch(s,p)?" matches ":" doesn't match ")<< "pattern "<<p<<std::endl;
}
int main()
{
    
    test((std::string)("aa"),(std::string)("a"));
    test((std::string)("aa"),(std::string)("a*"));
    test((std::string)("aa"),(std::string)("a."));
    test((std::string)("aa"),(std::string)(".*"));
    test((std::string)("aaaaaaaaaaaaaaaqwerty"),(std::string)("aaaa*aaaaaqwerty"));
    
    /*
    std::string p{"0****1234*567********89"};
    std::vector<int> stars{};
    for(int i{};i<p.size()-1;++i)
    {
        if(p[i]=='*'&&p[i+1]=='*')
        {
            //check if there are more of them
            int j{i+1};
            while(j<p.size()&&p[j]=='*')
                ++j;
            //delete from i to j-1 from p;
            p.erase(i,j-i-1);
            stars.push_back(i);
            //i=0;
        }
        else if(p[i]=='*')
        {
            stars.push_back(i);
        }
    }
    std::cout<<p<<std::endl;
    for(int i{};i<stars.size();++i)
    {
        std::cout<<stars[i]<<" ";
    }
    */
    //isMatch("qwer","qwer");
    return 0;
}