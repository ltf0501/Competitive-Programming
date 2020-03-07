#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 2000+10
#define LL long long
int r,c;
LL x[maxn],y[maxn],m[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&r,&c);
        memset(x,0,sizeof(x));memset(y,0,sizeof(y));memset(m,0,sizeof(m));
        LL k;
        for(int i=1;i<=r;i++)
        {
            LL sum=0;
            for(int j=1;j<=c;j++)
            {
                scanf("%lld",&k);
                m[j]+=k;sum+=k;
            }
            x[i]=x[i-1]+sum;
        }
        for(int i=1;i<=c;i++)y[i]=y[i-1]+m[i];
        /*
        for(int i=1;i<=r;i++)printf("%d ",x[i]);
        puts("");
        for(int i=1;i<=c;i++)printf("%d ",y[i]);
        puts("");
        */
        LL tmp=0,totx,toty,ans=0;
        int ax=1,ay=1;
        for(int i=1;i<=r;i++)tmp+=(i-1)*(x[i]-x[i-1]);
        ans=tmp;
        for(int i=2;i<=r;i++)
        {
            tmp+=x[i-1]-(x[r]-x[i-1]);

            if(tmp<ans)
            {
                ans=tmp;ax=i;
            }
        }
        totx=ans;tmp=0;

        for(int i=1;i<=c;i++)tmp+=(i-1)*(y[i]-y[i-1]);
        ans=tmp;
        for(int i=2;i<=c;i++)
        {
            tmp+=y[i-1]-(y[c]-y[i-1]);
            if(tmp<ans)
            {
                ans=tmp;ay=i;
            }
        }
        toty=ans;
        LL tot=totx+toty;
        printf("%d %d\n%lld\n",ax,ay,tot*100);
    }
    return 0;
}
