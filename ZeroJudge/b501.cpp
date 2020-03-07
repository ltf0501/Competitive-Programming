#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int cmp(string a,string b)
{
    string s=a+b,t=b+a;
    if(s<t)return 0;
    return 1;
}
main()
{
    int n;
    string s[100005];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)cin>>s[i];
        sort(s,s+n,cmp);
        for(int i=0;i<n;i++)cout<<s[i];
        puts("");
    }
    return 0;
}
