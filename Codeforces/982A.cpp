#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int n;
char c[maxn];
main()
{
    scanf("%d",&n);
    scanf("%s",c+1);
    c[0]='0',c[n+1]='0';
    if(n==1)
    {
        if(c[1]=='0')return 0*puts("No");
        return 0*puts("Yes");
    }
    for(int i=1;i<n;i++)
    {
        if(c[i]=='1' && c[i+1]=='1')return 0*puts("No");
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i-1]=='0' && c[i]=='0' && c[i+1]=='0')return 0*puts("No");
    }
    puts("Yes");
    return 0;
}

