#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
char c[maxn];
int l[30],r[30];
struct P
{
    int x,p;
    bool operator < (const P& b)const
    {
        return x<b.x;
    }
}a[60];
main()
{
    int n,k;scanf("%d%d",&n,&k);
    cin>>c+1;
    for(int i=1;i<=n;i++)
    {
        if(l[c[i]-'A']==0)l[c[i]-'A']=i;
        r[c[i]-'A']=i;
    }
    int s=0;
    for(int i=0;i<26;i++)
    {
        if(l[i])a[++s]=(P){l[i],1};
        if(r[i])a[++s]=(P){r[i],-1};
    }
    int cnt=0,mx=0;
    sort(a+1,a+s+1);
    for(int i=1;i<=s;i++)
    {
        cnt+=a[i].p;
        //printf("%d %d\n",a[i].x,a[i].p);
        mx=max(mx,cnt);
        //printf("%d\n",cnt);
    }
    if(mx>k)puts("YES");
    else puts("NO");
    return 0;
}
