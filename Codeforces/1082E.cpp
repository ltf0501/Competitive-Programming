#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
int pre[maxn],suf[maxn];
int a[maxn],num[maxn],le[maxn];
int n,c;

main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(a[i]==c);
    for(int i=n;i>=1;i--)suf[i]=suf[i+1]+(a[i]==c);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        num[i]=pre[i-1]+1;
        int l=le[a[i]];
        if(l)num[i]=max(num[i],num[l]+1);
        le[a[i]]=i;
    }
    for(int i=1;i<=n;i++)ans=max(ans,num[i]+suf[i+1]);
    printf("%d\n",ans);
    return 0;
}
