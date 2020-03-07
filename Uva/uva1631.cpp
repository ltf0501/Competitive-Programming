#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 1005
char sa[MAXN],sb[MAXN];
int a[MAXN],b[MAXN];
int d[MAXN][10][10];
int n;
int up(int x,int y)
{
    if(x<=y)return y-x;
    return 10+y-x;
}
int down(int x,int y)
{
    if(x>=y)return x-y;
    return 10+x-y;
}
main()
{
    while(scanf("%s%s",sa,sb)!=EOF)
    {
        n=strlen(sa);
        for(int i=0;i<n;i++)
        {
            a[i]=sa[i]-'0';
            b[i]=sb[i]-'0';
        }
        a[n]=a[n+1]=b[n]=b[n+1]=0;
        memset(d,-1,sizeof(d));
    }
    return 0;
}

