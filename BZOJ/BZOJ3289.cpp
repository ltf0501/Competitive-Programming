#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
#define SZ 225
struct P
{
    int l,r,block,id;
    bool operator < (const P& b)const
    {
        if(block!=b.block)return block<b.block;
        return r<b.r;
    }
}q[maxn];
vector<int> v;
int a[maxn],ans[maxn];
int cur_ans=0,n,m;
int bit[maxn];
void update(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
void add(int x,bool c)
{
    if(c)cur_ans+=query(n)-query(x);
    else cur_ans+=query(x-1);
    update(x,1);
}
void sub(int x,bool c)
{
    if(c)cur_ans-=query(n)-query(x);
    else cur_ans-=query(x-1);
    update(x,-1);
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int l,r;scanf("%d%d",&l,&r);
        q[i]={l,r,l/SZ,i};
    }
    sort(q+1,q+m+1);
    for(int i=1,L=1,R=0;i<=m;i++)
    {
        while(R<q[i].r)add(a[++R],1);
        while(L>q[i].l)add(a[--L],0);
        while(R>q[i].r)sub(a[R--],1);
        while(L<q[i].l)sub(a[L++],0);
        ans[q[i].id]=cur_ans;
    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}
