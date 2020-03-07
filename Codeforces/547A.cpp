#include<bits/stdc++.h>
using namespace std;
int m,h1,a1,x1,y1,h2,a2,x2,y2;
main()
{
    scanf("%d%d%d%d%d%d%d%d%d",&m,&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
    int cnt=0;
    while(h1!=a1 && cnt<=m)
    {
        h1=(1ll*h1*x1+y1)%m;
        cnt++;
    }
    if(cnt>m)return 0*puts("-1");

    int t=1,h1=(1ll*h1*x1+y1)%m;
    while(h1!=a1 && t<=m)
    {
        h1=(1ll*h1*x1+y1)%m;
        t++;
    }
    if(cnt>m)return 0*puts("-1");
    return 0;
}

