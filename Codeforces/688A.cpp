#include<bits/stdc++.h>
using namespace std;
int n,d;
main()
{
    int n,d;scanf("%d%d",&n,&d);
    int cnt=0,mx=0;
    for(int i=1;i<=d;i++)
    {
        string s;cin>>s;
        bool flag=1;
        for(int j=0;j<s.size();j++)
            if(s[j]=='0'){flag=0;break;}
        if(!flag)cnt++;
        else mx=max(cnt,mx),cnt=0;
    }
    printf("%d\n",max(mx,cnt));
    return 0;
}

