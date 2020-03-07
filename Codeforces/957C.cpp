#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,u;
int a[maxn];
int pos[maxn];
main()
{
    scanf("%d%d",&n,&u);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int cur=1;
    for(int i=1;i<=n;i++)
    {
        while(cur<=n && a[cur]-a[i]<=u)cur++;
        cur--;
        pos[i]=cur;
    }
    //for(int i=1;i<=n;i++)printf("%d ",pos[i]);puts("");
    double f=20.0;
    for(int i=1;i<=n-2;i++)
        if(pos[i]>i+1)f=min(f,(double)(a[i+1]-a[i])/(double)(a[pos[i]]-a[i]));
    if(f==20.0)puts("-1");
    else printf("%.12f\n",1-f);
    return 0;
}
