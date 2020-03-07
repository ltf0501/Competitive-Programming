#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
vector<int> a[maxn],b[maxn];
int n,m;
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        int x;scanf("%d",&x);
        a[i+j].push_back(x);
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        int x;scanf("%d",&x);
        b[i+j].push_back(x);
    }
    for(int sum=0;sum<n+m-1;sum++)
    {
        sort(a[sum].begin(),a[sum].end());sort(b[sum].begin(),b[sum].end());
        if(a[sum]!=b[sum])return 0*puts("NO");
    }
    puts("YES");
    return 0;
}
