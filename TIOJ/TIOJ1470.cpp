#include<bits/stdc++.h>
using namespace std;
#define maxn 210
int g[maxn][maxn];
int n,m;
bool check(int x,int y)
{
    if(x==1 || y==1)return 0;
    if(x%2)return g[(x-1)/2][y/2]<g[(x+1)/2][y/2];
    else return g[x/2][(y-1)/2]<g[x/2][(y+1)/2];
}
int h[maxn];
struct node{int x,h;}s[maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)scanf("%d",&g[i][j]);
    int ans=0;
    for(int i=2;i<=2*n;i++)
    {
        for(int j=1;j<=2*m;j++)
            h[j]=((i+j)%2 && !check(i,j)) ? 0 : h[j]+1;
        if(i%2)continue;
        int sz=0;
        for(int j=1;j<=2*m;j++)
        {
            while(sz>=2 && s[sz-2].h>=h[j])sz--;
            if(sz && s[sz-1].h>h[j])s[sz-1].h=h[j];
            if(j%2)continue;
            s[sz++]=(node){j,h[j]};
            for(int k=0;k<sz;k++)
                ans=max(ans,((j-s[k].x+2)/2)*((s[k].h+1)/2));
        }
    }
    printf("%d\n",ans);
    return 0;
}
