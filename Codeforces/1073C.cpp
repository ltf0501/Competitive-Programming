#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
char c[maxn];
int n;
int x,y;
int pos[2][maxn];
bool query(int m)
{
    for(int i=1;i+m-1<=n;i++)
    {
        int tx=pos[0][i+m-1]-pos[0][i-1];
        int ty=pos[1][i+m-1]-pos[1][i-1];
        tx=pos[0][n]-tx;
        ty=pos[1][n]-ty;
        if(abs(tx-x)+abs(ty-y)<=m)return 1;
    }
    return 0;
}
main()
{
    scanf("%d",&n);
    scanf("%s",c+1);
    scanf("%d%d",&x,&y);
    for(int i=1;i<=n;i++)
    {
        pos[0][i]=pos[0][i-1];
        pos[1][i]=pos[1][i-1];
        if(c[i]=='R')pos[0][i]++;
        if(c[i]=='L')pos[0][i]--;
        if(c[i]=='U')pos[1][i]++;
        if(c[i]=='D')pos[1][i]--;
    }
    if(abs(x)+abs(y)>n || (x+y+n)%2!=0)return 0*puts("-1");
    if(pos[0][n]==x && pos[1][n]==y)return 0*puts("0");
    int now=0;
    for(int i=17;i>=0;i--)if(now+(1<<i)<=n)
    {
        now+=(1<<i);
        if(query(now))now-=(1<<i);
    }
    now++;
    printf("%d\n",now);
    return 0;
}
