#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int a[maxn];
int n;
char c[maxn];
int l[maxn],r[maxn];
bool vis[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%s",c+1);
    c[0]='0';
    c[n]='0';
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i]=='1' && c[i-1]=='0')l[++cur]=i;
        if(c[i]=='0' && c[i-1]=='1')r[cur]= i;
    }
    //printf("%d\n",cur);
    //for(int i=1;i<=cur;i++)printf("%d %d\n",l[i],r[i]);
    for(int i=1;i<=cur;i++)
    {
        for(int j=l[i];j<=r[i];j++)vis[a[j]]=1;
        for(int j=l[i];j<=r[i];j++)if(!vis[j])return 0*puts("NO");
        for(int j=l[i];j<=r[i];j++)vis[a[j]]=0;
    }
    l[cur+1]=n+1;
    for(int i=1;i<=cur+1;i++)
    {
        for(int j=r[i-1]+1;j<l[i];j++)if(a[j]!=j)return 0*puts("NO");
    }
    puts("YES");
    return 0;
}

