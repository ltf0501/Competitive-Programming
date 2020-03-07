#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int n,k;
int a[maxn];
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int cnt=n;
    int l=n;
    for(int i=n;i>=2;i--)
    {
        while(a[l]==a[i])l--;
        while(l>=1 && a[l]>=a[i]-k)l--,cnt--;
    }
    printf("%d\n",cnt);
    return 0;
}
