#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
bool check[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(x!=i)check[i]=1;
    }
    int cnt=0;
    for(int i=1;i<n;i++)
        if(!check[i])cnt++,check[i]=1,check[i+1]=1;
    if(!check[n])cnt++;
    printf("%d\n",cnt);
    return 0;
}
