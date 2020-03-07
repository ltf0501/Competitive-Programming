#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int a[maxn],b[maxn];
ll s[maxn],t[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=a[i]+s[i-1];
    for(int i=1;i<=m;i++)scanf("%d",&b[i]),t[i]=b[i]+t[i-1];
    int ans=0,prea=0,curb=0,preb=0;
    for(int i=1;i<=n;i++)
    {
        while(curb<=m && t[curb]-t[preb]<s[i]-s[prea])curb++;
        //printf("%d %d %d %d\n",i,prea,curb,preb);
        if(t[curb]-t[preb]==s[i]-s[prea])
        {
            ans++;preb=curb;prea=i;
            continue;
        }
    }
    printf("%d\n",ans);
    return 0;
}

