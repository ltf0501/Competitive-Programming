#include<bits/stdc++.h>
using namespace std;
bool vis[2][1<<22];
int n,m,S;
void dfs(bool type,int x)
{
    if(vis[type][x])return ;
    //printf("%d %d\n",type,x);
    vis[type][x]=1;
    if(!type){dfs(1,x);return ;}
    for(int i=0;i<n;i++)
        if(!(x&(1<<i)))dfs(1,x|(1<<i));
    dfs(0,S^x);
}
main()
{
    scanf("%d%d",&n,&m);
    S=(1<<n)-1;
    for(int i=0;i<=S;i++)vis[0][i]=1;
    for(int i=1;i<=m;i++)
    {
        int x;scanf("%d",&x);
        vis[0][x]=0;
    }
    int cnt=0;
    for(int i=0;i<=S;i++)
        if(!vis[0][i])dfs(0,i),cnt++;
    printf("%d\n",cnt);
    return 0;
}
