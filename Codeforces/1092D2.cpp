#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ALL(v) v.begin(),v.end()
int a[maxn];
vector<int> v,pos[maxn];
bool vis[maxn];
int p[maxn],sz[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
int cnt;
void Union(int x,int y)
{
    int a=finds(x),b=finds(y);
    if(a==b)return ;
    if(sz[a]<sz[b])swap(a,b);
    cnt-=(sz[a]%2),cnt-=(sz[b]%2);
    sz[a]+=sz[b],p[b]=a;
    cnt+=(sz[a]%2);
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
    sort(ALL(v));
    v.resize(unique(ALL(v))-v.begin());
    int m=v.size();
    for(int i=1;i<=n;i++)a[i]=lower_bound(ALL(v),a[i])-v.begin()+1,pos[a[i]].push_back(i);
    for(int i=1;i<=n;i++)sz[i]=1,p[i]=i;
    int now=0;
    for(int i=1;i<=m;i++)
    {
        for(int j : pos[i])
        {
            cnt++,now++;
            if(j>1 && vis[j-1])Union(j,j-1);
            if(j<n && vis[j+1])Union(j,j+1);
            vis[j]=1;
            //printf("%d: %d\n",j,cnt);
        }
        if(now<n && cnt!=0)return 0*puts("NO");
    }
    puts("YES");
    return 0;
}
