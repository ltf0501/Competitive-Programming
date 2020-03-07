#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
int a[maxn];
int deg[maxn];
int le[maxn],ri[maxn];
ll sum[maxn],val[maxn];
bool vis[maxn];
vector<int> g[maxn];
queue<int> q;
int n;
//int pos[maxn];
int bit[maxn];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]=max(bit[i],d);
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret=max(ret,bit[i]);
    return ret;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=a[n+1]=maxn;
    for(int i=1;i<=n;i++)
    {
        le[i]=query(n-a[i]+1);
        add(n-a[i]+1,i);
    }
    memset(bit,0,sizeof(bit));
    for(int i=n;i>=1;i--)
    {
        ri[i]=n-query(n-a[i]+1)+1;
        add(n-a[i]+1,n-i+1);
    }
    for(int i=1;i<=n;i++)
    {
        if(le[i]==0 && ri[i]==n+1)continue;
        int k;
        if(le[i]!=0 && ri[i]!=n+1)
        {
            if(a[le[i]]>a[ri[i]])k=ri[i];
            else k=le[i];
        }
        else if(le[i]!=0)k=le[i];
        else k=ri[i];
        deg[i]++,deg[k]++;
        g[k].push_back(i),g[i].push_back(k);
    }
    for(int i=1;i<=n;i++)if(deg[i]==1)q.push(i),vis[i]=1;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int v : g[x])if(!vis[v])
        {
            val[v]+=(sum[x]+1)*sum[v];
            sum[v]+=(sum[x]+1);
            deg[v]--;
            if(deg[v]==1)
            {
                val[v]+=sum[v]*(n-1-sum[v]);
                q.push(v);vis[v]=1;
            }
            break;
        }
    }
    //for(int i=1;i<=n;i++)printf("%d ",val[i]);puts("");
    int id=1;
    for(int i=2;i<=n;i++)if(val[i]>val[id])id=i;
    printf("%lld %d\n",2*(val[id]+n-1),id);
    return 0;
}
