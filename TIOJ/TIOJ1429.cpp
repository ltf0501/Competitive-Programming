#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define LL long long
#define maxn 100005
struct tnode
{
    LL left,right,dis,root,val,lead;
    tnode():left(0),right(0),dis(0),root(0),val(0),lead(0){};

}a[maxn];
LL sum[maxn],v[maxn],num[maxn],nxt[maxn],node[maxn];
LL ans,Left,Right,tree;
int n,m;
void Insert(int x,int y)
{
    tree++;
    v[tree]=y;
    nxt[tree]=node[x];
    node[x]=tree;
}
int mrg(int x,int y)
{
    if(!x)return y;
    if(!y)return x;
    if(a[x].val<a[y].val)swap(x,y);
    a[x].right=mrg(a[x].right,y);
    if(a[a[x].right].dis>a[a[x].left].dis)swap(a[x].left,a[x].right);
    if(a[x].right==0)a[x].dis=0;
    else a[x].dis=a[a[x].right].dis+1;
    return x;
}
main()
{
    ans=0;tree=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int b;
        scanf("%d%lld%lld",&b,&a[i].val,&a[i].lead);
        Insert(b,i);
    }
    for(int i=n;i>=1;i--)
    {
        a[i].root=i;sum[i]=a[i].val;num[i]=1;
        for(int z=node[i];z!=0;z=nxt[z])
        {
            a[i].root=mrg(a[i].root,a[v[z]].root);
            sum[i]+=sum[v[z]];
            num[i]+=num[v[z]];
        }
        while(sum[i]>m)
        {
            if(!a[i].root)break;
            LL k=a[i].root;
            sum[i]-=a[k].val;
            num[i]--;
            Left=a[k].left;Right=a[k].right;
            a[k].left=a[k].right=0;
            a[i].root=mrg(Left,Right);
        }
        ans=max(num[i]*a[i].lead,ans);
        //printf("%lld\n",ans);
    }
    printf("%lld",ans);
    return 0;
}
