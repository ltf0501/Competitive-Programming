#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        string s;cin>>s;
        int match=0,ans=0;
        int len=s.size();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='.')continue;
            if(s[i]=='p')match++;
            if(s[i]=='q')
            {
                if(match==0)continue;
                match--;ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
