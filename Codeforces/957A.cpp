#include<bits/stdc++.h>
using namespace std;
char c[105];
int n;
main()
{
    scanf("%d",&n);
    scanf("%s",c+1);
    for(int i=1;i<n;i++)if(c[i]==c[i+1] && c[i]!='?')return 0*puts("No");
    bool flag=0;
    for(int i=1;i<=n;i++)if(c[i]=='?')
    {
        if((i==1 || i==n)){flag=1;break;}
        else if(c[i-1]==c[i+1] || c[i-1]=='?' || c[i+1]=='?'){flag=1;break;}
    }
    if(flag)puts("Yes");
    else puts("No");
    return 0;
}

