#include<bits/stdc++.h>
using namespace std;
#define maxn 80
#define SZ(v) ((int)v.size())
const int INF=1e9+7;
int dp[maxn][maxn][maxn][2];
char c[maxn];
vector<int> V,K,a;
int cal(int id,vector<int> vv,int pos)
{
    int cnt=0;
    for(int i=id;i<SZ(vv);i++)if(vv[i]<pos)cnt++;
    return cnt;
}
int cc(int i,int j,int k,int pos){return cal(i,V,pos)+cal(j,K,pos)+cal(k,a,pos);}
void mi(int &a,int b){if(a>b)a=b;}
main()
{
    int n;scanf("%d",&n);
    scanf("%s",c);
    for(int i=0;i<n;i++)
    {
        if(c[i]=='V')V.push_back(i);
        else if(c[i]=='K')K.push_back(i);
        else a.push_back(i);
    }
    for(int i=0;i<=SZ(V);i++)for(int j=0;j<=SZ(K);j++)
        for(int k=0;k<=SZ(a);k++)for(int l=0;l<2;l++)dp[i][j][k][l]=INF;
    dp[0][0][0][0]=0;
    for(int i=0;i<=SZ(V);i++)for(int j=0;j<=SZ(K);j++)
        for(int k=0;k<=SZ(a);k++)for(int l=0;l<2;l++)
        {
            if(i+1<=SZ(V))mi(dp[i+1][j][k][1],dp[i][j][k][l]+cc(i,j,k,V[i]));
            if(j+1<=SZ(K) && l==0)mi(dp[i][j+1][k][0],dp[i][j][k][l]+cc(i,j,k,K[j]));
            if(k+1<=SZ(a))mi(dp[i][j][k+1][0],dp[i][j][k][l]+cc(i,j,k,a[k]));
        }
    printf("%d\n",min(dp[SZ(V)][SZ(K)][SZ(a)][0],dp[SZ(V)][SZ(K)][SZ(a)][1]));
    return 0;
}
