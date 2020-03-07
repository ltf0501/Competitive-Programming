#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,ans=0;scanf("%d",&n);
    char c[15];
    while(n--)
    {
        scanf("%s",c);
        if(c[0]=='T')ans+=4;
        else if(c[0]=='C')ans+=6;
        else if(c[0]=='O')ans+=8;
        else if(c[0]=='I')ans+=20;
        else if(c[0]='D')ans+=12;
        //printf("%d\n",ans);
    }
    printf("%d\n",ans);
    return 0;
}
