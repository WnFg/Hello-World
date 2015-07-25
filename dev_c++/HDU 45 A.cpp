#include <iostream>
#include <cstdio>
using namespace std;
int solve(long long n)
{
    int ans=0;
    int last=0;
    while(n)  
    {
        if(n%2==1&&last==0)
        {
            ans++;
            last=1;
        }    
        else if(n%2==0)
        {
            last=0;    
        }
        n/=2;    
    }  
    return ans;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long n;
        cin>>n;
        cout<<solve(n)<<endl;    
    }    
    return 0;
}
