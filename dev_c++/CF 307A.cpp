#include <iostream>
#include <cstdio>
using namespace std;
int a[2001];
int num[2001];
int f[2001];
int main()
{
    int n,b;
    cin>>n;
    int j;
    for(int i=0;i<n;i++)    
    {
        scanf("%d",&b);    
        for(j=i-1;j>=0;j--)
        {
            if(b>a[j])
            {
                a[j+1]=a[j];
                num[j+1]=num[j];         
            }    
            else
                break;
        }
        a[j+1]=b;
        num[j+1]=i;
    }
    //for(int i=0;i<n;i++)
      //  cout<<num[i]<<endl;
    int t=1;
    f[num[0]]=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])       
        {
            t=i+1;    
        }    
        f[num[i]]=t;
    }
    for(int i=0;i<n;i++)
        cout<<f[i]<<" ";
    cout<<endl;
    //while(1){}
    return 0;
}
