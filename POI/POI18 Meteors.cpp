#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll unsigned long long
int a[maxn];
int n,m,q;
vector<int> pos[maxn];
struct Q
{
    int l,r,val;
    void input(){scanf("%d%d%d",&l,&r,&val);}
}que[maxn];
vector<int> v;
int ans[maxn];
ll bit[maxn];
void add(int x,int d)
{
    for(int i=x;i<=maxn;i+=i&-i)bit[i]+=d;
}
ll query(int x)
{
    ll ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
int cur=0;
void gao(int s)
{
    while(cur<s)
    {
        cur++;
        if(que[cur].l<=que[cur].r)add(que[cur].l,que[cur].val),add(que[cur].r+1,-que[cur].val);
        else add(que[cur].l,que[cur].val),add(m+1,-que[cur].val),
             add(1,que[cur].val),add(que[cur].r+1,-que[cur].val);
    }
    while(cur>s)
    {
        if(que[cur].l<=que[cur].r)add(que[cur].l,-que[cur].val),add(que[cur].r+1,que[cur].val);
        else add(que[cur].l,-que[cur].val),add(m+1,que[cur].val),
             add(1,-que[cur].val),add(que[cur].r+1,que[cur].val);
        cur--;
    }
}
ll check(vector<int> v)
{
    ll ret=0;
    for(int i : v)ret+=query(i);
    return ret;
}
void solve(vector<int> &v,int l,int r)
{
    if(l==r)
    {
        for(int i : v)ans[i]=l;
        return ;
    }
    if(v.empty())return ;
    int m=(l+r)>>1;
    gao(m);
    vector<int> t[2];
    for(int i : v)
    {
        if(check(pos[i])>=a[i])t[0].push_back(i);
        else t[1].push_back(i);
    }
    solve(t[0],l,m),solve(t[1],m+1,r);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x;scanf("%d",&x);
        pos[x].push_back(i);
    }
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)que[i].input();
    for(int i=1;i<=n;i++)v.push_back(i);
    solve(v,1,q+1);
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==q+1)puts("NIE");
        else printf("%d\n",ans[i]);
    }
    return 0;
}
