#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n,m,t;
int a[maxn];
struct Q
{
    int id,k,x,y,v,add,p;
    void output()
    {
        printf("%d %d %d %d %d %d %d\n",id,k,x,y,v,add,p);
    }
}q[maxn*10],tmp[maxn*15];
int last[maxn];
set<int> s[maxn];
ll ans[maxn],bit[maxn];
void add(int x,ll d)
{
    for(int i=x;i<=maxn;i+=i&-i)bit[i]+=d;
}
ll query(int x)
{
    ll ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
bool cmp(Q &a,Q &b)
{
    if(a.p==b.p)return a.k<b.k;
    return a.p<b.p;
}
void solve(int l,int r)
{
    if(l==r)return ;
    int m=(l+r)>>1;
    solve(l,m),solve(m+1,r);
    int t=0;
    for(int i=l;i<=m;i++)
        if(!q[i].k)tmp[++t]=q[i],tmp[t].p=q[i].x;
    for(int i=m+1;i<=r;i++)if(q[i].k)
    {
        tmp[++t]=q[i],tmp[t].add=-1,tmp[t].p=q[i].x-1;
        tmp[++t]=q[i],tmp[t].add=1,tmp[t].p=q[i].y;
    }
    sort(tmp+1,tmp+t+1,cmp);
    for(int i=1;i<=t;i++)
    {
        if(!tmp[i].k)add(tmp[i].y,tmp[i].v);
        else ans[tmp[i].id]+=tmp[i].add*(query(tmp[i].y)-query(tmp[i].x-1));
    }
    for(int i=1;i<=t;i++)if(!tmp[i].k)add(tmp[i].y,-tmp[i].v);
}
bool check[maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(last[a[i]])q[++t]={0,0,i,last[a[i]],i-last[a[i]],0,0};
        last[a[i]]=i,s[a[i]].insert(i);
    }
    for(int i=1;i<=m;i++)
    {
        int type;scanf("%d",&type);
        if(type==2)
        {
            check[i]=1;
            int l,r;scanf("%d%d",&l,&r);
            q[++t]={i,1,l,r,0,0,0};
        }
        else
        {
            int x,v;scanf("%d%d",&x,&v);
            if(a[x]==v)continue;
            auto it=s[a[x]].lower_bound(x),it2=it;
            int tt=0;
            if(it!=s[a[x]].begin())
            {
                it2=it;--it2;
                tt=*it2;
                q[++t]={0,0,x,tt,tt-x,0,0};
            }
            it2=it;++it2;
            if(it2!=s[a[x]].end())
            {
                int k=*it2;
                q[++t]={0,0,k,x,x-k,0,0};
                if(tt)q[++t]={0,0,k,tt,k-tt,0,0};
            }
            s[a[x]].erase(x);tt=0;
            a[x]=v,s[a[x]].insert(x);
            it=s[a[x]].lower_bound(x);
            if(it!=s[a[x]].begin())
            {
                it2=it;--it2;
                tt=*it2;
                q[++t]={0,0,x,tt,x-tt,0,0};
            }
            it2=it;++it2;
            if(it2!=s[a[x]].end())
            {
                int k=*it2;
                q[++t]={0,0,k,x,k-x,0,0};
                if(tt)q[++t]={0,0,k,tt,tt-k,0,0};
            }
        }
    }
    //printf("%d\n",t);
    //for(int i=1;i<=t;i++)q[i].output();
    solve(1,t);
    for(int i=1;i<=m;i++)if(check[i])printf("%I64d\n",ans[i]);
    return 0;
}
/*
7 6
1 2 3 1 3 2 1
2 3 7
2 1 3
1 7 2
1 3 2
2 1 6
2 5 7
*/
