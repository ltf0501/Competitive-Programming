#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn],n;
int num[maxn],ans[maxn];
vector<int> pos[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        x=n-x;
        num[x]++;
        pos[x].push_back(i);
    }
    for(int i=1;i<=n;i++)
        if(num[i]%i!=0)return 0*puts("Impossible");
    int cur=0;
    puts("Possible");
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<num[i]/i;j++)
        {
            cur++;
            for(int k=0;k<i;k++)ans[pos[i][j*i+k]]=cur;
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}
