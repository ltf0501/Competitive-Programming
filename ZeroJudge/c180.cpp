#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
ll mx[maxn<<2],pre[maxn<<2],post[maxn<<2],sum[maxn<<2];
int a[maxn];
void push_up(int o)
{
    sum[o]=sum[o<<1]+sum[o<<1|1];
    mx[o]=max(max(mx[o<<1],mx[o<<1|1]),post[o<<1]+pre[o<<1|1]);
    pre[o]=max(pre[o<<1],sum[o<<1]+pre[o<<1|1]);
    post[o]=max(post[o<<1|1],sum[o<<1|1]+post[o<<1]);
}
void build(int l,int r,int o)
{
    if(l==r)
    {
        mx[o]=a[l],pre[o]=a[l],post[o]=a[l],sum[o]=a[l];
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    while(m--)
    {
        int b,c,d;scanf("%d%d%d",&b,&c,&d);
    }
    return 0;
}
