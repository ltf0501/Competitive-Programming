#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

main()
{
    int s[4],a[10],b[10];
    while(scanf("%d%d%d%d",&s[0],&s[1],&s[2],&s[3])==4)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<=3;i++)a[s[i]]++;
        int n;
        scanf("%d",&n);
        while(n--)
        {
            int t[4];
            memset(b,0,sizeof(b));
            scanf("%d%d%d%d",&t[0],&t[1],&t[2],&t[3]);
            for(int i=0;i<=3;i++)b[t[i]]++;
            int A=0,C=0;
            for(int i=0;i<=3;i++)
            {
                if(s[i]==t[i])A++;
            }
            /*
            for(int i=0;i<=9;i++)printf("%d ",a[i]);
            puts("");
            for(int i=0;i<=9;i++)printf("%d ",b[i]);
            puts("");
            */
            for(int i=0;i<=9;i++)C+=min(a[i],b[i]);
            int B=C-A;
            printf("%dA%dB\n",A,B);
        }
    }
    return 0;
}
