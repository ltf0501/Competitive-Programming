#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cnt[10];
void check(ll &a,int n)
{
    while(a%n==0)
        cnt[n]++,a/=n;
}
main()
{
    ll a;
    scanf("%lld",&a);
    if(a==1){puts("1");return 0;}
    check(a,9),check(a,3);
    check(a,8),check(a,2);
    check(a,5),check(a,7);
    if(a!=1){puts("-1");return 0;}
    if(cnt[3]==1 && cnt[2]!=0)
        cnt[2]--,cnt[3]--,cnt[6]++;
    else if(cnt[2]==2 && cnt[3]==0)
        cnt[2]-=2,cnt[4]++;
    for(int i=2;i<=9;i++)
        for(int j=1;j<=cnt[i];j++)printf("%d",i);
    puts("");
    return 0;
}
