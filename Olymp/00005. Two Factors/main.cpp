#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>
#include <map>
//https://www.eolymp.com/uk/problems/5
bool isPrime(long long n)
{
    int f{};
    for(long long i{1};i<=static_cast<long long>(std::sqrt(n));++i)
    {
        if(n%i==0)
        {
            f+=2;
        }
    }
    return (f==2);
}
long long min(long long a, long long b)
{
    return a<b?a:b;
}
int numOfFactors(long long n)
{
    if(n==1)
        return 1;
    int factors=0;
    for(long long i{2};n>1;++i)
    {
        if(n%i==0)
        {
            n/=i;
            factors+=2;
            i=1;
        }
    }
    return factors;
}

//generated prime numbers up to 100
int primes[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
void printVector(std::vector<int> v)
{
    for(auto it{v.begin()};it!=v.end();++it)
        std::cout<<*it<<" ";
    //std::cout<<std::endl;
}
long long evaluate(const std::vector<int> p)
{//assume, that p is already sorted max to min
    long long result{1};
    //for(auto it{p.begin};it!=p.end();++it)
    for(int i{};i<p.size();++i)
    {
        result*=static_cast<long long>(powl(primes[i],p[i]-1));
    }
    return result;
}
std::vector<int> subset;
std::vector<int> TMP_DO_NOT_CHANGE;
std::map<std::vector<int>,int> factorsCombinations{};
void search(int k, int n)
{
    if(k == n+1)
    {
        if(subset.size()>1)
        {
            int res=1;
            std::vector<int> tmp(TMP_DO_NOT_CHANGE);
            for(auto i : subset)
                res*=tmp[i];
            for(int i=subset.size()-1;i>=0;--i)
            {
                tmp.erase(tmp.begin()+subset[i]);
            }
            tmp.push_back(res);
            //tmp.insert(tmp.begin(),res);
            sort(tmp.begin(),tmp.end(),std::greater<int>());
            factorsCombinations[tmp]++;
        }
    }
    else
    {
        subset.push_back((k-1));
        search(k+1, n);
        subset.pop_back();
        search(k+1, n);
    }
}
int main()
{
    //std::map<int,int> factors{};
    
    //printVector(primes.begin(),primes.end());
    std::vector<int> f{};
    std::cout<<"k -> list -> evaluation"<<std::endl;
    long long min{LLONG_MAX};
    for(int k{1};k<=100;++k)
    {
        //factors.clear();
        factorsCombinations.clear();
        f.clear();
        int tmp = k;
        //long long min{static_cast<long long>(pow(2,(k/2)-1))};
        for(int j{2};tmp>1;)
        {
            if(tmp%j==0)
            {
                //factors[j]++;
                f.push_back(j);
                tmp/=j;
            }
            else
                ++j;
        }
        if(f.size()==0)
            f.push_back(1);
        //printVector(f.begin(),f.end());

        sort(f.begin(),f.end(),std::greater<int>());//sort max to min

        TMP_DO_NOT_CHANGE=f;
        
        search(1,TMP_DO_NOT_CHANGE.size());

        std::cout<<(k+1)/2<<" \t-> ";
        printVector(f);
        std::cout<<" -> "<<evaluate(f)<<std::endl;

        if(k%2==1)
            min = evaluate(f)>0?evaluate(f):LLONG_MAX;
        else
            min = evaluate(f)<min?(evaluate(f)>0?evaluate(f):min):min;
        for(const auto &it : factorsCombinations)
        {
            long long abeba{evaluate(it.first)};
            std::cout<<" \t-> ";
            printVector(it.first);
            
            std::cout<<" -> "<<abeba<<std::endl;
            if(abeba>0&&abeba<min)
                min = abeba;
        }
        if(k%2==0)
            std::cout<<"ANSWER = "<<min<<std::endl;
    }

#if 0
    //std::vector<long long> a{1,4,12, 24, 48, 60, 192, 120, 180, 240, 3072, 360, 12288, 900, 720, 840, 196608, 1260, 786432, 1680, 2880, 15360, 12582912, 2520, 6480, 61440, 6300, 6720, 805306368, 5040, 3221225472, 7560, 446080, 983040, 25920, 10080, 206158430208, 32400, 184320, 15120, 3298534883328, 20160, 13194139533312, 107520, 25200, 2985984, 211106232532992, 27720, 233280, 45360};//{1,4,12,24,48,60,192,120,180,240,3072,360,12288,960,720,840,196608,1260,786432};
    std::vector<long long> a{1,4};//,12, 24, 48, 60, 192, 120, 180, 240, 3072, 360, 12288, 900, 720, 840, 196608, 1260, 786432, 1680, 2880, 15360, 12582912, 2520, 6480, 61440, 6300, 6720, 805306368, 5040, 3221225472, 7560, 446080, 983040, 25920, 10080, 206158430208, 32400, 184320, 15120, 3298534883328, 20160, 13194139533312, 107520, 25200, 2985984, 211106232532992, 27720, 233280, 45360};//{1,4,12,24,48,60,192,120,180,240,3072,360,12288,960,720,840,196608,1260,786432};
    std::unordered_map<int,int> map{};
    int max=0;
    for(long long i{2};i<1000000;++i)
    {
        map.clear();
        long long tmp=i;
        for(long long j{2};tmp>1;)
        {
            if(tmp%j==0)
            {
                map[j]++;
                tmp/=j;
            }
            else
            {
                j++;
            }
        }
        int result{1};
        for(auto it = map.begin();it!=map.end();++it)
            result *= (it->second+1);
        if(result/2>max)
        {
            max=result/2;
            std::cout<<i<<" -> "<<result<<"|\n";
        }
        if(i%10000000==0)
            std::cout<<".";
    }
    //long long a[]{1,4,12, 24, 48, 60, 192, 120, 180, 240, 3072, 360, 12288, 900, 720, 840, 196608, 1260, 786432, 1680, 2880, 15360, 12582912, 2520, 6480, 61440, 6300, 6720, 805306368, 5040, 3221225472, 7560, 446080, 983040, 25920, 10080, 206158430208, 32400, 184320, 15120, 3298534883328, 20160, 13194139533312, 107520, 25200, 2985984, 211106232532992, 27720, 233280, 45360};
    /*
    long long k{1};
    long long factors{};
    long long n{1};
    while (a.size()<50)
    {
        factors=0;
        n=a.size()+1;
        if(isPrime(n))
        {
            long long aboba=1;
            for(int i{};i<n-1;++i)
            {
                aboba*=2;
            }
            a.push_back(aboba*3);
            std::cout<<aboba*3<<", ";
            k=0;
            //std::cout<<n<<" -> "<<aboba*3<<std::endl;
        }
        else
        {
            for(long long i{1};i<=static_cast<long long>(std::sqrt(k));++i)
            {
                if(k%i==0)
                {
                    factors+=2;
                }
            }
            if(factors==(a.size()+1)*2)
            {
                a.push_back(k);
                std::cout<<k<<", ";
                k=0;
            }
        }
        ++k;
    }
    */
    //for (int i : a)
    //    std::cout<<i<<", ";
    /*

    for(auto i : a)
    {
        std::cout<<i<<" -> "<<numOfFactors(i)<<std::endl;
    }
    */
#endif

#if 0
    //std::unordered_map<int,int> factors{};
    std::map<int,int> factors{};
    
    for(int i{2};i<=100;i+=2)
    {
        int tmp = i;
        factors.clear();
        for(int j{2};tmp>1;)
        {
            if(tmp%j==0)
            {
                factors[j]++;
                tmp/=j;
            }
            else
            {
                ++j;
            }
        }
        //int result{1};
        //for(auto it = factors.begin();it!=factors.end();++it)
        //{
        //    result*=(it->second+1);
        //}
        std::cout<<i<<" -> ";//<<result<<"| f = ";
        for(auto it = factors.begin();it!=factors.end();)
        {
            std::cout<<it->first<<"^"<<it->second;
            if((++it)!=factors.end())
                std::cout<<" * ";
        }
        std::cout<<std::endl;
    }
#endif


    return 0;
}
