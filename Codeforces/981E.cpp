#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
vector<int> seg[maxn<<2],v;
bitset<maxn> ans,b;
void update(int l,int r,int o,int ql,int qr,int x)
{
    if(ql<=l && r<=qr){seg[o].push_back(x);return ;}
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,x);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,x);
}
void gao(bitset<maxn>bb,int l,int r,int o)
{
    for(int s : seg[o])bb|=bb<<s;
    if(l==r){ans|=bb;return ;}
    int m=(l+r)>>1;
    gao(bb,l,m,o<<1);
    gao(bb,m+1,r,o<<1|1);
}
main()
{
    int n,q;scanf("%d%d",&n,&q);
    while(q--)
    {
        int l,r,x;scanf("%d%d%d",&l,&r,&x);
        update(1,n,1,l,r,x);
    }
    b[0]=1;
    gao(b,1,n,1);
    for(int i=1;i<=n;i++)if(ans.test(i))v.push_back(i);
    printf("%d\n",v.size());
    for(int s : v)printf("%d ",s);
    return 0;
}
