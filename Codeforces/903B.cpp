#include<bits/stdc++.h>
using namespace std;
#define INF 10000000
#define ll long long
main()
{
    int h1,a1,c1,h2,a2;scanf("%d%d%d%d%d",&h1,&a1,&c1,&h2,&a2);
    int ans=INF;
    for(int i=0;i<=10000;i++)
    {
        int h=h1+i*(c1-a2);
        ll t=(h+a2-1)/a2;
        if(t*a1>=h2)
        {
            ans=min(ans,(h2+a1-1)/a1+i);
			printf("%d\n",ans);
			for(int j=1;j<=i;j++)puts("HEAL");
			for(int j=1;j<=(h2+a1-1)/a1;j++)puts("STRIKE");
			return 0;
        }
    }
    return 0;
}
