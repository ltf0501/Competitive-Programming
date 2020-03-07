#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 100000+5
int p[maxn];
vector<int> Set[maxn];
int findset(int x)
{
    return p[x]==x ? x : (p[x]=findset(p[x]));
}
void Union(int x,int y)
{
    x=findset(x);y=findset(y);
    if(x==y)return ;
    if(Set[x].size()>Set[y].size())
    {
        for(int i=0;i<Set[y].size();i++)
        {
            Set[x].push_back(Set[y][i]);
            p[Set[y][i]]=x;
        }
        Set[y].clear();
    }
    else
    {
        for(int i=0;i<Set[x].size();i++)
        {
            Set[y].push_back(Set[x][i]);
            p[Set[x][i]]=y;
        }
        Set[x].clear();
    }
}
main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
        {
            p[i]=i;
            Set[i].clear();
            Set[i].push_back(i);
        }
        while(m--)
        {
            int com;
            scanf("%d",&com);
            if(com==1)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                Union(x,y);
                /*
                for(int i=1;i<=n;i++)
                {
                    for(int j=0;j<Set[i].size();j++)printf("%d ",Set[i][j]);
                    puts("");
                }
                */
            }
            else if(com==2)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                int u=x;
                x=findset(x);y=findset(y);
                if(x==y)continue;
                vector<int>::iterator iter=Set[x].begin();
                int cnt=0;
                while(*iter!=u){iter++;cnt++;}
                Set[x].erase(iter);
                Set[y].push_back(u);
                p[x]=findset(y);
                if(cnt==0)
                {
                    for(int i=0;i<Set[x].size();i++)
                    {
                        Set[Set[x][0]].push_back(Set[x][i]);
                        p[Set[x][i]]=Set[x][0];
                    }
                }
                /*
                for(int i=1;i<=n;i++)
                {
                    for(int j=0;j<Set[i].size();j++)printf("%d ",Set[i][j]);
                    puts("");
                }
                */
            }
            else if(com==3)
            {
                int x;scanf("%d",&x);
                int sum=0;
                x=findset(x);
                for(int i=0;i<Set[x].size();i++)
                {
                   // printf("%d ",Set[x][i]);
                    sum+=Set[x][i];
                }
                printf("%d %d\n",Set[x].size(),sum);
            }
        }
    }
    return 0;
}
