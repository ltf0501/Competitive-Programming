#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int row[maxn],col[maxn],p[maxn];
int r_sum[maxn],c_sum[maxn];
main()
{
    int r,c;scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)
    {
        int pre=0;
        for(int j=1;j<=c;j++)
        {
            int x;scanf("%d",&x);
            row[i]+=(pre&x);
            col[j]+=(p[j]&x);
            pre=x;
            p[j]=x;
        }
    }
    puts("");
    for(int i=1;i<=r;i++)printf("%d ",row[i]);puts("");
    for(int i=1;i<=c;i++)printf("%d ",col[i]);puts("");
    puts("");
    for(int i=1;i<=r;i++)r_sum[i]=r_sum[i-1]+row[i];
    for(int i=1;i<=c;i++)c_sum[i]=c_sum[i-1]+col[i];
    int q;scanf("%d",&q);
    while(q--)
    {
        int r1,c1,r2,c2;scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        printf("%d\n",r_sum[r2]-r_sum[r1-1]+c_sum[c2]-c_sum[c1-1]);
    }
    return 0;
}
