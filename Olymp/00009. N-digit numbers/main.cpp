#include <iostream>
#include <vector>
#include <cmath>
int sum(std::vector<int>& v)
{
    int s{};
    for(auto i:v)
        s+=i;
    return s;
}
int prod(std::vector<int>& v)
{
    int p{1};
    for(auto i:v)
        p*=i;
    return p;
}

int main()
{
#if 0
//rough solution
    int n{};
    int numOfNumbers=0;
    std::cin>>n;
    int from{static_cast<int>(std::pow(10,n-1))};
    int to  {static_cast<int>(std::pow(10,n))};
    std::vector<int>a(n);
    for(int i{from-1};i<to;++i)
    {
        int k{1},t{};
        while(k<to)
        {
            a[t] = (i/k)%10;
            t++;
            k*=10;
        }
        int sum{};
        for(auto j:a)
            sum+=j;
        int mult{1};
        for(auto j:a)
            mult*=j;
        if(mult==sum)
        {
            numOfNumbers++;
            std::cout<<i<<std::endl;
        }
    }
    
    std::cout<<"Num of numbers = "<<numOfNumbers<<std::endl;
#endif
#if 0
//cheat solution, based on rough solution
    int n{};
    std::cin>>n;
    switch (n)
    {
    case 1:
        std::cout<<"10 0";
        break;
    case 2:
        std::cout<<"1 22";
        break;
    case 3:
        std::cout<<"6 123";
        break;
    case 4:
        std::cout<<"12 1124";
        break;
    case 5:
        std::cout<<"40 11125";
        break;
    case 6:
        std::cout<<"30 111126";
        break;
    case 7:
        std::cout<<"84 1111127";
        break;
    case 8:
        std::cout<<"224 11111128";
        break;
    case 9:
        std::cout<<"144 111111129";        
        break;
    
    default:
        break;
    }
#endif
    int n{};
    std::cin>>n;
    std::vector<int>a(n,1);
    std::vector<int>b(n,1);//copy
    // if(n==1)
    //     a[0]==0;
    // else
    // {
    //     for(int i{};i<n-2;++i)
    //         a[i]=1;
    //     a[n-2]=2;
    //     a[n-1]=n;
    // }
    // std::cout<<"min number is ";
    // for(auto i:a)
    //     std::cout<<i;
    // std::cout<<std::endl;
    std::vector<std::vector<int>>result;
    for(int i{n-2},k{2},h{1};i>=0;--i)
    {
        //k - is for digit num
        //h - is for digit count
        for(int j{};j<i;++j)
        {
            b[j]=1;
        }
        for(int j{i};j<n;++j)
        {
            b[j]=k;
        }
        int p{prod(b)};
        int s{sum(b)};
        int edgeIndex=n-h-1;//?n-k?
        while(k<=9&&edgeIndex==n-h-1)
        {
            while(p>s&&k<=9)
            {
                k++;
                for(int j{};j<i;++j)
                {
                    b[j]=1;
                }
                for(int j{i};j<n;++j)
                {
                    b[j]=k;
                }
                s=sum(b);
                p=prod(b);
            }
            if(p==s)
            {
                result.push_back(b);
                for(auto i:b)
                    std::cout<<i;
                std::cout<<std::endl;
            }
            b[n-1]++;
            int index=n-1;

            while (index>=0)
            {
                if(b[index]>9)
                {
                    ++k;
                    b[index]=k;
                    if(index-1>=0)
                    {
                        if(edgeIndex>index-1)
                            edgeIndex==index-1;
                        b[index-1]++;
                    }
                    else
                        break;
                }
                index--;
            }
            
            p=prod(b);
            s=sum(b);
        }
        ++h;
        k=2;
    }

    //1) how to find other combinations
    //assume, that half of digits are ones:
    //N=10 ->
    /*(s = sum, p = product)
    [1,1,1,1,1,_,_,_,_,_] :
    [1,1,1,1,1,1,1,1,1,0]; - no, because it's zero
    [1,1,1,1,1,1,1,1,1,1]; s!=p -> 10!=1
    [1,1,1,1,1,1,1,1,1,2]; s!=p -> 11!=2
    [1,1,1,1,1,1,1,1,1,3]; s!=p -> 12!=3
    [1,1,1,1,1,1,1,1,1,4]; s!=p -> 13!=4
    [1,1,1,1,1,1,1,1,1,5]; s!=p -> 14!=5
    [1,1,1,1,1,1,1,1,1,6]; s!=p -> 15!=6
    [1,1,1,1,1,1,1,1,1,7]; s!=p -> 16!=7
    [1,1,1,1,1,1,1,1,1,8]; s!=p -> 17!=8
    [1,1,1,1,1,1,1,1,1,9]; s!=p -> 18!=9
    //conclusion = there is no number, where every digit = 1...
    [1,1,1,1,1,1,1,1,2,2]; s!=p -> 12!=4
    [1,1,1,1,1,1,1,1,2,3]; s!=p -> 13!=6
    [1,1,1,1,1,1,1,1,2,4]; s!=p -> 14!=8
    [1,1,1,1,1,1,1,1,2,5]; s!=p -> 15!=10
    [1,1,1,1,1,1,1,1,2,6]; s!=p -> 16!=12
    [1,1,1,1,1,1,1,1,2,7]; s!=p -> 17!=14
    [1,1,1,1,1,1,1,1,2,8]; s!=p -> 18!=16
    [1,1,1,1,1,1,1,1,2,9]; s!=p -> 19!=18
    //well, i guess, that that part is number-dependent (in this case we didn't get anything)
    [1,1,1,1,1,1,1,1,3,3]; s!=p -> 14!=9
    [1,1,1,1,1,1,1,1,3,4]; s!=p -> 15!=12
    [1,1,1,1,1,1,1,1,3,5]; s!=p -> 16!=15
    [1,1,1,1,1,1,1,1,3,6]; s!=p -> 17!=18
    [1,1,1,1,1,1,1,1,3,7]; s!=p -> 18!=21
    [1,1,1,1,1,1,1,1,3,8]; s!=p -> 19!=24
    [1,1,1,1,1,1,1,1,3,9]; s!=p -> 20!=27
    //same shit
    [1,1,1,1,1,1,1,1,4,4]; s==p -> 16==16 //wow
    [1,1,1,1,1,1,1,1,4,5]; s!=p -> 17!=20
    ...//all other products will be greater, so skip them...
    [1,1,1,1,1,1,1,1,5,5]; s!=p -> 18!=25
    ...//all other products will be greater, so skip them...
    ...
    [1,1,1,1,1,1,1,2,2,2]; s!=p -> 13!=6
    [1,1,1,1,1,1,1,2,2,3]; s!=p -> 14!=12
    [1,1,1,1,1,1,1,2,2,4]; s!=p -> 15!=16//at this point p>s -> can skip others
    [1,1,1,1,1,1,1,2,2,5]; s!=p -> 16!=20
    [1,1,1,1,1,1,1,2,2,6]; s!=p -> 17!=24
    [1,1,1,1,1,1,1,2,2,7]; s!=p -> 18!=28//...



    */
    //2) how to calculate all unique permutations
    return 0;
}