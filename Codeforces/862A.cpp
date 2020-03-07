#include<bits/stdc++.h>
using namespace std;
bool vis[105];
main()
{
    int n,x;scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
    {
        int k;scanf("%d",&k);
        vis[k]++;
    }
    int cnt=0;
    for(int i=0;i<x;i++)if(!vis[i])cnt++;
    if(vis[x])cnt++;
    printf("%d\n",cnt);
    return 0;
}

