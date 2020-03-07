#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,a[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int cur=0,cnt=0;
    for(int i=1;i<=n;i++)
        if(cur<=a[i])cnt++,cur+=a[i];
    printf("%d\n",cnt);
    return 0;
}
