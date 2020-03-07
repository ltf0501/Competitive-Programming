#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int parent[1024], weight[1024];
int deg[1024];
int findp(int x)//對x找該連通的一個爸爸
{
    return (parent[x]==x)?x:parent[x]=findp(parent[x]);
}

bool joint(int x,int y)//判斷是否需要合併成一連通快
{
    x=findp(x);y=findp(y);
    if(x==y)return false;
    if (weight[x]>weight[y]){weight[x]+=weight[y];parent[y]=x;}
    else{weight[y]+=weight[x];parent[x]=y;}
    return true;
}

main()
{
    int N,E,T,x,y,cas=0;
    while(scanf("%d %d %d",&N,&E,&T)==3&&(N+E+T))
    {
        for(int i=1;i<=N;i++){parent[i]=i;weight[i]=1;deg[i]=0;}
        int com=N;//連通的數量
        for(int i=0;i<E;i++)
        {
            scanf("%d %d",&x,&y);
            deg[x]++;deg[y]++;
            if(joint(x,y))com--;
        }
        for (int i=1;i<=N;i++)
        {
            if (weight[i]==1&&findp(i)==i)com--;
        }
        int ret=E,odd[1024];
        memset(odd,0,sizeof(odd));
        ret+=com>0 ? com-1 : 0;
        for (int i=1;i<=N;i++)
        {
            if (deg[i]&1)odd[findp(i)]++;
        }
        for (int i = 1; i <= N; i++)
        {
            if (odd[i]>=4)ret+=odd[i]/2 - 1;
        }
        printf("Case %d: %d\n", ++cas, ret * T);

    }
    return 0;
}
