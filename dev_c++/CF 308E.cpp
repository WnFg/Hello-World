#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int mul[20];
//int sta[5002];
long long f(string s,int x,int y)
{
    long long sum=0,mul=s[x];
    for(int i=x;i<y;i+=2)
    {
        if(s[i+1]=='+')
        {        
            sum+=mul;
            mul=s[i+2];
        }    
        else           
        {
            mul*=s[i+2];    
        }    
    }    
    sum+=mul;
    return sum;
}
int gg(char c)
{
    return c-'0';    
}
long long f(string s1,string s2,long long x)
{
    long long sum=0,mul=s1[0];
    int q=s1.size(),w=s2.size();
    //cout<<q<<" "<<w<<" "<<mul<<endl;
    //int tt=q+w;
    //cout<<s1<<" "<<s2<<endl;
    //cout<<q<<" "<<w<<endl;
    q--;
    for(int i=0;i<q;i+=2)
    {
        if(s1[i+1]=='+')
        {        
            sum+=mul;
            if(i+2<q)
                mul=s1[i+2];
            else
                mul=x;
        }    
        else           
        {
            if(i+2<q)
                mul*=s1[i+2];    
            else
                mul*=x;
        }       
    }
    if(q<0)
    {
        mul=x;    
    }
    //cout<<sum<<" "<<mul<<endl;
    w--;
    for(int i=0;i<w;i+=2)
    {
        if(s2[i]=='+')
        {
            sum+=mul;
            mul=s2[i+1];    
        }    
        else
        {
            mul*=s2[i+1];    
        }
    }    
    return sum+mul;    
}
long long max(long long x,long long y)
{
    return x>=y?x:y;    
}
int main()
{
   // string s1,s2;
    //int x;
   // cin>>s1>>s2>>x;
   // cout<<f(s1,s2,x)<<endl;
   // while(1){}
    string s;
    cin>>s;
    int n=s.size();
    int t=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='*')
            mul[t++]=i;    
        if(s[i]>='0'&&s[i]<='9')
            s[i]-='0';
    }        
    //cout<<f(s,0,n-1)<<endl;
    //int p=0;
    int sum=0,m=1,last;
    int a1,a2,a3;
    //long long ans=-1;
    string s2;
   // cout<<n<<endl;
   // cout<<mul[0]<<endl;
    if(t==0)
    {
        int ttt=0;
        for(int i=0;i<n;i+=2)
            ttt+=s[i];
        cout<<ttt<<endl;
     //   while(1){}
        return 0;    
    }
    long long ans=f(s,0,n-1);
    //cout<<ans<<endl;
    //while(1){}
   // cout<<mul[0]<<endl;
   // while(1){}
    for(int i=0;i<t;i++)
    {
        //a1=f(s,0,mul[i]-1);
        for(int j=mul[i]+1;j<n;j+=2)    
        {
           // cout<<j<<" "<<"fdsf"<<endl;
            s2.clear();
            a2=f(s,mul[i]+1,j);
            //s2.push_back(a2);
           // s2=s.substr(0,mul[i]+1);
           // s2.push_back(a2);
           // s2+=s.substr(j+1,n);
         //   cout<<mul[i]<<" "<<j+1<<" "<<a2<<" "<<" "<<f(s.substr(0,mul[i]+1),s.substr(j+1,n),a2)<<endl;
         //   cout<<" ooo"<<endl;
            ans=max(ans,f(s.substr(0,mul[i]+1),s.substr(j+1,n),a2));
        }
        //cout<<" "<<ans<<"fdsf"<<endl;
        for(int j=mul[i]-1;j>=0;j-=2)
        {
            s2.clear();
            a2=f(s,j,mul[i]-1);
            //cout<<j<<" "<<"  "<<a2<<"  YYYYY"<<endl;
            //s2=s.substr(0,j);
            //s2.push_back(a2);
            //s2+=s.substr(mul[i],n);
            //if(j==0)
            //    cout<<a2<<endl;
            ans=max(ans,f(s.substr(0,j),s.substr(mul[i],n),a2));    
        }
    }
    cout<<ans<<endl;
    //while(1){}
    return 0;
}
