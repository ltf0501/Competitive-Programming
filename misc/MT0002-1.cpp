#include<bits/stdc++.h>
using namespace std;
string s;
bool check(int k)
{
    if(s[k]=='M' && s[k+1]=='T' && s[k+2]=='F')return 1;
    return 0;
}
main()
{
    cin>>s;
    int len=s.size();
    if(len<=2)
    {
        for(int i=0;i<len;i++)cout<<'.';
        puts("");
        return 0;
    }
    int i;
    for(i=0;i<len-3;i++)
    {
        if(check(i))cout<<s[i]<<s[i+1]<<s[i+2],i+=2;
        else cout<<'.';
    }
    if(i==len-3 && check(i))cout<<s[i]<<s[i+1]<<s[i+2];
    else
    {
        for(int j=i;j<len;j++)cout<<'.';
    }
    puts("");
    return 0;
}
