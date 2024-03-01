#include <iostream>
#include <string>

/*Given a string s, return the longest palindromic
 
substring in s*/

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
    for(start=0;start<s.length();++start)
        for(end=start;end<s.length();++end)
            if((end-start+1)>answer.length() && isPalindrom(s,start,end))
                answer = s.substr(start,end-start+1);
    return answer;
}

int main()
{
    std::string s{"jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx"};
    std::cout<<"longestPalindrome("<<s<<") = "<<longestPalindrome(s)<<std::endl;
    //std::cout<<"isPalindrome("<<s<<") = "<<isPalindrom(s,4,5)<<std::endl;
    return 0;
}