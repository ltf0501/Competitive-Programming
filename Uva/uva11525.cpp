
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 50000+5
#define low(x) x&-x
int c[maxn];
int n;
int sum(int x)
{
    int res=0;
    while(x>=1)
    {
        res+=c[x];
        x-=low(x);
    }
    return res;
}
void add(int x,int d)
{
    while(x<=n)
    {
        c[x]+=d;
        x+=low(x);
    }
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)add(i,1);

        for(int i=1;i<=n;i++)
        {
            int v;scanf("%d",&v);v++;
            int l=1,r=n;
            while(r>l)
            {
                int m=l+(r-l)/2;
                if(sum(m)>=v)r=m;
                else l=m+1;
            }
            printf("%d%c",l,i==n ? '\n' : ' ');
            add(l,-1);
        }
    }
    return 0;
}

