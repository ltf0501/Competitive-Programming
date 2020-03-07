#include<bits/stdc++.h>
using namespace std;

main()
{
    int r,d,n;scanf("%d%d%d",&r,&d,&n);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x,y,R;scanf("%d%d%d",&x,&y,&R);
        if(2*R>d)continue;
        int dis=x*x+y*y;
        if((R+r-d)*(R+r-d)<=dis && dis<=(r-R)*(r-R))cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}

