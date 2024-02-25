#include <iostream>
#include <vector>
using namespace std;
#define LOOP(i,n) for(int i{};i<n;++i)


vector<int> subset;
void search(int k, int n)
{
    if(k == n+1)
    {
        for(auto i : subset)
            cout<<i<<" ";
        cout<<"\n";
    }
    else
    {
        subset.push_back(k);
        search(k+1, n);
        subset.pop_back();
        search(k+1, n);
    }
}

int main()
{
    cout<<"input set size: ";
    int n{};
    cin>>n;
    cout<<"\nall subsets of the set { ";
    LOOP(i,n)cout<<(1+i)<<" ";
    cout<<"} are : \n";
    search(1,n);
    return 0;
}