#include<bits/stdc++.h>
using namespace std;
#define maxn 60010
#define pii pair<int,int>
#define F first
#define S second
map<pii,int> mp;
vector<int> v[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        v[x].push_back(i);
    }
    while(m--)
    {
        int a,b;scanf("%d%d",&a,&b);
        if(!v[a].size() || !v[b].size()){puts("-1");continue;}
        if(a==b){puts("0");continue;}
        if(v[a].size()>v[b].size())swap(a,b);
        if(mp.find(pii(a,b))!=mp.end()){printf("%d\n",mp[pii(a,b)]);continue;}
        int ans=maxn;
        for(int s : v[a])
        {
            int k=lower_bound(v[b].begin(),v[b].end(),s)-v[b].begin();
            if(k!=0)ans=min(ans,s-v[b][k-1]);
            if(k!=v[b].size())ans=min(ans,v[b][k]-s);
        }
        printf("%d\n",ans);
        mp[pii(a,b)]=ans;
    }
    return 0;
}
