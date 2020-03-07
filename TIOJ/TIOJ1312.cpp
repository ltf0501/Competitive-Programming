#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int p[maxn];
int n,m;
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)p[i]=i;
        for(int i=1;i<=m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            int a=finds(x),b=finds(y);
            if(a==b)continue ;
            if(a>b)swap(a,b);
            p[b]=a;
        }
        int x;scanf("%d",&x);
        printf("%d\n",finds(x));
    }

    return 0;
}
