#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int num[40];

main()
{
    int t,n,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        if(n==0){puts("-1");continue;}
        if(n==1){puts("1");continue;}
        cnt=0;


        for(int i=9;i>1;i--)
        {
            while(n%i==0)
            {
                num[cnt++]=i;
                n/=i;
            }
            if(n==1)break;
        }
        sort(num,num+cnt);
        if(n!=1)puts("-1");
        else
        {
            for(int i=0;i<cnt;i++)printf("%d", num[i]);
            puts("");
        }
    }
    return 0;
}
