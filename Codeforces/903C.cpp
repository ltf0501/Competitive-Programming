#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
int a[maxn],n;
map<int,int> mp;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(mp.find(x)!=mp.end())mp[x]++;
        else mp[x]=1;
    }
    int ans=0;
    for(auto s : mp)ans=max(ans,s.second);
    printf("%d\n",ans);
    return 0;
}
