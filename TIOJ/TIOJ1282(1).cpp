#include <cstdio>
#include <algorithm>
#include <iostream>
//#define int long long
#ifdef linux
#define getchar getchar_unlocked
#endif
using namespace std;

char __c;
bool flag;

struct Node
{
  long long gcd,sm;
};

int N,Q,l,r,k,c;
long long q,t,x[100005];
Node seg[400005];
void build(int,int,int);
void update(int,int,int,int,int);
long long query1(int,int,int,int,int);
long long query2(int,int,int,int,int);
int main()
{
    scanf("%d%d",&N,&Q);
    x[0]=0;
    for(int i=1;i<=N;i++)scanf("%lld",&x[i]);
    build(1,N,1);
    while(Q--)
    {
        scanf("%d",&c);
        if(c==1)
        {
            scanf("%d%d%d",&l,&r,&k);
            update(1,N,1,l,k),update(1,N,1,r+1,-k);
        }
        if (c == 2)
        {
            scanf("%d%d",&l,&r);
            if(l==r){printf("%lld\n",query2(1,N,1,1,l));continue;}
            q=query1(1,N,1,l+1,r);
            t=query2(1,N,1,1,l);
            printf("%lld\n",__gcd(q,t));
    }
  }
  return 0;
}

void build(int L,int R,int id)
{
  if(L==R){seg[id].sm=x[L]-x[L-1];seg[id].gcd=abs(seg[id].sm);return;}
  int M=(L+R)/2;
  build(L,M,id*2);build(M+1,R,id*2+1);
  seg[id].gcd=abs(__gcd(seg[id*2].gcd,seg[id*2+1].gcd));
  seg[id].sm=seg[id*2].sm+seg[id*2+1].sm;
}

void update(int L,int R,int id,int x,int k)
{
  if(x<L || x>R) return;
  if(x==L && L==R){seg[id].sm+=k;seg[id].gcd=abs(seg[id].sm);return;}
  int M=(L+R)/2;
  if(x<=M)update(L,M,id*2,x,k);
  if(x>M)update(M+1,R,id*2+1,x,k);
  seg[id].gcd=__gcd(seg[id*2].gcd,seg[id*2+1].gcd);
  seg[id].sm=seg[id*2].sm+seg[id*2+1].sm;
}

long long query1(int L, int R, int id, int l, int r) {
  if(L>r || l>R)return 0;
  if(l<=L && R<=r)return seg[id].gcd;
  int M=(L+R)/2;
  long long q1=query1(L,M,id*2,l,r),q2=query1(M+1,R,id*2+1,l,r);
  return __gcd(q1,q2);
}

long long query2(int L, int R, int id, int l, int r)
{
  if(L>r || l>R)return 0;
  if(l<=L && R<=r)return seg[id].sm;
  int M=(L+R)/2;
  long long q1=query2(L,M,id*2,l,r),q2=query2(M+1,R,id*2+1,l,r);
  return q1+q2;
}
