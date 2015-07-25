#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int num[2][201][201];
int x[2001],y[2001];
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);   
}
int f(int x)
{
    return x>=0?x:-x;    
}
int main()
{
    int n;
    cin>>n;
    //cout<<gcd(4,-2)<<endl;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);    
    }
    int a,b,g,m=n,ans=0,ret;
    for(int i=0;i<n;i++)
    {
        memset(num,0,sizeof(num));
        ret=0;
        for(int j=i+1;j<n;j++)
        {
            a=x[j]-x[i];b=y[j]-y[i];
            if(a==0)
            {
                num[0][0][1]++;
                continue;
            }    
            else if(b==0)
            {
                num[0][1][0]++;
                continue;
            }    
            g=gcd(a,b);
            a/=g;b/=g;
            if(a*b<0)
                num[1][f(a)][f(b)]++;    
            else
                num[0][f(a)][f(b)]++; 
        }    
        for(int u=0;u<2;u++)
        for(int q=0;q<201;q++)
            for(int w=0;w<201;w++)
                if(num[u][q][w])
                {
                    ret+=num[u][q][w]*(m-num[u][q][w]-1);   
                    //cout<<u<<" "<<q<<" "<<w<<" "<<num[u][q][w]<<endl;
                }
        ans+=ret/2;
        m--;
    }       
    cout<<ans<<endl;
    //while(1){}
    return 0;
}
