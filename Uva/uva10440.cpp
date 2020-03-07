#include<cstdio>
#include<algorithm>
using namespace std;
#define maxm 1440+10
main()
{
    int c,n,t,m,car[maxm];
    scanf("%d",&c);
    while(c--)
    {
        int tot=0,num=0;
        scanf("%d %d %d",&n,&t,&m);
        for(int i=1;i<=m;i++)scanf("%d",&car[i]);
        if(n>=m){tot=car[m]+t;num=1;}
        else
        {
            if(m%n==0)
            {
                num=m/n;
                for(int i=n;i<=m;i+=n)
                {
                    tot=max(tot,car[i]);
                    tot+=2*t;
                }
            }
            else
            {
                num=m/n+1;
                tot=car[m%n]+2*t;
                for(int i=m%n+n;i<=m;i+=n)
                {
                tot=max(tot,car[i]);
                tot+=2*t;
                }
            }

            tot-=t;
        }
        printf("%d %d\n",tot,num);
    }
    return 0;
}
