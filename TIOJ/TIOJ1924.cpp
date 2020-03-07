#include<bits/stdc++.h>
using namespace std;
#define maxn 2000010
char c[maxn],s[maxn];
int pre[3][maxn],cut[maxn];
int n,ans;
map<char,int> mp;
void solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)pre[j][i]=pre[j][i-1];
        pre[mp[c[i]]][i]++;
        cut[i]=cut[i-1];
        if(pre[0][i]>pre[0][cut[i]]+(pre[1][i]-pre[1][cut[i]]))cut[i]=i;
    }
    for(int i=0;i<=n;i++)
    {
        ans=max(ans,pre[0][cut[i]]+(pre[1][i]-pre[1][cut[i]])+(pre[2][n]-pre[2][i]));
    }
}
int ss[3];
main()
{
    scanf("%d",&n);
    scanf("%s",c+1);
    for(int i=0;i<3;i++)ss[i]=i;
    do
    {
        mp['P']=ss[0],mp['E']=ss[1],mp['C']=ss[2];
        //printf("%d %d %d\n",mp['P'],mp['E'],mp['C']);
        solve();
    }while(next_permutation(ss,ss+3));
    printf("%d\n",ans);
    return 0;
}
