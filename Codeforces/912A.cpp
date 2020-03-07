#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ll a,b,x,y,z;cin>>a>>b>>x>>y>>z;
    ll m=0,n=0;
    m=2*x+y,n=3*z+y;
    cout<<max(m-a,0ll)+max(n-b,0ll)<<'\n';
    return 0;
}

