#include <iostream>
#include <string>
/*Given two strings needle and haystack,
return the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.*/
int strStr(std::string haystack, std::string needle)
{
    return haystack.find(needle);
}
int main()
{
    return 0;
}