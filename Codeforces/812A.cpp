#include<bits/stdc++.h>
using namespace std;
int l[4],s[4],r[4],p[4];
main()
{
    for(int i=0;i<=3;i++)scanf("%d%d%d%d",&l[i],&s[i],&r[i],&p[i]);
    bool flag=0;
    for(int i=0;i<=3;i++)
    {
        if(p[i] && (l[i] || s[i] || r[i] || l[(i+1)%4] || s[(i+2)%4] || r[(i+3)%4])){flag=1;break;}
    }
    if(flag)puts("YES");
    else puts("NO");
    return 0;
}

