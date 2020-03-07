#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
#define pii pair<int,int>
#define F first
#define S second
const int INF=1e9;
int n,m;
pii a[maxn];
int cnt[3];
void init()
{
    memset(cnt,0,sizeof(cnt));
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d%d",&a[i].F,&a[i].S);
        sort(a+1,a+n+1);
        int l=1,r=0;
        int ans=INF;
        while(r<=n)
        {
            while(r<=n && min({cnt[0],cnt[1],cnt[2]})<m)cnt[a[++r].S-1]++;
            if(r==n+1)break;
            ans=min(ans,a[r].F-a[l].F);
            //printf("%d %d %d\n",l,r,ans);
            while(a[l+1].F==a[l].F)cnt[a[l++].S-1]--;
            cnt[a[l++].S-1]--;
        }
        if(ans!=INF)printf("%d\n",ans);
        else puts("QQ");
    }
    return 0;
}
