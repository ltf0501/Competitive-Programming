#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 200000+5
#define LL long long
int n,q;
struct node
{
    LL gcd,sum;
}seg[maxn*4+5];
LL a[maxn];
LL Gcd(LL a,LL b)
{
    a=abs(a);b=abs(b);
    if(a<b)swap(a,b);
    if(b==0)return a;
    return Gcd(b,a%b);
}
void build(int L,int R,int o)
{
    if(L==R){seg[o].sum=a[L]-a[L-1];seg[o].gcd=abs(seg[o].sum);return ;}
    int m=L+(R-L)/2;
    build(L,m,o*2);build(m+1,R,o*2+1);
    seg[o].gcd=Gcd(seg[o*2].gcd,seg[o*2+1].gcd);
    seg[o].sum=seg[o*2].sum+seg[o*2+1].sum;
}
int l,r;
void update(int L,int R,int o,int x,int k)
{
    if(x<L || x>R)return ;
    if(x==L && x==R){seg[o].sum+=k;seg[o].gcd=abs(seg[o].sum);return ;}
    int m=L+(R-L)/2;
    if(x<=m)update(L,m,o*2,x,k);
    else update(m+1,R,o*2+1,x,k);
    seg[o].gcd=Gcd(seg[o*2].gcd,seg[o*2+1].gcd);
    seg[o].sum=seg[o*2].sum+seg[o*2+1].sum;
}

LL query1(int L,int R,int o,int l,int r)
{
    if(L>r || l>R)return 0;
    if(l<=L && R<=r)return seg[o].gcd;
    int m=L+(R-L)/2;
    LL q1=query1(L,m,o*2,l,r),q2=query1(m+1,R,o*2+1,l,r);
    return Gcd(q1,q2);
}

LL query2(int L,int R,int o,int l,int r)
{
    if(L>r || l>R)return 0;
    if(l<=L && R<=r)return seg[o].sum;
    int m=L+(R-L)/2;
    LL q1=query2(L,m,o*2,l,r),q2=query2(m+1,R,o*2+1,l,r);
    return q1+q2;
}

main()
{
    scanf("%d%d",&n,&q);
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    build(1,n,1);
    while(q--)
    {
        int c;scanf("%d",&c);
        if(c==1)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            update(1,n,1,l,k),update(1,n,1,r+1,-k);
        }
        if(c==2)
        {
            scanf("%d%d",&l,&r);
            if(l==r){printf("%lld\n",query2(1,n,1,1,l));continue;}
            LL q=query1(1,n,1,l+1,r);
            LL t=query2(1,n,1,1,l);
            printf("%lld\n",Gcd(q,t));
        }
    }
    return 0;
}
/*
6 5
1 4 8 10 14 21
*/
