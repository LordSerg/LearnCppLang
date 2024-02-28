#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
//Given a string s, find the length of the longest substring without repeating characters.

namespace my_solution
{
    /*
    суть:
    проходимось по стрінгу з початкового char-у;
    йдемо іншим(внутрішнім) ітератором
    якщо елемента нема у перевірочному векторі - то додаємо елемент у вектор і йдемо далі;
    якщо елемент є - то очищуємо вектор, запам'ятовуємо поточну довжину та починаємо новий пошук, але з наступного початкового char-у
    */
    int lengthOfLongestSubstring(std::string s) 
    {
        if(s.size()==1)
            return 1;
        int ans{0};
        std::vector<char> checker;
        for(int i{};i<s.size();++i)
        {
            checker.push_back(s[i]);
            for(int j{i+1};j<s.size();++j)
            {
                if(std::find(checker.begin(),checker.end(),s[j]) != checker.end())
                {//if there is a similar character
                    ans = (j-i)>ans ? j-i : ans;
                    checker.clear();
                    break;
                }
                else
                {
                    checker.push_back(s[j]);
                    ans = (j-i+1)>ans ? (j-i+1) : ans;
                }
            }
        }
        return ans;
    }
}

namespace fast_solution
{
    /*
    суть:
    є два "поінтери" на строку
    проходимось першим вперед і, проходячи, додаємо "ключ-значення" у map
    якщо кількість елементів "ключ-значення" не співпадає з довжиною між поінтерами,
    то рухаємо другий поінтер вперед, і, проходячи, віднімаємо ті елементи "ключ-значення" із map
    якщо довжина між поінтерами співпадає з кількістю елементів у map-і, то знов рухаємо вперед перший "поінтер"
    */
    int lengthOfLongestSubstring(std::string s) 
    {
        int mx=0,n=s.size(),i=0,j=0;
        std::unordered_map<int,int> mp;
        while(j<n)//from begining till the end
        {
            mp[s[j]]++;//we count character
            //
            if((int)mp.size()==j-i+1)
                mx=std::max(mx,j-i+1);
            
            while((int)mp.size()<j-i+1)//???
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)//delete element, if connected to it value == 0
                    mp.erase(s[i]);
                i++;
            }
            // mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
}

void test(std::string s)
{
    std::cout<<"lengthOfLongestSubstring_my of "<<s<<" is "<<my_solution::lengthOfLongestSubstring(s)<<std::endl;
    std::cout<<"lengthOfLongestSubstring_fast of "<<s<<" is "<<fast_solution::lengthOfLongestSubstring(s)<<std::endl;
}
int main()
{
    //test("bbbbbb");
    //test("qwqwqw");
    //test("qweqwe");
    //test("qwerty");
    //test("pwwkew");
    test("abcabcbb");
    
    return 0;
}