#include<cstdio>
using namespace std;
#define maxn 100000+10
int pa[maxn];

int findset(int x)
{
    return pa[x]!=x?pa[x]=findset(pa[x]):x;
}

main()
{
    int x,y;
    while(scanf("%d",&x)==1)
    {
        for(int i=0;i<=maxn;i++)pa[i]=i;
        int ans=0;
        while(x!=-1)
        {
            scanf("%d",&y);
            x=findset(x);y=findset(y);
            if(x==y)ans++;
            else pa[x]=y;
            scanf("%d",&x);
        }
        printf("%d\n",ans);
    }
    return 0;
}
