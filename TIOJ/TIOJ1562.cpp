#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 105
int p,t;
int cost[maxn];
bool test(int n)
{
    int tp=0,r[maxn];
    for(int i=0;i<p;i++)r[i]=cost[p-i-1];
    int k=0;
    for(int i=0;i<p && k<=t;i++)
    {
        tp+=r[i];
        if(tp>n)tp=0,k++,i--;
    }
    k++;
    return k<=t;
}
main()
{
    while(~scanf("%d%d",&p,&t))
    {
        int r=0,l=999999;
        for(int i=0;i<p;i++)scanf("%d",&cost[i]),r+=cost[i],l=min(l,cost[i]);
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(test(m))r=m;
            else l=m+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
