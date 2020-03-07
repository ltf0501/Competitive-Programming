#include<bits/stdc++.h>
using namespace std;

main()
{
    int a,b,f,k;scanf("%d%d%d%d",&a,&b,&f,&k);
    if(b<f)return 0*puts("-1");
    int now=b-f,ans=0;
    f=a-f;
    while(--k)
    {
        if(now<0)return 0*puts("-1");
        if(2*f>now)now=b,ans++;
        now-=2*f;
        f=a-f;
    }
    if(now<0)return 0*puts("-1");
    if(f>now)now=b,ans++;
    now-=f;
    if(now<0)return 0*puts("-1");
    printf("%d\n",ans);
    return 0;
}
