#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
char s[2][maxn];
main()
{
    scanf("%s%s",s[0]+1,s[1]+1);
    int cnt=0,n=strlen(s[0]+1);
    for(int i=1;i<=n;i++)if(s[0][i]!=s[1][i])cnt++;
    if(cnt&1)return 0*puts("impossible");
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        if(s[0][i]==s[1][i])putchar(s[0][i]);
        else
        {
            if(cur<cnt/2)putchar(s[0][i]);
            else putchar(s[1][i]);
            cur++;
        }
    }
    return 0;
}
