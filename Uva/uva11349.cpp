#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100+5
ll a[maxn][maxn];

main()
{
    int t,cas=0;scanf("%d",&t);
    while(t--)
    {
        char c[2];int n;
        cin>>c[0]>>c[1]>>n;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%lld",&a[i][j]);
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(a[i][j]<0 || a[i][j]!=a[n-1-i][n-1-j]){flag=0;break;}
            if(!flag)break;
        }
        if(flag)printf("Test #%d: Symmetric.\n",++cas);
        else printf("Test #%d: Non-symmetric.\n",++cas);
    }

}
