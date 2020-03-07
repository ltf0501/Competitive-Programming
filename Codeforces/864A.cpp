#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[105];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        cnt[x]++;
    }
    int mm=0,c[5]={0};
    for(int i=1;i<=100;i++)if(cnt[i])
    {
        c[++mm]=i;
        if(mm>=3){puts("NO");return 0;}
    }
    puts(cnt[c[1]]==cnt[c[2]] ? "YES" : "NO");
    if(cnt[c[1]]==cnt[c[2]])printf("%d %d\n",c[1],c[2]);
    return 0;
}

