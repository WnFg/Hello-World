#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int d[200001];
int m,n;
int check(int x)
{
    int i;
    for(i=x;d[i]!=0;i++)
    {
        printf("(%d->",d[i]);
    }    
   // cout<<endl<<x<<" "<<i<<" "<<m<<" ghg"<<endl; 
    printf("%d",d[i]);
    for(int j=x;j<i;j++)
        printf(")");
    if(m==2)
    {
        printf(")");
       // m++;
    }    
    if(i!=n-1)
        printf("->");
    return i;
}
int main()
{
    //int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&d[i]);
    int i;
    if(n==1)
    {
        if(d[0])
            printf("NO\n");
        else{
            printf("YES\n");        
            printf("%d\n",d[0]);
        }    
        return 0;
    }
    if(n==2)
    {
        if(d[1]==1)
            printf("NO\n");
        else if(d[0]==0)
            printf("NO\n");
        else
            printf("YES\n%d->%d\n",d[0],d[1]);
        return 0;    
    }
    if(d[n-1]==1)
    {
        printf("NO\n");
        return 0;    
    }
    int t=0;
    for(int i=0;i<n;i++)
    {
        if(d[i]==0)
            t++;
    }
    if(t>=3)
    {
        printf("YES\n");
        int p=(t-3)&1;
       // cout<<p<<" gfg"<<endl;
        if(!p)
        {
            int i;
            for(i=0;i<n-1;i++)
            {
                if(d[i]==1)
                    i=check(i);    
                else
                    printf("%d->",d[i]);
            }    
            if(i==n-1)
                printf("%d\n",d[n-1]);
        }    
        else
        {
            m=0;
            int i;
            for(i=0;i<n-1;i++)
            {
                //cout<<
                if(m==1&&i!=0)
                {
                    printf("(");
                  //  cout<<"YY"<<endl;
                }    
                if(d[i]==1)
                {
                    i=check(i);    
                }    
                else
                {
                    if(m==2)
                    {
                        printf("%d)->",d[i]);
                    }    
                    else
                    printf("%d->",d[i]);
                 
                } 
                m++;     
            }    
            if(i==n-1)
                printf("%d\n",d[n-1]);
        }
    }    
        else
        {
            if(d[n-1]==0&&d[n-2]==0)
                printf("NO\n");
            else
            {
                printf("YES\n");
                for(int i=0;i<n-1;i++)    
                    printf("%d->",d[i]);
                printf("%d\n",d[n-1]);
            }    
        }
    //while(1){}
    return 0;
}
