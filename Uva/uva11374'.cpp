// File Name: 11374.cpp
// Author: zlbing
// Created Time: 2013/2/6 13:29:09

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include <queue>
using namespace std;
#define MAXN 100000
const int INF=1e9;
struct Edge{
    int from,to,dist;
};
struct HeapNode{
    int d,u;
    bool operator <(const HeapNode &rhs)const{
        return d>rhs.d;
    }
};
struct Dijkstra{
    int n,m;//点和边数
    vector<Edge>edges;//边列表
    vector<int>G[MAXN];//每个节点出发的边编号（从0开始编号）
    bool done[MAXN];//是否永久标记
    int d[MAXN];//s到各个点的距离
    int p[MAXN];//最短路中的上一条边

    void init(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++)G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int dist)
    {
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);
    }
    void dijkstra(int s)
    {
        priority_queue<HeapNode> Q;
        for(int i=0;i<n;i++)d[i]=INF;
        d[s]=0;
        memset(done,0,sizeof(done));
        Q.push((HeapNode){0,s});
        while(!Q.empty())
        {
            HeapNode x=Q.top();Q.pop();
            int u=x.u;
            if(done[u])continue;
            done[u]=true;
            for(int i=0;i<G[u].size();i++)
            {
                Edge& e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist)
                {
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
};
int N,S,E,M,K;
Dijkstra solver;
int d1[MAXN],d2[MAXN];
int p1[MAXN],p2[MAXN];
void printA(int k)
{
    if(k==S){
        printf("%d",k+1);
        return ;
    }
    int t=p1[k];
    Edge& e=solver.edges[t];
    printA(e.from);
    printf(" %d",k+1);
}
void printB(int k)
{
    if(k==E)
    {
        printf(" %d",k+1);
        return;
    }
    printf(" %d",k+1);
    int t=p2[k];
    Edge& e=solver.edges[t];
    printB(e.from);
}
int main(){
    int count=0;
    while(~scanf("%d%d%d",&N,&S,&E))
    {
        if(count++)printf("\n");

        S--,E--;
        solver.init(N);
        scanf("%d",&M);
        int a,b,c;
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            a--,b--;
            solver.AddEdge(a,b,c);
            solver.AddEdge(b,a,c);
        }
        solver.dijkstra(S);
        for(int i=0;i<N;i++){
            d1[i]=solver.d[i];
            p1[i]=solver.p[i];
        }
        solver.dijkstra(E);
        for(int i=0;i<N;i++){
            d2[i]=solver.d[i];
            p2[i]=solver.p[i];
        }
        scanf("%d",&K);
        int ans=d1[E];
        int Acomercial=-1;
        int Bcomercial=-1;
        for(int i=0;i<K;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            a--,b--;
            if(ans>d1[a]+c+d2[b])
            {
                ans=d1[a]+c+d2[b];
                Acomercial=a;
                Bcomercial=b;
            }
            if(ans>d1[b]+c+d2[a])
            {
                ans=d1[b]+c+d2[a];
                Acomercial=b;
                Bcomercial=a;
            }
        }
        if(Acomercial==-1)
        {
            printA(E);
            printf("\n");
            printf("Ticket Not Used\n");
            printf("%d\n",ans);
        }
        else{
            printA(Acomercial);
            printB(Bcomercial);
            printf("\n");
            printf("%d\n",Acomercial+1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
