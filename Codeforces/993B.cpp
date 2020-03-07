#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
pii a[15],b[15];
bool ok[11];
int check(int a,int b,int c,int d)
{
    if(a==c && b==d)return -1;
    if(a==c)return a;
    if(a==d)return a;
    if(b==c)return b;
    if(b==d)return b;
    return -1;
}
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S);
        if(a[i].F>=a[i].S)swap(a[i].F,a[i].S);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&b[i].F,&b[i].S);
        if(b[i].F>=b[i].S)swap(b[i].F,b[i].S);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int s=check(a[i].F,a[i].S,b[j].F,b[j].S);
            if(s!=-1)ok[s]=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=9;i++)if(ok[i])cnt++;
    assert(cnt);
    if(cnt==1)
    {
        for(int i=1;i<=9;i++)
            if(ok[i])return 0*printf("%d\n",i);
    }
    for(int i=1;i<=n;i++)
    {
        int umr=-1;
        for(int j=1;j<=m;j++)
        {
            int s=check(a[i].F,a[i].S,b[j].F,b[j].S);

            if(umr==-1)umr=s;
            if(s!=-1 && umr!=s)umr=-2;
            //printf("%d %d\n",umr,s);
        }
        if(umr==-2)return 0*puts("-1");
    }
    for(int i=1;i<=m;i++)
    {
        int umr=-1;
        for(int j=1;j<=n;j++)
        {
            int s=check(b[i].F,b[i].S,a[j].F,a[j].S);
            //printf("%d %d\n",umr,s);
            if(umr==-1)umr=s;
            if(s!=-1 && umr!=s)umr=-2;
        }
        if(umr==-2)return 0*puts("-1");
    }
    puts("0");
    return 0;
}
