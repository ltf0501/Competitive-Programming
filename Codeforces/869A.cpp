#include<bits/stdc++.h>
using namespace std;
#define maxn 4000010
bool vis[maxn];
int x[2010],y[2010];
main()
{
    int n;scanf("%d",&n);
    int mx=0;
    for(int i=1;i<=n;i++)scanf("%d",&x[i]),vis[x[i]]=1,mx=max(mx,x[i]);
    for(int i=1;i<=n;i++)scanf("%d",&y[i]),vis[y[i]]=1,mx=max(mx,y[i]);
    int cnt=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        if((x[i]^y[j])<=mx && vis[x[i]^y[j]])cnt++;
    //printf("%d\n",cnt);
    puts(cnt%2==1 ? "Koyomi" : "Karen");
    return 0;
}

