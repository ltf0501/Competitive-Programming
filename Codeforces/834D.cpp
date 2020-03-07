#include<bits/stdc++.h>
using namespace std;
#define maxn 35010
const int inf=1e9;
int dp[2][maxn],pr[maxn],now[maxn];
int mx[4*maxn],lazy[4*maxn];
void push_up(int o)
{
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void push_down(int o)
{
    if(lazy[o])
    {
        lazy[o<<1]+=lazy[o];
        lazy[o<<1|1]+=lazy[o];
        mx[o<<1]+=lazy[o];
        mx[o<<1|1]+=lazy[o];
        lazy[o]=0;
    }
}
void build(int l,int r,int o,int a[])
{
    lazy[o]=0;
    if(l==r){mx[o]=a[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1,a),build(m+1,r,o<<1|1,a);
    push_up(o);
}
void update(int l,int r,int o,int ql,int qr,int d)
{
    if(ql<=l && r<=qr){mx[o]+=d,lazy[o]+=d;return ;}
    int m=(l+r)>>1;
    push_down(o);
    if(ql<=m)update(l,m,o<<1,ql,qr,d);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,d);
    push_up(o);
}
int query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return mx[o];
    int m=(l+r)>>1;
    push_down(o);
    int ret=0;
    if(ql<=m)ret=max(ret,query(l,m,o<<1,ql,qr));
    if(qr>m)ret=max(ret,query(m+1,r,o<<1|1,ql,qr));
    return ret;
}
main()
{
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        pr[i]=now[x];
        now[x]=i;
    }
    int cur=0;
    for(int i=1;i<=n;i++)dp[cur][i]=dp[cur][i-1]+!pr[i];
    for(int i=2;i<=k;i++)
    {
        cur^=1;
        fill(dp[cur]+1,dp[cur]+k+1,-inf);
        build(1,n,1,dp[cur^1]);
        for(int j=i;j<=n;j++)
        {
            update(1,n,1,max(pr[j],1),j-1,1);
            dp[cur][j]=query(1,n,1,i-1,j-1);
            //printf("%d ",dp[cur][j]);
        }
    }
    printf("%d\n",dp[cur][n]);
    return 0;
}
