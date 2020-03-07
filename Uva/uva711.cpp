#include<cstdio>
#include<cstring>
using namespace std;
int num[7],tot,ok[121000];
void pack(int cost)
{
    for(int i=tot;i>=cost;i--)ok[i]|=ok[i-cost];
}
main()
{
    int a,b,cas=0;
    while(++cas)
    {
        tot=0;
        for(int i=1;i<=6;i++){scanf("%d",&num[i]);tot+=num[i]*i;}
        if(!tot)break;
        printf("Collection #%d:\n",cas);
        if(tot&1){printf("Can't be divided.\n\n");continue;}

        memset(ok,0,sizeof(ok));
        ok[0]=1;
        for(int i=1;i<=6;i++)
        {
            a=1;b=num[i];
            while(a<num[i])
            {
                pack(a*i);
                b-=a;
                a*=2;
            }
            if(b>0)pack(b*i);
        }
        if(ok[tot/2])printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}
