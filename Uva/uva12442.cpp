#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> edges,sum;
vector<bool> vis;
int dfs(int s)
{
    if(vis[s]) return 0;
    vis[s]=true;
    int tot=1;
    if(edges[s]!=-1 &&vis[edges[s]]==false)
    {
        tot=(1+dfs(edges[s]));
        vis[edges[s]]=false;
    }
    return sum[s]=tot;
}
int main()
{
    int cas;
    cin>>cas;
    for(int cc=1; cc<=cas; cc++)
    {
        int n;
        cin>>n;
        edges.assign(n+5,-1);
        vis.assign(n+5,false);
        sum.assign(n+5,-1);
        for(int i=0; i<n; i++)
        {
            int a,b;
            cin>>a>>b;
            edges[a]=b;
        }
        int maxn=0,ans=0,tmp;
        for(int i=1; i<=n; i++)
        {
            tmp=0;
            vis[i-1]=false;
            if(sum[i]==-1) tmp=dfs(i);
            if(tmp>maxn)
            {
                ans=i;
                maxn=tmp;
            }
        }
        printf("Case %d: %d\n",cc,ans);
    }
    return 0;

}
