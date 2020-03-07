#include<bits/stdc++.h>
using namespace std;
#define maxn 10000+5
int a[maxn],l[maxn],r[maxn],num[maxn];
bool vis[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        scanf("%d",&a[i]);
        if(!l[a[i]])l[a[i]]=i;
        else r[a[i]]=i;
    }
    int coda=2;
    for(int i=1;i<=2*n;i++)
    {
        if(l[a[i]]==i)coda--;
        num[i]=coda;
        if(r[a[i]]==i)coda++;
    }
    int ans=n;
    for(int i=1;i<=2*n;i++)while(num[i]<0)
    {
        int mx=0,id;
        for(int j=1;j<=i;j++)if(!vis[a[j]] && j==l[a[j]] && r[a[j]]>mx)
            mx=r[id=a[j]];
        vis[id]=1;
        for(int j=l[id];j<=r[id];j++)num[j]++;
        ans--;
    }
    printf("%d\n",ans);
    return 0;
}
