#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxl 100005
main()
{
    string s;
    int a[maxl/3];
    while(cin>>s)
    {
        int len=s.size();
        int cur=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='y')a[cur++]=i;
        }
        int ans=0;
        for(int i=0;i<cur;i++)ans+=abs(a[i]-3*i);
        printf("%d\n",ans);
    }
    return 0;
}
