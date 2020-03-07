#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
const int INF=1e9+7;
int a[maxn];
char b[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%s",b+1);
    int l=-INF,r=INF;
    for(int i=5;i<=n;i++)
    {
        if(b[i]=='1')
        {
            if(b[i-1]-'0'+b[i-2]-'0'+b[i-3]-'0'+b[i-4]-'0'==0)
            {
                l=max(l,max({a[i],a[i-1],a[i-2],a[i-3],a[i-4]})+1);
            }
        }
        else
        {
            if(b[i-1]-'0'+b[i-2]-'0'+b[i-3]-'0'+b[i-4]-'0'==4)
            {
                r=min(r,min({a[i],a[i-1],a[i-2],a[i-3],a[i-4]})-1);
            }
        }
    }
    if(l==-INF)l=(int)-1e9;
    if(r==INF)r=(int)1e9;
    printf("%d %d\n",l,r);
    return 0;
}
