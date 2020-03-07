#include<bits/stdc++.h>
using namespace std;
#define maxn 23500
#define maxq 200010
const int SZ=90;
struct blo
{
    int l,r,block,id;
    bool operator < (const blo& b)const
    {
        if(block!=b.block)return block<b.block;
        return r<b.r;
    }
}que[maxq];
int n,m;
int bit[maxn],a[maxn];
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
int ans[maxq];
int cur_ans=0;
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        que[i]={x,y,x/SZ,i};
    }
    sort(que+1,que+m+1);
    for(int i=1,L=1,R=0;i<=m;i++)
    {
        while(R<que[i].r)add(a[++R],1);
        while(L>que[i].l)add(a[--L],0);
        while(R>que[i].r)sub(a[R--],1);
        while(L<que[i].l)sub(a[L++],0);
        ans[que[i].id]=cur_ans;
    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}
