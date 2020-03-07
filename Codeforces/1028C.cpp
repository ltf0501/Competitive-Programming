#include<bits/stdc++.h>
using namespace std;
#define maxn 150010
const int INF=1e9+7;
int a[4][maxn];//L D R U
int pre[4][maxn],suf[4][maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=0;j<4;j++)scanf("%d",&a[j][i]);
    pre[0][0]=pre[1][0]=suf[0][n+1]=suf[1][n+1]=-INF;
    pre[2][0]=pre[3][0]=suf[2][n+1]=suf[3][n+1]=INF;
    for(int i=1;i<=n;i++)
    {
        pre[0][i]=max(pre[0][i-1],a[0][i]);
        pre[1][i]=max(pre[1][i-1],a[1][i]);
        pre[2][i]=min(pre[2][i-1],a[2][i]);
        pre[3][i]=min(pre[3][i-1],a[3][i]);
    }
    for(int i=n;i>=1;i--)
    {
        suf[0][i]=max(suf[0][i+1],a[0][i]);
        suf[1][i]=max(suf[1][i+1],a[1][i]);
        suf[2][i]=min(suf[2][i+1],a[2][i]);
        suf[3][i]=min(suf[3][i+1],a[3][i]);
    }
    for(int i=1;i<=n;i++)
    {
        int L=max(pre[0][i-1],suf[0][i+1]);
        int D=max(pre[1][i-1],suf[1][i+1]);
        int R=min(pre[2][i-1],suf[2][i+1]);
        int U=min(pre[3][i-1],suf[3][i+1]);
        if(L<=R && D<=U)return 0*printf("%d %d\n",L,D);
    }
    return 0;
}
