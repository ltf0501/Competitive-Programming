#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
pii a[maxn];
int n,m;
ll ans[(1<<22)+5];
void mrge(int l,int r,int ql,int qr)
{
    if(l==r-1){for(int i=ql;i<qr;i++)ans[l]+=a[i].S;return ;}
    int m=(l+r)>>1;
    int m2=lower_bound(a+ql,a+qr,mkp(m,-105))-a;
    mrge(l,m,ql,m2);
    mrge(m,r,m2,qr);
    for(int i=m;i<r;i++)ans[i]+=ans[i-m+l];
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        char s[25];int k;
        scanf("%s %d",s,&k);
        int b=0;
        for(int j=0;j<n;j++)b|=(s[j]-'0')<<j;
        a[i]=mkp(b,k);
        //printf("%d\n",b);
    }
    sort(a,a+m);
    mrge(0,1<<n,0,m);
    ll ans2=0;
    sort(ans+1,ans+(1<<n));
    for(int i=1;i<(1<<n);i++)ans2+=(ll)i*ans[i];
    //for(int i=0;i<(1<<n);i++)printf("%d ",ans[i]);puts("");
    printf("%lld\n",ans2);
    return 0;
}
