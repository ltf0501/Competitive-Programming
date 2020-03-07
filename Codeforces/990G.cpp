#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200001
#define pii pair<int,int>
#define F first
#define S second
vector<int> v[maxn];
vector<pii> edge[maxn];
int n;
int a[maxn];
ll cur,ans[maxn];
int p[maxn],sz[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void Union(int x,int y)
{
    int a=finds(x),b=finds(y);
    if(a==b)return ;
    cur+=1ll*sz[a]*sz[b];
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b],p[b]=a;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        v[a[i]].push_back(i);
    }
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        edge[__gcd(a[x],a[y])].push_back(pii(x,y));
    }
    for(int i=maxn-1;i;i--)
    {
        cur=0;
        for(int j=i;j<maxn;j+=i)
        {
            for(int s : v[j])p[s]=s,sz[s]=1,cur++;
            if(j>i)ans[i]-=ans[j];
        }
        for(int j=i;j<maxn;j+=i)
        {
            for(pii e : edge[j])Union(e.F,e.S);
        }
        ans[i]+=cur;
    }
    for(int i=1;i<maxn;i++)
        if(ans[i])printf("%d %lld\n",i,ans[i]);
    return 0;
}
