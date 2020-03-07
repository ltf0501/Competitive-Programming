#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 20000+10
int pa[maxn],d[maxn];

int findset(int x)
{
    if(pa[x]!=x)
    {
        int root=findset(pa[x]);
        d[x]+=d[pa[x]];
        return pa[x]=root;
    }
    else return x;
}
main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++){pa[i]=i;d[i]=0;}
        char c;
        while(cin >> c)
        {
            if(c=='O')break;
            if(c=='I')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                pa[x]=y;
                d[x]=abs(x-y)%1000;
            }
            if(c=='E')
            {
                int a;
                scanf("%d",&a);
                findset(a);
                printf("%d\n",d[a]);
            }
        }
    }
}
