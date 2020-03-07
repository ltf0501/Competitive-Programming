#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
unsigned long long F[100];
int n,k;
void backs(int n,int k)
{
    if(n==1)puts("0");
    else if(n==2)puts("1");
    else
    {
        if(k>F[n-2])backs(n-1,k-F[n-2]);
        else backs(n-2,k);
    }
}
main()
{
    F[1]=F[2]=1;
    for(int i=3;i<100;i++)F[i]=F[i-1]+F[i-2];
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        int c;
        for(int i=1;i<100;i++)if(k<=F[i]){c=i;break;}
        if(c>n){puts("-1");continue;}
        backs(n,k);
    }
    return 0;
}
