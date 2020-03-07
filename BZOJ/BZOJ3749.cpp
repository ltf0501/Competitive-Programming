#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int pos[maxn][5];
int a[maxn],ans[maxn];
int n;
bool check(int k)
{
    memset(pos,0,sizeof(pos));
    pos[1][k]=1;
    for(int i=2;i<=n;i++)
    {
        if(pos[i-1][1] && a[i-1]<=2*a[i])pos[i][1]=1;
        if(pos[i-1][1] && a[i-1]<=a[i])pos[i][3]=1;
        if(pos[i-1][2] && 2*a[i-1]>=a[i])pos[i][2]=2;
        if(pos[i-1][2] && a[i-1]>=a[i])pos[i][4]=2;
        if(pos[i-1][3] && a[i-1]>=a[i])pos[i][2]=3;
        if(pos[i-1][3] && a[i-1]>=2*a[i])pos[i][4]=3;
        if(pos[i-1][4] && a[i-1]<=a[i])pos[i][1]=4;
        if(pos[i-1][4] && 2*a[i-1]<=a[i])pos[i][3]=4;
    }
    return pos[n][k];
}
void print(int k)
{
    for(int i=n;i>=1;i--)
    {
        if(k==1)ans[i-1]=(i-1)%(n-1)+1;
        else if(k==2)ans[i]=(i-1)%(n-1)+1;
        else if(k==3)ans[i-1]=ans[i]=(i-1)%(n-1)+1;
        k=pos[i][k];
    }
    for(int i=1;i<n;i++)printf("%d%c",ans[i],i==n?'\n':' ');
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[++n]=a[1];
    for(int i=1;i<=4;i++)
    {
        if(check(i))
        {
            print(i);
            return 0;
        }
    }
    puts("NIE");
    return 0;
}
