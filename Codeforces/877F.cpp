#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
int a[maxn],b[maxn];
ll sum[maxn];
int n,k,SZ;
map<ll,ll> mp;
struct Q
{
    int l,r,B,id;
    void input(int i)
    {
        scanf("%d%d",&l,&r);
        id=i;B=l/SZ;
    }
    bool operator < (const Q& b)const
    {
        if(B!=b.B)return B<b.B;
        return r<b.r;
    }
}q[maxn];
ll cur_ans=0,ans[maxn];
void add(int l,int r,int x,bool d)
{
}
void sub(int l,int r,int x,bool d)
{
}
main()
{
    scanf("%d%d",&n,&k);
    SZ=(int)sqrt(n+0.5);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(a[i]==2)x=-x;
        b[i]=x;
    }
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+b[i];
    int m;scanf("%d",&m);
    for(int i=1;i<=m;i++)q[i].input(i);
    sort(q+1,q+m+1);
    for(int i=1,L=1,R=0;i<=m;i++)
    {
        while(R<q[i].r)add(L,R,b[R+1],1),R++;
        while(L>q[i].l)add(L,R,b[L-1],0),L--;
        while(R>q[i].r)sub(L,R-1,b[R],1),R--;
        while(L<q[i].l)sub(L+1,R,b[L],0),L++;
        ans[q[i].id]=cur_ans;
    }
    for(int i=1;i<=m;i++)printf("%I64d\n",ans[i]);
    return 0;
}
