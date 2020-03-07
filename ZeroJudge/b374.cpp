#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 30000+5
int c[maxn];
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            c[x]++;
        }
        int Max=0;
        for(int i=1;i<=maxn;i++)Max=max(Max,c[i]);
        for(int i=1;i<=maxn;i++)
            if(c[i]==Max)printf("%d %d\n",i,Max);
    }
    return 0;
}
