#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1


const int N = 511111;
struct node{
  LL sub,pre,suf,sum;
  LL l,r,prep,sufp;
  node(LL x=0,LL y=0,LL z=0):
      sub(x),l(y),r(z){}
}a[N<<2];
LL b[N];
node get(node a,node b){
  if(a.sub !=b.sub){
     return (a.sub > b.sub ? a:b);
  }
  if(a.l != b.l)
    return (a.l < b.l ? a : b);
  return (a.r < b.r ? a : b);
}
node better(node a,node b){
  node te ,tl= get(a,b);
   tl = get(tl,node(a.suf+b.pre,a.sufp,b.prep));
  te.l = tl.l; te.r = tl.r;
  te.sub = max(a.sub,b.sub);
  te.sub = max(te.sub,a.suf+b.pre);
  te.suf = max(b.suf,b.sum+a.suf);
  te.sufp = (b.suf > b.sum+a.suf ? b.sufp:a.sufp);
  te.pre = max(a.pre,a.sum+b.pre);
  te.prep = (a.pre >= a.sum+b.pre ? a.prep:b.prep);
  te.sum = a.sum+b.sum;
  return te;
}
void push_up(int l,int r,int rt){
  a[rt] = better(a[rt<<1],a[rt<<1|1]);
}
void build(int l,int r,int rt){
   if(l==r){
     a[rt].pre = a[rt].suf = a[rt].sum =a[rt].sub = b[l];
     a[rt].l = l; a[rt].r = r; a[rt].prep = a[rt].sufp =l;
     return ;
   }
   int m = (l+r)>>1;
   build(lson);
   build(rson);
   push_up(l,r,rt);
}
node query(int l,int r,int rt,int L,int R){
  if(L<=l&&r<=R){
     return a[rt];
  }
  int m =(l+r)>>1,ok=0;
  node res;
  if(L<=m){ok = 1; res=query(lson,L,R);}
  if(R>m){
     if(ok) res = better(res,query(rson,L,R));
     else res = query(rson,L,R);
  }
  return res;
}
int n,M;
int main()
{
    int kase = 1;
    while(scanf("%d %d",&n,&M)==2){
       for(int i=1;i<=n;i++){
         scanf("%lld",&b[i]);
       }
       build(1,n,1);
       printf("Case %d:\n",kase++);
       while(M--){
          int x,y;
         scanf("%d %d",&x,&y);
         node res = query(1,n,1,x,y);
         printf("%lld %lld\n",res.l,res.r);
       }
    }
    return 0;
}
