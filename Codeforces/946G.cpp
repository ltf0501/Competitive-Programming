#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
const int INF=1e9+7;
int a[maxn],n;
int b[2][maxn];
int f[maxn],g[maxn],t[maxn];
pii seg[maxn*50];
int lt[maxn*50],rt[maxn*50],tsz;
void push_up(int o){seg[o]=max(seg[lt[o]],seg[rt[o]]);}
void update(int l,int r,int &o,int v,pii x)
{
    if(!o)o=++tsz;
    if(l==r){seg[o]=max(seg[o],x);return ;}
    int m=(l+r)>>1;
    if(v<=m)update(l,m,lt[o],v,x);
    else update(m+1,r,rt[o],v,x);
    push_up(o);
}
pii query(int l,int r,int o,int ql,int qr)
{
    if(!o)return pii(0,0);
    if(ql<=l && r<=qr)return seg[o];
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,lt[o],ql,qr);
    if(ql>m)return query(m+1,r,rt[o],ql,qr);
    return max(query(l,m,lt[o],ql,m),query(m+1,r,rt[o],m+1,qr));
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]-=i;
    }
    for(int i=1;i<=n;i++)t[i]=INF;
    for(int i=1;i<=n;i++)
    {
        int k=upper_bound(t+1,t+n+1,a[i])-t;
        f[i]=k;t[k]=a[i];
    }
    for(int i=1;i<=n;i++)a[i]=-a[i],t[i]=INF;
    for(int i=n;i>=1;i--)
    {
        int k=upper_bound(t+1,t+n+1,a[i])-t;
        g[i]=k;t[k]=a[i];
    }
    for(int i=1;i<=n;i++)a[i]=-a[i];
    //for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
    //for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
    //for(int i=1;i<=n;i++)printf("%d ",g[i]);puts("");
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        pii p=query(-INF,INF,rt[0],-INF,a[i]+1);
        pii q=query(-INF,INF,rt[0],-INF,a[i]);
        int tt=q.F+g[i];
        ans=max(ans,tt+(tt!=n));
        ans=max(ans,p.F+g[i]+(-p.S!=i-1));
        update(-INF,INF,rt[0],a[i],pii(f[i],-i));
    }
    printf("%d\n",n-ans);
    return 0;
}
