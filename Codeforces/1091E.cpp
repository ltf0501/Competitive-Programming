#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
int a[maxn],tmp[maxn];
ll pre[maxn],suf[maxn];
ll seg[maxn<<2],tg[maxn<<2];
vector<int> ans,id;
void push_up(int o){seg[o]=min(seg[o<<1],seg[o<<1|1]);}
void push_down(int o)
{
    if(!tg[o])return ;
    seg[o<<1]+=tg[o],seg[o<<1|1]+=tg[o];
    tg[o<<1]+=tg[o],tg[o<<1|1]+=tg[o];
    tg[o]=0;
}
void build(int l,int r,int o)
{
    if(l==r){seg[o]=suf[l]-pre[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int ql,int qr,int d)
{
    if(ql<=l && r<=qr){seg[o]+=d,tg[o]+=d;return ;}
    push_down(o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,d);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,d);
    push_up(o);
}
/*
ll query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    push_down(o);
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    return min(query(l,m,o<<1,ql,qr),query(m+1,r,o<<1|1,ql,qr));
}
*/
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(a[n]==0)return 0*puts("0");
    for(int i=1;i<=n;i++)tmp[i]=a[i];
    for(int i=1;i<=n;i++)if(tmp[i])
    {
        for(int j=i;j<=n;j++)a[j-i+1]=tmp[j];
        n=n-i+1;
        break;
    }
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    for(int i=1,r=n;i<=n;i++)
    {
        while(r>=1 && a[r]<i)r--;//r largest s.t. a[r]>=i
        suf[i]=1ll*i*(i-1);
        if(r<=i)suf[i]+=pre[n]-pre[i];
        else suf[i]+=(pre[n]-pre[r])+1ll*(r-i)*i;
    }
    build(1,n,1);
    if(pre[n]%2==0 && seg[1]>=0)ans.push_back(0);
    for(int i=1;i<=n;)
    {
        int j=i+1;
        while(j<=n && a[j]==a[i])j++;
        j--;
        for(int k=j;k>=i;k--)id.push_back(k);
        i=j+1;
    }
    for(int j=0;j<id.size();j++)
    {
        int i=id[j];
        update(1,n,1,i,n,1);
        if(a[i]<=i-1)update(1,n,1,a[i],i-1,-1);
        if((pre[n]+(j+1))%2==0 && seg[1]>=0)ans.push_back(j+1);
    }
    if(ans.empty())puts("-1");
    else for(int s : ans)printf("%d ",s);
    return 0;
}
