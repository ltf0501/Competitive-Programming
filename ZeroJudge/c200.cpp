#include<bits/stdc++.h>
using namespace std;
char c[105];
int d[105];
void init()
{
    d[0]=1;
    for(int i=1;i<=100;i++)d[i]=(d[i-1]*36)%1688;
}
main()
{
    int t;scanf("%d",&t);
    init();
    while(t--)
    {
        scanf("%s",c);
        int len=strlen(c);
        int ans=0;
        for(int i=0;i<len;i++)
        {
            if('0'<=c[i] && c[i]<='9')ans=(ans+(c[i]-'0')*d[len-1-i])%1688;
            else ans=(ans+(c[i]-'A'+10)*d[len-1-i])%1688;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
