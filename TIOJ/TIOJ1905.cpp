#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
#define INF 1000000007
#define pii pair<int,int>
#define F first
#define S second
ll a[maxn];
int n;
//map<int,int> mp;
vector<int> v;
int cur_id[maxn],nxt[maxn];
set<int> s;
int seg[maxn<<2];
inline void push_up(int o){seg[o]=min(seg[o<<1],seg[o<<1|1]);}
void build(int l,int r,int o)
{
    if(l==r){seg[o]=cur_id[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
int pos,vv;
void update(int l,int r,int o)
{
    if(l==r){seg[o]=vv;return ;}
    int m=(l+r)>>1;
    if(pos<=m)update(l,m,o<<1);
    else update(m+1,r,o<<1|1);
    push_up(o);
}
int ql,qr;
int query(int l,int r,int o)
{
    if(ql<=l && r<=qr)return seg[o];
    int m=(l+r)>>1;
    int ret=maxn;
    if(ql<=m)ret=min(ret,query(l,m,o<<1));
    if(qr>m)ret=min(ret,query(m+1,r,o<<1|1));
    return ret;
}
vector<int> inc[maxn],dc[maxn];
vector<int> pro_inc[maxn],pro_dec[maxn];
vector<pii> q[maxn];
int bit[maxn],ans[maxn*3];
inline void modify(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]=min(bit[i],d);
}
inline int que(int x)
{
    int ret=INF;
    for(int i=x;i;i-=i&-i)ret=min(ret,bit[i]);
    return ret;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
        s.insert(a[i]);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    int c=v.size();
    for(int i=1;i<=n;i++)cur_id[i]=maxn;
    for(int i=n;i>=1;i--)
    {
        int tt=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        nxt[i]=cur_id[tt];
        cur_id[tt]=i;
    }
    build(1,c,1);
    for(int i=1;i<=n;i++)
        pro_inc[i].push_back(i),
        pro_dec[i].push_back(i);
    for(int i=1;i<=n;i++)
    {
        int ss=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        pos=ss,vv=nxt[i];
        update(1,c,1);
        for(int k : pro_inc[i])
        {
            ql=lower_bound(v.begin(),v.end(),a[k])-v.begin()+1;
            if(inc[k].empty())qr=c;
            else
            {
                int m=(a[k]+a[inc[k].back()])>>1;
                auto it=--s.upper_bound(m);
                qr=lower_bound(v.begin(),v.end(),*it)-v.begin()+1;
            }
            int tmp=query(1,c,1);
            if(tmp!=maxn)
            {
                inc[k].push_back(tmp);
                if(a[tmp]!=a[k])pro_inc[tmp].push_back(k);
            }
        }
        for(int k : pro_dec[i])
        {
            qr=lower_bound(v.begin(),v.end(),a[k])-v.begin()+1;
            if(dc[k].empty())ql=1;
            else
            {
                int m=(a[k]+a[dc[k].back()])>>1;
                auto it=s.lower_bound(m);
                ql=lower_bound(v.begin(),v.end(),*it)-v.begin()+1;
            }
            int tmp=query(1,c,1);
            if(tmp!=maxn)
            {
                dc[k].push_back(tmp);
                if(a[tmp]!=a[k])pro_dec[tmp].push_back(k);
            }
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        printf("%d: ",i);
        for(int j : inc[i])printf("%d ",j);puts("");
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d: ",i);
        for(int j : dc[i])printf("%d ",j);puts("");
    }
    */
    int Q;scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        int l,r;scanf("%d%d",&l,&r);
        q[l].push_back(pii(r,i));
    }
    for(int i=1;i<=n;i++)bit[i]=INF;
    for(int i=n;i>=1;i--)
    {
        for(int k : inc[i])modify(k,abs(a[k]-a[i]));
        for(int k : dc[i])modify(k,abs(a[k]-a[i]));
        for(pii v : q[i])ans[v.S]=que(v.F);
    }
    for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
    return 0;
}
