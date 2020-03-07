#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int n;
int pos[maxn],b[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        pos[x]=i;
    }
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(pos[x]<=cur)printf("0 ");
        else printf("%d ",pos[x]-cur),cur=pos[x];
    }
    return 0;
}
