#include<cstdio>
#include<algorithm>
using namespace std;
int f[13];
bool vis[13];
char ans[13];
int n,m;
void init()
{
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=12;i++)f[i]=f[i-1]*i;
}
char al(int x)
{
    int cnt=0;
    int i=0;
    for(i=0;i<n;i++)
    {
        if(vis[i]&&cnt==x)break;
        if(vis[i])cnt++;
    }
    vis[i]=0;
    return i+'A';
}
int main()
{
    init();
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        m--;
        m%=f[n];
        for(int i=0;i<15;i++)vis[i]=1;
        for(int i=0;i<n;i++)
        {
            int mm=m/f[n-1-i];
            m%=f[n-1-i];
            ans[i]=al(mm);
        }
        ans[n]='\0';
        for(int i=0;i<n-1;i++)printf("%c ",ans[i]);
        printf("%c\n",ans[n-1]);
    }
}
