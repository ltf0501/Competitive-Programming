#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
vector<int> g1[maxn],g2[maxn];
int n,m;
bool flag[maxn],rem[maxn];
int cur=1;
void umr()
{
    while(cur<=n && rem[cur])cur++;
    if(cur>n)return ;
    int u=cur++;
    flag[u]=1,rem[u]=1;
    for(int v : g1[u])rem[v]=1;
    umr();
    for(int v : g2[u])
        if(flag[v]){flag[u]=0;return ;}
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g1[x].push_back(y),g2[y].push_back(x);
    }
    umr();
    int num=0;
    for(int i=1;i<=n;i++)
        if(flag[i])num++;
    printf("%d\n",num);
    for(int i=1;i<=n;i++)
        if(flag[i])printf("%d ",i);
    return 0;
}
