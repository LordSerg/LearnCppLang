#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

std::vector<int> countServers(int n, std::vector<std::vector<int>>& logs, int x, std::vector<int>& queries)
{
    std::sort(logs.begin(), logs.end(),[](auto& a, auto& b){return a[1]<b[1]; });

    std::vector<std::tuple<int,int>> q;
    for(int i=0;i<queries.size();++i)
    {
        q.push_back({queries[i],i});
    }
    std::sort(q.begin(), q.end(),[](auto& a,auto& b){return std::get<0>(a)<std::get<0>(b);});

    std::vector<int> counter(n);
    std::vector<int> answer(queries.size());

    int l=0,r=0,active=0;

    for(auto [t,i]:q)
    {
        while(r < logs.size() && logs[r][1] <= t)
        {
            if(++counter[logs[r++][0]-1]==1)
            {
                active++;
            }
        }

        while(l<r && logs[l][1] < t-x)
        {
            if(--counter[logs[l++][0]-1]==0)
            {
                active--;
            }
        }

        answer[i] = n-active;
    }
    return answer;
}

int main()
{
    int n = 3;
    std::vector<std::vector<int>> logs{{1,35},{1,32},{1,11},{1,39},{2,29}};
    int x = 8;
    std::vector<int> queries{38,30,23,33,15,31,34,22,11,14};
    std::vector<int> answer(countServers(n,logs,x,queries));
    for(int a:answer)
    {
        std::cout<<a<<" ";
    }
    std::cout<<"\n";
}
