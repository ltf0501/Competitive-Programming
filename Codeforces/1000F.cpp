#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define pii pair<int,int>
#define F first
#define S second
int n,Q,a[maxn];
vector<int> que[maxn];
int ans[maxn];
int le[maxn],ri[maxn],pre[maxn];
pii seg[maxn<<2];
pii good(pii a,pii b)
{
    if(!a.F)return b;
    if(!b.F)return a;
    return min(a,b);
}
void push_up(int o){seg[o]=good(seg[o<<1],seg[o<<1|1]);}
void update(int l,int r,int o,int p,int x,int y)
{
    if(l==r){seg[o]=pii(x,y);return ;}
    int m=(l+r)>>1;
    if(p<=m)update(l,m,o<<1,p,x,y);
    else update(m+1,r,o<<1|1,p,x,y);
    push_up(o);
}
pii query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    return good(query(l,m,o<<1,ql,qr),query(m+1,r,o<<1|1,ql,qr));
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        scanf("%d%d",&le[i],&ri[i]);
        que[ri[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(pre[a[i]])update(1,n,1,pre[a[i]],0,0);
        update(1,n,1,i,pre[a[i]]+1,a[i]);
        pre[a[i]]=i;
       // for(int i=1;i<=4;i++)printf("%d ",pre[i]);puts("");
        for(int id : que[i])
        {
            int l=le[id];
            pii umr=query(1,n,1,l,n);
            //printf("%d %d %d\n",id,umr.F,umr.S);
            if(umr.F<=l)ans[id]=umr.S;
        }
    }
    for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
    return 0;
}
/*
7
1 1 2 3 4 4 3
6
4 7
1 3
1 2
3 7
2 6
5 7
*/

