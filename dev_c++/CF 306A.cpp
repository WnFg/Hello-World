#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s.size()<4)  {cout<<"NO"<<endl;return 0;}
    int mark1=0,mark2=0;
  //  cout<<s.size()<<endl;
    int i;
    for(i=1;i<s.size();i++)
    {
        if(s[i]=='B'&&s[i-1]=='A'&&s[i+1]=='A')
            break;
        if(s[i]=='A'&&s[i-1]=='B'&&s[i+1]=='B')
            break; 
    }   
    if(i!=s.size())
    {    
        for(int j=0;j<s.size()-1;j++)
        {
            if(j+1<i-1||j>i+1)
            {
                if(s[j]=='A'&&s[j+1]=='B'||s[j]=='B'&&s[j+1]=='A')
                {cout<<"YES"<<endl;return 0;}        
            }                
        }
        cout<<"NO"<<endl;
        return 0;
    }        
    else
    {
        for(int j=0;j<s.size()-1;j++)
        {
            if(s[j]=='A'&&s[j+1]=='B')
            {
                mark1=1;
                j++;
                continue;    
            }    
            if(s[j]=='B'&&s[j+1]=='A')
            {
                mark2=1;
                j++;
                continue;    
            }
        }    
        if(mark1&mark2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;    
}
