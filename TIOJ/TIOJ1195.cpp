#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        char c[10];
        int ans=0;
        while(n--)
        {
            scanf("%s",c);
            if(c[2]==c[3] && c[4]==c[5] && c[3]!=c[4])ans+=1500;
            else if(c[2]==c[3] && c[2]==c[4] && c[2]==c[5])ans+=2000;
            else ans+=1000;
        }
        printf("%d\n",ans);
    }
    return 0;
}
