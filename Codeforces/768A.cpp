#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+5
int a[maxn];
main()
{
    int n;scanf("%d",&n);
    int m,k;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int mi=a[1],mx=a[n];
    int ans=n,idx=1;
    if(mi==mx){puts("0");return 0;}
    while(mi==a[idx])ans--,idx++;
    idx=n;
    while(mx==a[idx])ans--,idx--;
    printf("%d\n",ans);
    return 0;
}

