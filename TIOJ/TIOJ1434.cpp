#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
pii a[1005];
main()
{
    int n,m;scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for(int i=0;i<m;i++)scanf("%d%d",&a[i].S,&a[i].F);
        sort(a,a+m);
        int now=0;
        bool flag=1;
        for(int i=0;i<m;i++)
        {
            now+=a[i].S;
            if(now>a[i].F){puts("unschedulable");flag=0;break;}
        }
        if(flag==1)puts("schedulable");
    }
    return 0;
}
