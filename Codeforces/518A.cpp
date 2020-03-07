#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int len=s.size();
    for(int i=len-1;i>=0;i--)
    {
        if(s[i]=='z')s[i]='a';
        else {s[i]++;break;}
    }
    if(s<t)cout<<s; else cout<<"No such string";
    puts("");
    return 0;
}
