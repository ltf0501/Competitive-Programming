#include<cstdio>
#include<iostream>
#include<cctype>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

string s;
int cnt;
map<long long,int>wei_map;
void solve(string s)
{
    int dep=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='[')dep++;
        if(s[i]==']')dep--;
        if(isdigit(s[i]))
        {
            cnt++;
            long long weight=0;
            for(;i<s.length() && isdigit(s[i]);i++)
            {
                weight=weight*10+s[i]-'0';
            }
            i--;
            wei_map[weight<<dep]++;
        }
    }
}
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        wei_map.clear();
        cin >> s;
        solve(s);
        int ans=0;
        for(map<long long, int>::iterator it=wei_map.begin();it!=wei_map.end();it++)
        {
           if(it->second>ans)ans=it->second;
        }
        ans=cnt-ans;
        printf("%d\n",ans);
    }
    return 0;
}
