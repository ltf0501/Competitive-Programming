#include<bits/stdc++.h>
using namespace std;
#define maxn 50050
int n,k;
int a[maxn];
bool check(int s)
{
    int cnt=0;
    int l=1,r=1;
    while(r<=n)
    {
        if(a[r]-a[l]<=s)
        {
            r++;
            if(r>n){cnt++;break;}
        }
        else l=r,cnt++;
    }
    return cnt<=k;
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=(int)1e9;
    while(r-l>=1)
    {
        int m=(l+r)>>1;
        if(check(m))r=m;
        else l=m+1;
    }
    printf("%d\n",l);
    return 0;
}
