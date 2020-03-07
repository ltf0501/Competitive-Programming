#include<bits/stdc++.h>
using namespace std;
int cnt[105];

main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        cnt[x]++;
    }
    for(int i=1;i<=100;i++)
        for(int j=0;j<cnt[i];j++)printf("%d ",i);puts("");
    return 0;
}
