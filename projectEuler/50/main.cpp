#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <cmath>
/*
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13.
This is the longest sum of consecutive primes that adds to a prime below one-hundred.
The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/
long long int sumAllExept(std::vector<long long int>&s, std::vector<bool> &exceptIndeces)
{
    long long int sum{};
    for(int i{};i<s.size();++i)
    {
        if(!exceptIndeces[i])
        {
            sum+=s[i];
        }
    }
    return sum;
}
void next(std::vector<bool>&a,int &from, int &to)
{
    a[from] = true;
    if(from == to)
    {
        from = 0;
        to--;
        for(int i{};i<a.size();++i)
        {
            if(i>=from&&i<=to)
                a[i]=false;
            else
                a[i]=true;
        }
    }
    else
    {
        from++;
    }
}
int main()
{
    int n = 1000000;
    std::cout<<"Calculating the primes..."<<std::endl;
    bool is_prime[n + 1];
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p{1}; p * p <= n; ++p) 
        if (is_prime[p]) 
            for (int i{p * p}; i <= n; i += p) 
                is_prime[i] = false;

    std::vector<long long int> primes;
    std::vector<long long int> allPrimes;
    for (long long int i{0}; i <= n; i++)
        if (is_prime[i])
        {

            if(i<=static_cast<int>(pow(n,2.0/3.0)))primes.push_back(i);
            allPrimes.push_back(i);
            //std::cout<<i<<",";
        }
    //for(auto it:primes)std::cout<<it<<" ";
    //std::cout<<std::endl;
    int from{},to{static_cast<int>(primes.size())-1};
    std::vector<bool> exc(static_cast<int>(primes.size()),false);
    int numOfIterations = (static_cast<int>(primes.size())*(static_cast<int>(primes.size())+1))/2;//static_cast<int>(pow(2,static_cast<int>(primes.size())));
    int max{0};
    for(int i{};i<numOfIterations;++i)
    {
        //for(auto it:exc)std::cout<<it<<" ";
        //std::cout<<std::endl;
        //for(int t{};t<static_cast<int>(primes.size());++t)
        //{
        //    if(!exc[t])
        //    {
        //        std::cout<< primes[t]<<" ";
        //    }
        //}
        //std::cout<<std::endl;
        //std::cout<<"sumAllExept = "<<sumAllExept(primes,exc)<<std::endl;
        std::vector<long long int>::iterator it;
        long long int sum=sumAllExept(primes,exc);
        it=std::find(allPrimes.begin(),allPrimes.end(),sum); 
        if(it != allPrimes.end())
        {
            //std::cout<<sum<<" = ";
            int j{};
            for(int t{};t<primes.size();++t)
            {
                if(!exc[t])
                {
                    ++j;
                    //std::cout<<primes[t]<<" ";
                }
            }
            if(j>max)
            {
                max = j;
                std::cout<<max<<" -> "<<sum<<" = ";
                for(int t{};t<primes.size();++t)
                    if(!exc[t])
                        std::cout<<primes[t]<<" ";
                std::cout<<"\n";
            }
        }
        next(exc,from,to);
    }
    //the answer is 997651 - it is the sum of 543 consecutive primes:
    //997651 = 7+11+13+17+...+3919+3923+3929+3931

    
    return 0;
}