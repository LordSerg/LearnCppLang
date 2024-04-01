#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <unordered_map>
/*You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings.
 "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.
*/
#if 0
//my solution
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
#endif
#if 0
//fast solution
bool checkSubstring(std::unordered_map<std::string, int> wordCount, std::string s, int wordLen) 
{
    for(int j=0; j<s.size(); j+=wordLen) {
        std::string w = s.substr(j, wordLen);
        if(wordCount.find(w) != wordCount.end()) {
            if(--wordCount[w] == -1) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
    std::vector<int> res;
    int wordLen = words[0].size();
    int sLen = s.size();
    int wordsWindow = words.size() * wordLen;
    
    std::unordered_map<std::string, int> wordCount;
    for(int i=0; i<words.size(); i++) {
        wordCount[words[i]]++;
    }
    
    int i = 0;
    while(i + wordsWindow <= sLen) {
        if(checkSubstring(wordCount, s.substr(i, wordsWindow), wordLen)) {
            res.push_back(i);
        }
        i++;
    }
    return res;
}
#endif
//VERY fast solution
struct matcher {
    struct info { int mtindex, count; };
    std::unordered_map<std::string_view, info>dict;
    int different_word_count;

    std::vector<int>slot;
    int maching_slot_count;

    matcher(const std::vector<std::string>& words) {
        int mtind = 0;
        for (auto& word : words) {
            auto find = dict.find(word);
            if (find != dict.end()) {
                ++find->second.count;
            }
            else { dict[word] = { mtind++,1 }; }
        }
        different_word_count = mtind;
        slot = std::vector<int>(different_word_count, 0);
        maching_slot_count = 0;
    }

    void reset() {
        for (auto& i : slot) { i = 0; }
        maching_slot_count = 0;
    }
    bool match() {
        return maching_slot_count == different_word_count;
    }
    void push(std::string_view sv) {
        auto find = dict.find(sv);
        if (find == dict.end())return;
        if (++slot[find->second.mtindex] == find->second.count) {
            ++maching_slot_count;
        }
    }
    void pop(std::string_view sv) {
        auto find = dict.find(sv);
        if (find == dict.end())return;
        if (--slot[find->second.mtindex] == find->second.count - 1) {
            --maching_slot_count;
        }
    }
};
std::vector<int> findSubstring(std::string s, const std::vector<std::string>& words) {
    int word_count = words.size();
    int word_len = words[0].size();

    matcher matcher(words);

    const char* str = s.c_str();
    int len = s.size();
    std::vector<int> ret;

    for (int off = 0; off < word_len; off++) {
        const char* beg = str + off, * end = str + len;
        if (beg + word_len * word_count <= end) {
            matcher.reset();
            for (int i = 0; i < word_count; i++) {
                std::string_view sv(beg + i * word_len, word_len);
                matcher.push(sv);
            }
            if (matcher.match()) {
                ret.push_back(beg - str);
            }
            const char* pos = beg + word_len * word_count;
            while (pos + word_len <= end) {
                std::string_view del(beg, word_len);
                std::string_view add(pos, word_len);
                beg += word_len;
                pos += word_len;
                matcher.pop(del);
                matcher.push(add);
                if (matcher.match()) {
                    ret.push_back(beg - str);
                }
            }
        }
    }
    return ret;
}
int main()
{
    std::vector<std::string>a{"foo","bar"};
    findSubstring("barfoothefoobarman",a);
    // long long a{-2147483648LL};
    // std::cout<<a<<" of size "<<sizeof(a)<<std::endl;
    // std::cout<<(std::abs(a))<<" of size "<<sizeof(std::abs(a))<<std::endl;
    
    //system("pause");
    return 0;
}