#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[2];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(x>0)cnt[0]++;
        else cnt[1]++;
    }
    if(cnt[0]>1 && cnt[1]>1)puts("No");
    else puts("Yes");
    return 0;
}

