#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 50010
#define maxm 500010
int s[maxm],t[maxm];
int n,m;
int dp[maxn];
int mi[maxn<<2];
void push_up(int o){mi[o]=min(mi[o<<1],mi[o<<1|1]);}
void build(int l,int r,int o)
{
    if(l==r){mi[o]=maxm;return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int pos,int val)
{
    if(l==r){mi[o]=min(mi[o],val);return ;}
    int m=(l+r)>>1;
    if(pos<=m)update(l,m,o<<1,pos,val);
    else update(m+1,r,o<<1|1,pos,val);
    push_up(o);
}
int query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return mi[o];
    int m=(l+r)>>1;
    int ret=maxm;
    if(ql<=m)ret=min(ret,query(l,m,o<<1,ql,qr));
    if(qr>m)ret=min(ret,query(m+1,r,o<<1|1,ql,qr));
    return ret;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d%d",&s[i],&t[i]);
    fill(dp+1,dp+n+1,maxm);
    dp[1]=0;
    build(1,n,1);
    update(1,n,1,1,0);
    for(int i=1;i<=m;i++)
    {
        int now=query(1,n,1,s[i],t[i]);
        if(now!=maxm)
        {
            //printf("%d\n",now);
            dp[t[i]]=min(dp[t[i]],now+1);
            update(1,n,1,t[i],dp[t[i]]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
/*
40 6
20 30
1 10
10 20
20 30
15 25
30 40
*/
