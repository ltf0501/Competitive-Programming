#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
char c[maxn];
main()
{
    scanf("%s",c);
    int n=strlen(c);
    char cur='a';
    for(int i=0;i<n;i++)
    {
        if(c[i]<=cur)c[i]=cur,cur++;
        if(cur>'z')break;
    }
    //printf("%c\n",cur);
    if('z'<cur)printf("%s",c);
    else puts("-1");
    return 0;
}
