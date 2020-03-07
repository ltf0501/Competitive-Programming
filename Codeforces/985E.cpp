#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
int n,k,d;
int a[maxn];
bool ok[maxn];
main()
{
    scanf("%d%d%d",&n,&k,&d);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int cnt=1;
    ok[0]=1;
    int l=0,r=0;
    for(int i=k;i<=n;i++)
    {
        while(l<=r && a[i]-a[l+1]>d)
            cnt-=ok[l],l++;
        if(cnt)ok[i]=1;
        r++;
        cnt+=ok[r];
    }
    puts(ok[n] ? "YES" : "NO");
    return 0;
}
