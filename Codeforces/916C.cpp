#include<bits/stdc++.h>
using namespace std;
const int k=100069;
main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d %d\n",k,k);
    for(int i=1;i<n-1;i++)printf("%d %d %d\n",i,i+1,1);
    printf("%d %d %d\n",n-1,n,k-n+2);
    m-=(n-1);
    if(!m)return 0;
    for(int i=1;i<=n-2;i++)for(int j=i+2;j<=n;j++)
    {
        printf("%d %d %d\n",i,j,1000000000);
        if(!(--m))return 0;
    }
    return 0;
}
