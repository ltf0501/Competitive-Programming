#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 1000000
int mins;
int G[30][30];
int vis[30],t,m;
void dfs(int start,int now,int len)
{
    if(len>mins)return ;
    for(int i=0;i<26;i++)
    {
        if(!vis[i] && G[now][i])
        {
            vis[i]=1;
            dfs(start,i,len+1);
            vis[i]=0;
        }
        else
        {
            if(G[now][i] && i==start && len<mins)mins=len;
        }
    }
}

main()
{
    while(scanf("%d",&m)==1)
    {
        memset(G,0,sizeof(G));
        memset(vis,0,sizeof(vis));
        char a[2];
        for(int i=1;i<=m;i++)
        {
            scanf("%s",a);
            int p=a[0]-'A',q=a[1]-'A';
            G[p][q]=1;
        }
        mins=inf;
        for(int i=0;i<26;i++)
        {
            vis[i]=1;
            dfs(i,i,1);
            vis[i]=0;
        }
        if(mins!=1000000)printf("%d\n",mins);
        else puts("0");
    }
    return 0;
}
