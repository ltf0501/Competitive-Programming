#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int MAXN=333;

int color[MAXN];
vector<int >G[MAXN];
queue<int >q;

bool Bjudge()
{
    memset(color,-1,sizeof(color));
    while(!q.empty())
        q.pop();
    q.push(1);
    color[1]=0;
    while(!q.empty())
    {
        int i=q.front();
        q.pop();
        for(int j=0;j<G[i].size();j++)
        {
            if(color[G[i][j]]==-1){
                color[G[i][j]]=1-color[i];
                q.push(G[i][j]);
            }else if(color[G[i][j]]==color[i])
                return false;
        }
    }
    return true;
}

int main()
{
    int n,a,b;
    while(~scanf("%d",&n))
    {
        if(!n)
            return 0;
        for(int i=1;i<=n;i++)
            G[i].clear();
        do{
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }while(a&&b);

        if(Bjudge())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
/*
附上一组“YES”的数据
6
1 2
1 4
1 6
2 3
2 5
3 4
3 6
4 5
5 6
0 0
*/
