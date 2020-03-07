#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

main()
{
    int k;scanf("%d",&k);
    int a,b,ans=0,sum=0;
    while(k--)
    {
        scanf("%d%d",&a,&b);
        if(b==1)
        {
            sum++;
            ans=max(ans,sum);
        }
        else
        {
            sum--;
            ans=max(ans,sum);
        }
    }
    printf("%d\n",ans);
    return 0;
}
