#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

main()
{
    string s,t;
    while(cin>>s>>t)
    {
        int lens=s.size(),lent=t.size();
        int now=0;
        for(int i=0;i<lent;i++)
        {
            if(s[now]==t[i])now++;
            if(now==lens)break;
        }
        if(now==lens)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
