#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+5
char a[maxn],b[maxn];
int c[maxn],d[maxn];
main()
{
    int n;scanf("%d",&n);
    scanf("%s %s",a,b);
    for(int i=0;i<n;i++)c[a[i]-'0']++,d[b[i]-'0']++;
    int ans=0,t=0;
    for(int i=9;i>=0;i--)
        t+=c[i]-d[i],ans=max(ans,t);
    printf("%d\n",ans);
    ans=t=0;
    for(int i=9;i>=0;i--)
    {
        if(t>c[i])t-=c[i],ans+=c[i];
        else ans+=t,t=0;
        t+=d[i];
        //printf("%d\n",t);
    }
    printf("%d\n",ans);
    return 0;
}
