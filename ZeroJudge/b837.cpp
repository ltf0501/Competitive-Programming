#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[35];
void build()
{
    f[0]=0,f[1]=1,f[2]=1;
    for(int i=3;i<=35;i++)f[i]=f[i-1]+f[i-2];
}

main()
{
    int t;scanf("%d",&t);
    build();
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        int cnt=0;
        int k=0;
        while(f[k]<a)k++;
        if(f[k]>b)
        {
            printf("0\n");
        }
        else
        {
            while(f[k]<=b)
            {
                printf("%d\n",f[k]);
                k++,cnt++;
            }
            printf("%d\n",cnt);
        }
        if(t)printf("------\n");
    }
    return 0;
}
