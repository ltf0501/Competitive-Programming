#include<bits/stdc++.h>
using namespace std;
int n;
main()
{
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<n;i++)if(n%i==0)ans++;
    printf("%d\n",ans);
    return 0;
}

