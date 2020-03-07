#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 20000+10
main()
{
    int t;scanf("%d",&t);
    int g[maxn];
    while(t--)
    {
        int x,k;
        scanf("%d%d",&x,&k);
        g[0]=1;
        for(int i=1;i<=20000;i++)
        {
            if(i<k)
            {
                if(g[i-1]==0)g[i]=1;
                else g[i]=0;
            }
            else
            {
                if(g[i-1] && g[i-k])g[i]=0;
                else
                {
                    if(max(g[i-1],g[i-k])==1)g[i]=2;
                    else g[i]=1;
                }
            }
        }
        //for(int i=0;i<=10;i++)printf("%d ",g[i]);
        //printf("\n");
        int cnt=1;
        x++;
        while(g[x]!=0 && cnt<=10000)
        {
            x++,cnt++;
        }
        if(cnt>10000)printf("0\n");
        else printf("%d\n",cnt);
    }
    return 0;
}
