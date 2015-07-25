#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
    int k;
    scanf("%d",&k);
    if(k%2==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }       
    cout<<"YES"<<endl;
    if(k==1)
    {
        cout<<2<<" "<<1<<endl;
        cout<<1<<" "<<2<<endl;
        return 0;
    }    
    cout<<4*k-2<<" "<<k*(2*k-1)<<endl;
    // while(1){}
    int t=2*k-1;
    for(int i=2;i<=k;i++)
    {
        cout<<1<<" "<<i<<endl;
        cout<<1+t<<" "<<i+t<<endl;
        for(int j=k+1;j<=2*k-1;j++)
        {
            cout<<i<<" "<<j<<endl;
            cout<<i+t<<" "<<j+t<<endl;
        }    
    }    
    for(int j=k+1;j<=2*k-1;j+=2)
    {
        cout<<j<<" "<<j+1<<endl;
        cout<<j+t<<" "<<j+1+t<<endl;    
    }
    cout<<1<<" "<<1+t<<endl;
 //   while(1){}
    return 0;
}
