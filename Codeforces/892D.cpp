#include<bits/stdc++.h>
using namespace std;
int a[25];
int b[25],r[25];
int num[25];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)r[i]=lower_bound(b+1,b+n+1,a[i])-b;
    for(int i=1;i<=n;i++)num[r[i]]=i;
    int tmp=a[num[n]];
    for(int i=n;i>1;i--)a[num[i]]=a[num[i-1]];
    a[num[1]]=tmp;
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}

