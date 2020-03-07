#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define maxn 200010
const double eps=1e-10;
pii a[maxn],b[maxn];
ll c[maxn],d[maxn];
int n;ll x;
main()
{
    scanf("%d%lld",&n,&x);
    int big=0,small=0;
    double tot=0;
    double ans=0;
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&d[i]);
    for(int i=1;i<=n;i++)
    {
        ll w=d[i],s=c[i];
        w-=x;
        tot+=w*s;
        ans+=s;
        if(w>0)a[++big]={w,s};
        else if(w<0)b[++small]={-w,s};
    }
    sort(a+1,a+big+1);
    sort(b+1,b+small+1);
    reverse(a+1,a+big+1);
    reverse(b+1,b+small+1);
    //printf("%.10f\n",tot);
    if(abs(tot)<eps)return 0*printf("%.10f\n",ans);
    else if(tot>0)
    {
        for(int i=1;i<=big;i++)
        {
            ll k=a[i].F*a[i].S;
            if(tot>=k)tot-=k,ans-=a[i].S;
            else{ans-=(1.0*tot)/(1.0*a[i].F),tot=0;break;}
        }
    }
    else
    {
        tot=-tot;
        for(int i=1;i<=small;i++)
        {
            ll k=b[i].F*b[i].S;
            if(tot>=k)tot-=k,ans-=b[i].S;
            else{ans-=(1.0*tot)/(1.0*b[i].F),tot=0;break;}
        }
    }
    if(abs(tot)>eps)puts("0");
    else printf("%.10f\n",ans);
    return 0;
}
