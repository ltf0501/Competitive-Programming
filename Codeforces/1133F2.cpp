#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
struct E
{
    int u,v;
};
vector<E> edge;
vector<int> ans;
int deg[maxn];
int p[maxn],sz[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
bool Union(int x,int y)
{
    int a=p[x],b=p[y];
    if(a==b)return 0;
    if(sz[a]<sz[b])swap(a,b);
    p[b]=a,sz[a]+=sz[b];
    return 1;
}
main()
{
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    int cnt=0;
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        edge.push_back({x,y});
        if((x==1 || y==1) && cnt<k)ans.push_back(i),cnt++,Union(x,y);
    }
    if((int)ans.size()<k)return 0*puts("NO");
    for(int i=0;i<m;i++)
    {
        E e=edge[i];
        if(e.u==1 || e.v==1) continue;
        if(Union(e.u,e.v))cnt++,ans.push_back(i);
        if(cnt==n-1)break ;
    }
    printf("%d\n",cnt);
    if(cnt<n-1)return 0*puts("NO");
    puts("YES");
    for(int i : ans)printf("%d %d\n",edge[i].u,edge[i].v);
    return 0;
}
/*
7 10 2
7 1
1 3
5 2
6 1
6 5
3 7
5 7
1 2
5 1
1 4

YES
6 5
2 5
7 5
1 7
3 7
4 1
*/
