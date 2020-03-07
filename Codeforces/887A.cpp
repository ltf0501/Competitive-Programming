#include<bits/stdc++.h>
using namespace std;
char c[105];
main()
{
    scanf("%s",c+1);
    int n=strlen(c+1);
    int k=-1;
    int cnt=0;
    for(int i=n;;i--)
    {
        if(c[i]=='0')cnt++;
        if(cnt==6){k=i;break;}
    }
    if(cnt<6)return 0*puts("no");
    for(int i=1;i<k;i++)
        if(c[i]=='1')return 0*puts("yes");
    puts("no");
    return 0;
}

