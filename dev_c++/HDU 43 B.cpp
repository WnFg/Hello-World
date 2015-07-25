#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[100001];
int main()
{
    int n,p,b;
    while(scanf("%d%d",&n,&p)!=EOF)
    {
        for(int i=0;i<n;i++)
        {    
            scanf("%d",&b);
            a[i]=b%p;
        }           
        sort(a,a+n);
       // if(a[n-1]+a[0]>=p)
        int i;
        long long ans=-1;
        for(i=n-1;i>0;i--)
        {
            if(a[i]+a[0]<p) break;
            ans=max(ans,(a[i]+a[n-2])%p);    
        }
        int r=i,l=0;
        long long res;
        while(r-l>0)
        {
            res=(a[r]+a[l]);
            ans=max(ans,res%p);
            if(res>=p)
            {
                r--;    
                continue;
            }       
            l++;     
        }
        printf("%I64d\n",ans);
    }    
    return 0;
}
