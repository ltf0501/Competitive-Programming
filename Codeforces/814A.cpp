#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],h[105];
bool cmp(int x,int y){return x>y;}
main()
{
    int n,k;scanf("%d%d",&n,&k);
    int now=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(!a[i])h[++now]=i;
    }
    for(int i=1;i<=k;i++)scanf("%d",&b[i]);
    sort(b+1,b+k+1,cmp);
    for(int i=1;i<=k;i++)a[h[i]]=b[i];
    bool flag=0;
    for(int i=1;i<n;i++)
        if(a[i+1]<a[i]){flag=1;break;}
    if(flag)puts("Yes");
    else puts("No");
    return 0;
}

