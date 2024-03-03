#include <iostream>
#include <string>
#include <vector>
/*Given a string s, return the longest palindromic
 
substring in s*/

/*
//bad algorithm of O(n^3)

bool isPalindrom(std::string s, int start, int end)
{
    while (start<end)
    {
        if(s[start]!=s[end])
            return false;
        ++start;
        --end;
    }
    return true;
}

std::string longestPalindrome(std::string s)
{
    int start{};
    int end{};
    std::string answer{};
    int answer_start{};
    int answer_end{};
    for(start=0;start<s.length();++start)
        for(end=start;end<s.length();++end)
            if((end-start+1)>(answer_end-answer_start+1) && isPalindrom(s,start,end))
            {
                answer_start= start;
                answer_end = end;
            }
    answer = s.substr(answer_start,answer_end-answer_start+1);
    return answer;
}
*/

//solution when we search for center of palindrom and than expand to the right and to the left
//tome complexity is O(n^2)

/*
int expand(int left,int right,std::string s)
{
    while(left>=0 && right < s.length() && s[left]==s[right])
    {
        ++right;
        --left;
    }
    return right-left-1;
}
std::string longestPalindrome(std::string s)
{
    //std::vector<int> ans{0,0};
    int a{};
    int b{};
    for(int i{};i<s.length();++i)
    {
        int oddLng = expand(i,i,s);
        if(oddLng>b-a+1)
        {
            int dist = oddLng/2;
            a = i - dist;
            b = i + dist;
        }

        int evenLng = expand(i,i+1,s);
        if(evenLng>b-a+1)
        {
            int dist = (evenLng/2) -1;
            a = i - dist;
            b = i + dist + 1;
        }
    }
    return s.substr(a,b-a+1);
}
*/

//there exists the https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm 
//should try it
std::string longestPalindrome(std::string s)
{
    std::string s2{};
    char x{'|'};
    for(int i{};i<s.length()*2+1;++i)
    {
        if(!(i&1))
            s2.push_back(x);
        else
            s2.push_back(s[i/2]);
    }

    std::vector<int> palindromLngth;
    palindromLngth.resize(s2.length());

    int center{};
    int r{};
    int oldCenter{};
    int oldR{};
    int imax{};
    int max{0};
    while(center<s2.length())
    {
        r = 0;
        while (center<s2.length()&&
               center-(r+1)>=0&&
               center+(r+1)<s2.length()&&
               s2[center-(r+1)]==s2[center+(r+1)])
        {
            ++r;
        }
        palindromLngth[center] = r;
        if(r>max)
        {
            max=r;
            imax=center-r;
        }
        oldCenter=center;
        oldR=r;
        ++center;
        r=0;
        while(center <= (oldCenter+oldR))
        {
            int mirrorCenter{oldCenter-(center-oldCenter)};
            int maxMirrorRadius{oldCenter+oldR-center};
            if(palindromLngth[mirrorCenter]<maxMirrorRadius)
            {
                palindromLngth[center]=palindromLngth[mirrorCenter];
                ++center;
            }
            else if(palindromLngth[mirrorCenter]>maxMirrorRadius)
            {
                palindromLngth[center]=maxMirrorRadius;
                ++center;
            }
            else //if(palindromLngth[mirrorCenter]==maxMirrorRadius)
            {
                r=maxMirrorRadius;
                break;
            }
        }
    }
    return s.substr(imax/2,max);//s2.substr(imax,max*2+1);
}

int main()
{
    std::string s{"cbbd"};
    std::cout<<"longestPalindrome("<<s<<") = "<<longestPalindrome(s)<<std::endl;
    /*
    std::string s{"qwert"};
    std::string s2{};
    std::string x{"@"};
    for(int i{};i<s.length()*2+1;++i)
    {
        if(!(i&1))
            s2.append(x);
        else
        {
            std::string qwer{s[i/2]};
            s2.append(qwer);
        }
    }
    std::cout<<s2;
    */
    return 0;
}