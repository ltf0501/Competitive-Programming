#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn];
main()
{
    int n;scanf("%d",&n);
    int mx=-maxn;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
    int x=0,y=0,z=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==mx-2)x++;
        else if(a[i]==mx-1)y++;
        else z++;
    }
    if(!x)
    {
        printf("%d\n",n);
        for(int i=1;i<=y;i++)printf("%d ",mx-1);
        for(int i=1;i<=z;i++)printf("%d ",mx);
        return 0;
    }
    //printf("%d %d %d\n",x,y,z);
    int ans=x+y+z-2*max(y/2,min(x,z));
    printf("%d\n",ans);
    if(y/2>=min(x,z))
    {
        x+=y/2,z+=y/2;
        y&=1;
    }
    else
    {
        int t=min(x,z);
        y+=2*t;
        x-=t,z-=t;
    }
    for(int i=1;i<=x;i++)printf("%d ",mx-2);
    for(int i=1;i<=y;i++)printf("%d ",mx-1);
    for(int i=1;i<=z;i++)printf("%d ",mx);
    return 0;
}
