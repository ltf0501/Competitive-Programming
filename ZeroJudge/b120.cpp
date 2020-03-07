#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000006
#define UP 200000
int dp[2][N];  // dp[0][] for h & dp[1][] for f
int used[2][N];// used[0][] for h & used[1][] for f
int g(int z){return z<=2?(z*z)-1:2;}
int h(int y)
{
    if(used[0][y+UP])return dp[0][y+UP];
    used[0][y+UP]=1;
    if(y<2)return dp[0][y+UP]=-1;
    else return dp[0][y+UP]=2+h(y-1)-h(y-2);
}
int f(int x)
{
    if(used[1][x+UP])return dp[1][x+UP];
    used[1][x+UP]=0;
    if(x>h(x))return dp[1][x+UP]=f(x-1)-h(x);
    else if(x<h(x))return dp[1][x+UP]=f(g(x))-g(x);
    else return dp[1][x+UP]=1;
}
int main ()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",f(n));
    }

    return 0;
}
