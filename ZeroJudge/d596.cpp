#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int> G[10];
int check[10];
main()
{
    G[1].push_back(2);G[1].push_back(4);
    G[2].push_back(1);G[2].push_back(3);G[2].push_back(5);
    G[3].push_back(2);G[3].push_back(6);
    G[4].push_back(1);G[4].push_back(5);G[4].push_back(7);
    G[5].push_back(2);G[5].push_back(4);G[5].push_back(6);G[5].push_back(8);
    G[6].push_back(3);G[6].push_back(5);G[6].push_back(9);
    G[7].push_back(4);G[7].push_back(8);
    G[8].push_back(5);G[8].push_back(7);G[8].push_back(9);
    G[9].push_back(6);G[9].push_back(8);
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(check,0,sizeof(check));
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        for(int i=0;i<G[a].size();i++)
        {
            int v=G[a][i];
            check[v]=1;
        }
        for(int i=0;i<G[b].size();i++)
        {
            int v=G[b][i];
            check[v]=0;
        }
        for(int i=0;i<G[c].size();i++)
        {
            int v=G[c][i];
            check[v]=0;
        }
        int flag=0;
        for(int i=1;i<=9;i++)
        {
            if(check[i]){printf("%d ",i);flag=1;}
        }
        if(flag==0)printf("Empty");
        puts("");
    }
}
