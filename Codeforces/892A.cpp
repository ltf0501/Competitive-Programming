#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int a,b[maxn];
int n;
main()
{
    scanf("%d",&n);
    ll k=0;
    for(int i=1;i<=n;i++)scanf("%d",&a),k+=a;
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    sort(b+1,b+n+1);
    ll t=b[n-1]+b[n];
    puts(t>=k ? "YES" : "NO");
    return 0;
}

