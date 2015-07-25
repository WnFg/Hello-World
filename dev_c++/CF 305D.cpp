#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

//Node d[100001];
int f[200001];
int left[200001];
int right[200001];
int ans[200001];
//int MAX[100001];
int initright(int n)
{
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++)
    {
        while(!s.empty())
        {
            if(f[s.top()]<=f[i])
                 break;
            right[s.top()]=i-1;
            s.pop();    
        }    
        s.push(i);
    }       
    while(!s.empty())
    {
        right[s.top()]=n-1;
        s.pop();    
    }
    return 0;
}
int initleft(int n)
{
    stack<int> s;
    s.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty())
        {
            if(f[s.top()]<=f[i])
                  break;
            left[s.top()]=i+1;
            s.pop();    
        }    
        s.push(i);
    }    
    while(!s.empty())
    {
        right[s.top()]=0;
        s.pop();    
    }
    return 0;
}
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        f[i]=a;   
    }    
    initleft(n);
    initright(n);
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<n;i++)
    {
        int x=right[i]-left[i];
        ans[x]=max(ans[x],f[i]);    
    }
    for(int i=n-1;i>=1;i--)
    {
        if(ans[i]>ans[i-1])
            ans[i-1]=ans[i];    
    }
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    //while(1){}
    return 0;
}
