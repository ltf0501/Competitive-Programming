#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
char c[maxn][maxn];
int n,m;
vector<int> v[maxn];
bool vis[maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(int j=1;j<=m;j++)
    {
        vector<int> v;
        for(int i=1;i<=n;i++)if(c[i][j]=='1')v.push_back(i);
        if(v.size()==1)vis[v[0]]=1;
    }
    bool flag=0;
    for(int i=1;i<=n;i++)if(!vis[i]){flag=1;break;}
    puts(flag ? "YES" : "NO");
    return 0;
}

