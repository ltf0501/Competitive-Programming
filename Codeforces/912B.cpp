#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ll n,k;cin>>n>>k;
    int cnt;
    for(int i=0;;i++)if(1ll<<i>n){cnt=i;break;}
    if(k>=2)
    {
        cout<<(1ll<<cnt)-1<<'\n';
    }
    else cout<<n<<'\n';
    ///cout<<cnt;
    return 0;
}
