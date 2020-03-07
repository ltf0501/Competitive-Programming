#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define inf 100000000
#define maxn 500+10
int N,S,E;
struct Edge
{
    int from,to,dist;
};
struct node
{
    int d,u;
    bool operator < (const node& rhs) const
    {
        return d>rhs.d;
    }
};
struct Dijk
{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int vis[maxn],d[maxn],p[maxn];

    void init(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++)G[i].clear();
        edges.clear();
    }

    void addedge(int from,int to,int dist)
    {
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);
    }

    void sol(int s)
    {
        priority_queue<node> Q;
        for(int i=0;i<n;i++)d[i]=inf;
        d[s]=0;
        memset(vis,0,sizeof(vis));
        Q.push((node){0,s});
        while(!Q.empty())
        {
            node x=Q.top();Q.pop();
            int u=x.u;
            if(vis[u])continue;
            vis[u]=1;
            for(int i=0;i<G[u].size();i++)
            {
                Edge& e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist)
                {
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    Q.push((node){d[e.to],e.to});
                }
            }
        }
    }
};
Dijk solver;
int f1[maxn],f2[maxn];
int p[maxn];
main()
{
    while(scanf("%d%d%d",&N,&S,&E)==3)
    {

        S--;E--;
        solver.init(N);
        int M,K;
        scanf("%d",&M);
        for(int i=1;i<=M;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);x--;y--;
            solver.addedge(x,y,z);
            solver.addedge(y,x,z);
        }
        solver.sol(S);
        for(int i=0;i<N;i++)
        {
            f1[i]=solver.d[i];
        }
        //solver.init(N);
        solver.sol(E);
        for(int i=0;i<N;i++)
        {
            f2[i]=solver.d[i];
            p[i]=solver.p[i];
        }
        p[E]=-1;
        /*
        for(int i=0;i<N;i++)printf("%d ",f1[i]);
        puts("");
        for(int i=0;i<N;i++)printf("%d ",f2[i]);
        puts("");

        for(int i=0;i<N;i++)printf("%d ",p[i]);
        puts("");
        */
        scanf("%d",&K);
        int s=f1[E],t=-1,q=-1;
        for(int i=1;i<=K;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);x--;y--;
            if(s>f1[x]+f2[y]+z)
            {
                s=f1[x]+f2[y]+z;
                t=x;q=y;
            }
            if(s>f1[y]+f2[x]+z)
            {
                s=f2[x]+f1[y]+z;
                t=y;q=x;
            }
        }
        int flag=0;
        if(t!=-1)
        {
            int x=S;
            while(x!=t)
            {
                if(!flag){printf("%d",x+1);flag=1;}
                else printf(" %d",x+1);
                x=solver.edges[p[x]].from;
            }
            if(x!=S)printf(" %d",x+1);
            else printf("%d",x+1);
            x=q;
            while(x!=E)
            {
                printf(" %d",x+1);
                x=solver.edges[p[x]].from;
            }
            printf(" %d\n",E+1);
            printf("%d\n%d\n",t+1,s);
        }
        else
        {
            int x=S;
            while(x!=E)
            {
                if(!flag){printf("%d",x+1);flag=1;}
                else printf(" %d",x+1);
                x=solver.edges[p[x]].from;
            }
            if(!flag)printf("%d",E+1);
            else printf(" %d",E+1);
            printf("\nTicket Not Used\n%d\n",s);
        }


    }
    return 0;
}
/*
4 1 4
4
1 2 2
1 3 3
2 4 4
3 4 5
1
2 4 3

1 2 4
2
5
*/
