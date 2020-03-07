#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
char p[maxn];
int f[maxn];
main()
{
    int n,cas=0;
    while(~scanf("%d",&n) && n)
    {
        scanf("%s",p);
        f[0]=f[1]=0;
        for(int i=1;i<n;i++)
        {
            int j=f[i];
            while(j && p[i]!=p[j])j=f[j];
            f[i+1]=(p[i]==p[j]) ? j+1 : 0;
        }
        printf("Test case #%d\n",++cas);
        for(int i=2;i<=n;i++)
            if(f[i]>0 && i%(i-f[i])==0)printf("%d %d\n",i,i/(i-f[i]));
        puts("");
    }
    return 0;
}

