#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int l[maxn],r[maxn];
int n,k;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
    scanf("%d",&k);
    int cnt=0;
    for(int i=n;i>=1;i--)
    {
        cnt++;
        if(k>=l[i])break;
    }
    printf("%d\n",cnt);
    return 0;
}

