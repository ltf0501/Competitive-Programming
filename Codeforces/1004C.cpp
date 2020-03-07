#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
int le[maxn],ri[maxn];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)le[i]=n+1;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(le[x]==n+1)le[x]=i;
        ri[x]=i;
    }
    //for(int i=1;i<=n;i++)printf("%d %d\n",le[i],ri[i]);
    ll ans=0;
    sort(le+1,le+n+1);
    sort(ri+1,ri+n+1);
    for(int i=1,cur=1;i<=n;i++)
    {
        while(cur<=n && ri[cur]<=le[i])cur++;
        ans+=(n+1-cur);
    }
    printf("%lld\n",ans);
    return 0;
}
