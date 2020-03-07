#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int G[52][52],c[52];
int n;
int id(char a,char b)
{
    return (a-'A')*2+(b=='+'?1:0);
}
void connect(char a1,char a2,char b1,char b2)
{
    if(a1=='0' || b1=='0')return;
    int u=id(a1,a2)^1;
    int v=id(b1,b2);
    G[u][v]=1;
}
bool dfs(int u)//判斷是否包含u的環
{
    c[u]=-1;
    for(int v=0;v<52;v++)
    {
        if(G[u][v])
        {
            if(c[v]<0)return true;
            if(!c[v] && dfs(v))return true;
        }
    }
    c[u]=1;
    return false;
}
bool find_circle()
{
    memset(c,0,sizeof(c));
    for(int u=0;u<52;u++)if(dfs(u))return true;
    return false;
}
main()
{
    while(scanf("%d",&n)==1 && n)
    {
        memset(G,0,sizeof(G));
        while(n--)
        {
            char s[10];
            scanf("%s",s);

            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)if(i!=j)
                    connect(s[i*2],s[i*2+1],s[j*2],s[j*2+1]);
        }
        if(find_circle())puts("unbounded");
        else puts("bounded");
    }
    return 0;
}
/*
3
A+00A+A+ 00B+D+A- B-C+00C+
1
K+K-Q+Q

bounded
unbounded
*/
