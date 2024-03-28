#include <iostream>
#include <vector>
#include <algorithm>
//https://www.eolymp.com/uk/problems/6


int maxVect(std::vector<int> v)
{
    if(v.empty())
        return 0;
    int max=0;
    for(auto i:v)
        if(i>max)
            max=i;
    return max;
}

int superFunction(std::vector<std::vector<int>>p, int sum, int day=0)
{
    for(int i{};i<p.size();++i)
    {
        if(p[i][0]-day<1)
        {
            p.erase(p.begin()+i);
            --i;
        }
    }
    std::vector<int>subSum;
    for(int i{};i<p.size();++i)
    {
        int tmpsum{(p[i][0]-day)*p[i][1]};
        auto tmpP(p);
        tmpP.erase(tmpP.begin()+i);
        subSum.push_back(superFunction(tmpP,sum+tmpsum,day+1));
    }
    if(subSum.empty())
        return sum;
    return maxVect(subSum);
}

int main()
{
/*
input example:
4
2 37
3 45
1 46
4 30
output example:
232
*/
    //input data
    int n;//n < 15
    std::vector<std::vector<int>> inpt;//{{d,c},{d2,c2},...}
    std::cin>>n;
    for(int i{};i<n;++i)
    {
        int d,c;// (d <= 30) && (c <= 100)
        std::cin>>d>>c;
        inpt.push_back(std::vector<int>{d,c});
    }
    std::cout<<superFunction(inpt,0);
    /*
    
    int answer{0};
    //int i{0};
    for(const auto&[key,vect]:mp)
    {
        if(key==0)
        {
            answer+=vectMax(vect);
        }
        //++i;
    }
    */
    
    //for(const auto&[key,val]:mp)
    //{
    //    std::cout<<key<<" -> ";
    //    for(auto it : val)
    //    {
    //        std::cout<<it<<" ";
    //    }
    //    std::cout<<std::endl;
    //}
    return 0;
}