#include<bits/stdc++.h>
using namespace std;
#define ll long long

void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)x=1,y=0;
    else exgcd(b,a%b,y,x),y-=x*(a/b);
}
main()
{

    return 0;
}

