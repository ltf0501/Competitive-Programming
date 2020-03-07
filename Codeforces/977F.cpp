#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int a[maxn],pre[maxn];
int dp[maxn];
map<int,int> mp;
vector<int> v;
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        dp[i]=dp[mp[x-1]]+1;
        pre[i]=mp[x-1];
        mp[x]=i;
    }
    int id=0;
    for(int i=1;i<=n;i++)
        if(dp[i]>dp[id])id=i;
    printf("%d\n",dp[id]);
    while(id!=0)
    {
        v.push_back(id);
        id=pre[id];
    }
    reverse(v.begin(),v.end());
    for(int s : v)printf("%d ",s);
    return 0;
}
