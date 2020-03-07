#include<bits/stdc++.h>
using namespace std;
int a[105];
int n;
main()
{
    scanf("%d",&n);
    int m=n/2;
    for(int i=1;i<=m;i++)scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    int ans1=0,ans2=0;
    for(int i=1;i<=m;i++)ans1+=abs(a[i]-(2*i-1));
    for(int i=1;i<=m;i++)ans2+=abs(a[i]-2*i);
    printf("%d\n",min(ans1,ans2));
    return 0;
}
