#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 3010
const ll INF=1e18;
int n,m;
vector<int> v[maxn];
int id[maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int p,c;scanf("%d%d",&p,&c);
        v[p].push_back(c);
    }
    for(int i=1;i<=m;i++)sort(v[i].begin(),v[i].end());
    ll ans=INF;
    for(int i=0;i<n;i++)
    {
        vector<int> tmp;
        ll sum=0;
        int tot=v[1].size();
        for(int j=2;j<=m;j++)
        {
            int k;
            for(k=0;k<(int)v[j].size()-i;k++)tot++,sum+=v[j][k];

            for(;k<v[j].size();k++)tmp.push_back(v[j][k]);
        }

        sort(tmp.begin(),tmp.end());
        int s=i+1-tot;
        for(int j=0;j<s;j++)sum+=tmp[j];
        ans=min(ans,sum);
       // printf("%d %lld\n",i,sum);
    }
    printf("%lld\n",ans);
    return 0;
}

