#include <iostream>
#include "bits/stdc++.h"
//#include "./stdc++.h"
#include <vector>
#include <map>
/*
A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k; for example, R(6) = 111111.
Let us consider repunits of the form R(10^n).
Although R(10), R(100), or R(1000) are not divisible by 17, R(10000) is divisible by 17. Yet there is no value of n for which R(10^n) will divide by 19. In fact, it is remarkable that 11, 17, 41, and 73 are the only four primes below one-hundred that can  be a factor of R(10^n).
Find the sum of all the primes below one-hundred thousand that will never be a factor of R(10^n).
*/

int fractionToDecimal(int numr, int denr)
{
    std::string res;
    std::map<int, int> mp;
    mp.clear();
 
    int rem = numr % denr;
    while ((rem != 0) && (mp.find(rem) == mp.end()))
    {
        mp[rem] = res.length();
        rem = rem * 10;
        int res_part = rem / denr;
        res += std::to_string(res_part);
        rem = rem % denr;
    }
 
    return (rem == 0) ? 0 : res.substr(mp[rem]).size();
}

int primePeriodLength(int  prime)
{
    std::string s{};
    int i=1;
    while(i<prime)
    {
        i*=10;
        s.append("0");
    }
    for(int k{};k<prime;++k)//we need at most p digits after dot
    {
        s.append(std::to_string(i/prime));
        i=(i%prime)*10;

        while(i<prime)
        {
            i*=10;
            s.append("0");
        }
    }
    //find repitition length in 's'
    int min = (prime-1);
    std::string smin;
    for(int l{0};l<prime/2;++l)
    {
        for(int k{3};k<min;++k)
        {
            if(l+2*k<static_cast<int>(s.size()))
            {
                if(s.substr(l,k) == s.substr(l+k,k))
                {
                    if(min>k)
                    {
                        min = k;
                        smin =s.substr(l,k);
                    }
                }
            }
        }
    }
    //std::cout<< prime<<" : "<<min<<" : "<< smin<<" : "<<s<<std::endl;
    return min;
}

int main()
{
    int n = 100000;
    std::cout<<"Calculating the primes..."<<std::endl;
    bool is_prime[n + 1];
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p{2}; p * p <= n; ++p) 
    {
        if (is_prime[p]) 
        {
            for (int i{p * p}; i <= n; i += p) 
            {
                is_prime[i] = false;
            }
        }
    }
    std::vector<int> primes;
    for (int i{2}; i <= n; i++)
        if (is_prime[i])
        {
            primes.push_back(i);
            //std::cout<<i<<",";
        }
    //for each prime p find length of the period 1/p
    std::vector<int>numnum;
    for(auto p : primes)
    {
        std::cout<<"Calculating the fraction length of "<<p<<"...          \r";
        numnum.push_back(fractionToDecimal(1,p));
    }
    std::cout<<std::endl<<std::endl;

    int sum=-3;
    int answer=3;
    for(int i{0};i<numnum.size();++i)
    {
        int k = (numnum[i]);
        while(k%2==0&&k!=0)k/=2;
        while(k%5==0&&k!=0)k/=5;
        if(k==1)
        {
            sum+=primes[i];
            std::cout<<primes[i]<<": "<<numnum[i]<<std::endl;
        }
        else
        {
            answer+=primes[i];
        }
    }
    int tmp_sum_all_primes=0;
    for(auto i : primes)
        tmp_sum_all_primes+=i;
    std::cout<<"answer = "<< answer <<std::endl; // 453647705
    std::cout<<"check point : allPrimes - divisibles = "<< tmp_sum_all_primes<<" - "<<sum<<" = "<<(tmp_sum_all_primes-sum) <<std::endl;
    return 0;
}
/*
logic:
p - prime number;
R(p-1) is divisible by p;

solve this:
    (p-1)*x=10^n -> x=(10^n)/(p-1)
if(p-1 == 2^k * 5^j) // if (p-1) is fractiond by only 2s and 5s - than there exists such n, where (10^n)/(p-1) is integer
    than R(10^n) can be divided by p

//P.S. it is good, but a little fucked... :(
*/

//theorem:
/*
the smallest integer n such that p divides R(n) is the period length of 1/p:
1/41 = 0.024390243902439 -> len(02439) -> 5
1/73 = 0.013698630136986301369863 -> len(01369863) -> 8
*/
/*
So
if we calculate that minimal number (let's call it 'M') - we can know, if p divides R(10^n):
we just have to check, if M = 2^t*5^k (t>=0 && k>=0)
that's it!
*/