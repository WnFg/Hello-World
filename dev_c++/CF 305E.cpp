#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int f[200001],vis[200001];
int fac[500001];
int num[500001];
int cnt;
long long ans;
int Factor(int x)
{
    int t=0;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            fac[t++]=i;
            while(x%i==0)
                x/=i;    
        }        
    }    
    if(x!=1)
        fac[t++]=x;
    return t;
}
long long change(int x,int p)
{
    if(x==1&&p==0)
    {
        ans-=cnt-1;
        cnt--;
        return ans;    
    }   
    int t=Factor(x),ret=0;
    
    for(int i=1;i<(1<<t);i++)
    {
        int mul=1,c=0;
        for(int j=0;j<t;j++)
        {
            if((1<<j)&i)
            {
                mul*=fac[j];
                c++;    
         //       cout<<"OOOOO"<<endl;
            }    
        }  
        if(c&1)
            ret+=num[mul];    
        else
            ret-=num[mul];
        if(p)
            num[mul]++;
        else
            num[mul]--;
    }  
  //  cout<<ret<<" YYY  "<<cnt<<endl;
    if(p)
    {  
        ans+=cnt-ret;
        cnt++;
    }
    else
    {
        //cnt--; 
        ans-=cnt-ret;
        //ans++;
        cnt--;
    }    
    return ans;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&f[i]);
    int q;
    while(m--)
    {
        scanf("%d",&q);
        Factor(q);    
        if(!vis[q])
        {
            vis[q]=1;
            printf("%lld\n",change(f[q],1));    
        }
        else
        {
            vis[q]=0;
            printf("%lld\n",change(f[q],0));    
        }                                
    }        
    return 0;
}
