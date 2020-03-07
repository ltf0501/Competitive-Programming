#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
ll c[maxn];
int r[maxn],inv[maxn];
ll n,k;
bool cmp(int x,int y){return c[x]>c[y];}
main()
{
    scanf("%I64d%I64d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%I64d",&c[i]);
    for(int i=1;i<=n;i++)r[i]=i;
    ll ans=0ll;
    sort(r+1,r+n+1,cmp);
    //for(int i=1;i<=n;i++)printf("%d ",r[i]);puts("");
    for(int i=1;i<=n;i++)inv[r[i]]=i;
    //for(int i=1;i<=n;i++)printf("%d ",inv[i]);puts("");
    bool flag=1;
    while(flag)
    {
        flag=0;
        for(int i=1;i<=n;i++)
        {
            if(inv[r[i]]+k<r[i])
            {
                swap(inv[r[i]],inv[r[r[i]-k]]);
                swap(r[i],r[r[i]-k]);
                flag=1;
            }
        }
    }

    for(int i=1;i<=n;i++)ans+=c[i]*(ll)(inv[i]+k-i);
    printf("%I64d\n",ans);
    for(int i=1;i<=n;i++)printf("%d ",inv[i]+k);
    return 0;
}
