#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
char c[maxn];
vector<int> ans[maxn];
set<int> s0,s1;
main()
{
    scanf("%s",c+1);
    int n=strlen(c+1);
    if(c[1]=='1' || c[n]=='1')return 0*puts("-1");
    int num[2]={};
    for(int i=1;i<=n;i++)num[c[i]-'0']++;
    if(num[0]<=num[1])return 0*puts("-1");
    int sz=num[0]-num[1];
    for(int i=1;i<=sz;i++)s0.insert(i);
    for(int i=1;i<=n;i++)
    {
        if(c[i]=='0')
        {
            if(s0.empty())return 0*puts("-1");
            ans[*s0.begin()].push_back(i);
            s1.insert(*s0.begin());
            s0.erase(s0.begin());
        }
        else
        {
            if(s1.empty())return 0*puts("-1");
            ans[*s1.begin()].push_back(i);
            s0.insert(*s1.begin());
            s1.erase(s1.begin());
        }
    }
    printf("%d\n",sz);
    for(int i=1;i<=sz;i++)
    {
        printf("%d ",ans[i].size());
        for(int s : ans[i])printf("%d ",s);puts("");
    }
    return 0;
}
