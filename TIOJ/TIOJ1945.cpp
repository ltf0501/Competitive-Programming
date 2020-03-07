#include<cstdio>
#include<algorithm>
#include<cstring>
#include "lib1945.h"
using namespace std;
#define maxn 131072+10
int b[maxn];
int sum[maxn];
main()
{
    Init();
    for(int i=0;i<(1<<17);i++)
    {
        int a[1];
        a[0]=i;
        b[i]=Query(1,a);
        if(!i)sum[i]=b[i];
        else sum[i]=sum[i-1]+b[i];
    }
    int l=0,r=(1<<17)-1;
    while(r>l)
    {
        int m=l+(r-l)/2;
        int a[maxn];
        for(int i=0;i<=m-l;i++)a[i]=l+i;
        if(Query(m-l+1,a)==(sum[m]-sum[l-1])%2)
        {
            l=m+1;continue;
        }
        else{r=m;continue;}
    }
    int a[1];
    a[0]=l;
    int p=Query(1,a);
    int q=Query(1,a);
    if(p==q)b[l]=p;
    for(int i=0;i<(1<<17);i++)printf("%d ",b[i]);
    puts("");
    return 0;
}
