#include<bits/stdc++.h>
using namespace std;
#define maxh 100010
int n,h,x[3];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&h);
        bitset<maxh> b;
        b[0]=1;
        while(n--)
        {
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            b=(b<<x)|(b<<y)|(b<<z);
        }
        bool ok=0;
        for(int i=h;i>=1;i--)
        {
            if(b[i]){printf("%d\n",i);ok=1;break;}
        }
        if(!ok)puts("no solution");
    }
    return 0;
}
