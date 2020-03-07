#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn],f[maxn],g[maxn],t[maxn];
int n;
vector<int> v[maxn];
int ans[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int mx=0;
    for(int i=1;i<=n;i++)t[i]=maxn;
    for(int i=1;i<=n;i++)
    {
        int k=lower_bound(t+1,t+n+1,a[i])-t;
        f[i]=k;t[k]=a[i];
        mx=max(mx,f[i]);
    }
    for(int i=1;i<=n;i++)a[i]=maxn-a[i]+1,t[i]=maxn;
    for(int i=n;i>=1;i--)
    {
        int k=lower_bound(t+1,t+n+1,a[i])-t;
        g[i]=k;t[k]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]+g[i]==mx+1)
            ans[i]=2,v[f[i]].push_back(i);
        else ans[i]=1;
    }
    for(int i=1;i<=n;i++)
        if(v[i].size()==1)ans[v[i][0]]=3;
    for(int i=1;i<=n;i++)printf("%d",ans[i]);
    return 0;
}
