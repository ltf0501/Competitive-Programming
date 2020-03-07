#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[14],b[14];
main()
{
    for(int i=0;i<14;i++)scanf("%d",&a[i]);
    ll ans=0;
    for(int i=0;i<14;i++)
    {
        for(int j=0;j<14;j++)b[j]=a[(j+i)%14];
        int k=b[13]%14,t=b[13]/14;
        b[13]=0;
        for(int j=0;j<14;j++)b[j]+=t;
        for(int j=0;j<k;j++)b[j]++;
        ll tmp=0;
        for(int j=0;j<14;j++)
            if(b[j]%2==0)tmp+=b[j];
        ans=max(ans,tmp);
    }
    printf("%lld\n",ans);
    return 0;
}
