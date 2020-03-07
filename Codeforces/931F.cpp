#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int l[maxn],r[maxn];
int cnt[maxn],cc[maxn];
int n,m;
int f[maxn],g[maxn];

main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
    for(int i=1;i<=n;i++)cnt[l[i]]++,cnt[r[i]+1]--;
    for(int i=1;i<=m;i++)cnt[i]+=cnt[i-1];
    for(int i=1;i<=m;i++)cc[i]=maxn;
    for(int i=1;i<=m;i++)
    {
        int k=upper_bound(cc+1,cc+m+1,cnt[i])-cc;
        cc[k]=cnt[i];
        f[i]=k;
    }
    for(int i=1;i<=m;i++)cc[i]=maxn;
    for(int i=m;i>=1;i--)
    {
        int k=upper_bound(cc+1,cc+m+1,cnt[i])-cc;
        cc[k]=cnt[i];
        g[i]=k;
    }
    int ans=0;
    //for(int i=1;i<=m;i++)printf("%d ",f[i]);puts("");
    //for(int i=1;i<=m;i++)printf("%d ",g[i]);puts("");
    for(int i=1;i<=m;i++)ans=max(ans,f[i]+g[i]-1);
    printf("%d\n",ans);
    return 0;
}
