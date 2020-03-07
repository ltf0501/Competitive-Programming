#include<bits/stdc++.h>
using namespace std;
char s[300][10];
vector<int> v[60];
bool vis[300];
int ans[300][300];
int dir[300][300];
int val(char c)
{
    if(c=='-')return 0;
    if('a'<=c && c<='z')return c-'a'+1;
    return c-'A'+31;
}
char rev(char c)
{
    if(c=='-')return c;
    if('a'<=c && c<='z')return c-'a'+'A';
    return c-'A'+'a';
}
int r,c;
bool dfs(int ri,int ci)
{
    if(ri==r)return 1;
    if(ci==c)return dfs(ri+1,0);
    char u,l;
    u=!ri ? 0 : rev(s[ans[ri-1][ci]][(dir[ri-1][ci]+3)%4]);
    l=!ci ? 0 : rev(s[ans[ri][ci-1]][(dir[ri][ci-1]+2)%4]);
    int k=val(l);
    for(int i=0;i<v[k].size();i+=2)
    {
        int t=v[k][i];
        if(vis[t])continue;
        ans[ri][ci]=t;
        dir[ri][ci]=v[k][i+1];
        if(s[ans[ri][ci]][(dir[ri][ci]+1)%4]!=u)continue;
        if(ci==c-1)
        {
            if(s[ans[ri][ci]][(dir[ri][ci]+2)%4]!='-')continue;
        }
        if(ri==r-1)
        {
            if(s[ans[ri][ci]][(dir[ri][ci]+3)%4]!='-')continue;
        }
        vis[t]=1;
        if(dfs(ri,ci+1))return 1;
        vis[t]=0;
    }
    return 0;
}
main()
{
    while(~scanf("%d%d",&r,&c) && r+c)
    {
        for(int i=0;i<60;i++)v[i].clear();
        for(int i=0;i<r*c;i++)scanf(" %8[^\n]",s[i]);
        for(int i=0;i<r*c;i++)for(int j=0;j<4;j++)
        {
            int p=val(s[i][j]);
            v[p].push_back(i),v[p].push_back(j);
        }
        fill(vis,vis+r*c,0);
        dfs(0,0);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)printf("%c",s[ans[i][j]][4+dir[i][j]]);
            puts("");
        }
        puts("");
    }
    return 0;
}
