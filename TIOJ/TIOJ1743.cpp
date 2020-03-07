#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define INF 1000000000
#define ALL(v) v.begin(),v.end()
struct P
{
    int l,r,id;
    bool operator < (const P& b)const
    {
        if(l==b.l)return r>b.r;
        return l<b.l;
    }
}a[maxn],tmp[maxn];
bool cmp(P a,P b){return a.id<b.id;}
int f[18][maxn<<1];
int n,m,cnt;
vector<int> v;
stack<P> ss;
void pre()
{
    int cur=INF;
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
        if(a[i].r<cur)tmp[++cnt]=a[i],cur=a[i].r;
    for(int i=1;i<=cnt;i++)ss.push(tmp[i]);
    for(int i=1;i<=cnt;i++){tmp[i]=ss.top();ss.pop();}
    //printf("%d\n",cnt);
    //for(int i=1;i<=cnt;i++)printf("%d %d\n",tmp[i].l,tmp[i].r);
    for(int k=0;k<=17;k++)for(int i=1;i<=m+1;i++)f[k][i]=INF;
    for(int i=m,j=cnt;i>=1;i--)
    {
        f[0][i]=f[0][i+1];
        if(tmp[j].l==i)f[0][i]=min(f[0][i],tmp[j].r);
        for(int k=1;k<=17;k++)
            if(f[k-1][i]!=INF)f[k][i]=f[k-1][f[k-1][i]+1];
        while(tmp[j].l==i)j--;
    }
    /*
    for(int i=1;i<=m;i++)
    {
        for(int k=0;k<4;k++)printf("%d ",f[k][i]);puts("");
    }
    */
}
int cal(int l,int r)
{
    int ret=0;
    for(int i=17;i>=0;i--)
        if(f[i][l]<=r)l=f[i][l]+1,ret+=(1<<i);
    return ret;
}
struct Q
{
    int x,pos;
    Q(int x,int pos):x(x),pos(pos){}
    bool operator < (const Q& b)const
    {
        return x<b.x;
    }
};
set<Q> s;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].id=i;
        v.push_back(a[i].l),v.push_back(a[i].r);
    }
    sort(ALL(v));
    v.resize(unique(ALL(v))-v.begin());
    m=v.size();
    //printf("%d\n",m);
    for(int i=1;i<=n;i++)
    {
        a[i].l=lower_bound(ALL(v),a[i].l)-v.begin()+1;
        a[i].r=lower_bound(ALL(v),a[i].r)-v.begin()+1;
    }
    pre();
    int ans=cal(1,m);
    printf("%d\n",ans);
    sort(a+1,a+n+1,cmp);
    Q p=Q(0,-1),q=Q(m+1,1);
    s.insert(p),s.insert(q);
    for(int i=1;i<=n;i++)
    {
        Q l=Q(a[i].l,1),r=Q(a[i].r,-1);
        auto itl=s.lower_bound(l);
        auto itr=s.upper_bound(r);
        if(itl!=itr || itr->pos==-1)continue;
        itl--;
        int ll=itl->x+1,rr=itr->x-1;
        if(cal(ll,a[i].l-1)+cal(a[i].r+1,rr)+1==cal(ll,rr))
        {
            printf("%d ",i);
            s.insert(l),s.insert(r);
        }
    }
    return 0;
}

