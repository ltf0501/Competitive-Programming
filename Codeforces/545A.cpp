#include<bits/stdc++.h>
using namespace std;
int a[101][101],n;
vector<int> v;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        bool flag=1;
        for(int j=1;j<=n;j++)if(a[i][j]==1 || a[i][j]==3){flag=0;break;}
        if(flag)cnt++,v.push_back(i);
    }
    printf("%d\n",cnt);
    for(int s : v)printf("%d ",s);
    return 0;
}

