#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
char g[35][35];
int h,w;
vector<ll> s;
ll ans=0,cnt=0;
const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
bool dfs(int stx,int sty,int x,int y)
{
    g[x][y]='#';
    for(int i=0;i<=3;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(!(0<=a && a<h && 0<=b && b<w))continue;
        if(a==stx && b==sty)cnt++;
        if(cnt==2)return 1;
        if(g[a][b]=='#')continue;
        ans++;
        return dfs(stx,sty,a,b);
    }
    return 0;
}
main()
{
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++)scanf("%s",g[i]);
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)
        if(g[i][j]=='.')
        {
            if(dfs(i,j,i,j))s.push_back(ans+1);
            ans=0,cnt=0;
        }
    ll y=0,z=1;
    for(ll v : s)y+=v,z*=v;
    printf("%d %lld %llu\n",s.size(),y,z);
    return 0;
}
/*
3 3
...
.#.
...
*/
