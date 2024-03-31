#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
/*You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings.
 "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.
*/

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
{
    std::vector<int>answer;
    std::sort(words.begin(),words.end());
    do
    {
        std::string tmp{std::accumulate(words.begin(), words.end(), std::string(""))};
        int k{static_cast<int>(s.find(tmp))};
        while(k != std::string::npos)
        {
            answer.push_back(k);
            k = s.find(tmp,k+1);
        }
    } while (std::next_permutation(words.begin(),words.end()));
    
    return answer;
}

int main()
{
    std::vector<std::string>a{"foo","bar"};
    findSubstring("barfoothefoobarman",a);
    return 0;
}