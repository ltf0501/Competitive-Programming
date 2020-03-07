#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int a[maxn];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    vector<int> ans;
    for(int len=1;len<=n;len++)
    {
        int tmp=a[len]-a[0];
        bool flag=1;
        for(int i=len+1;i<=n;i++)
        {
            if(a[i]-a[i-len]!=tmp){flag=0;break;}
        }
        if(flag)ans.push_back(len);
    }
    printf("%d\n",ans.size());
    for(int s : ans)printf("%d ",s);
    return 0;
}
