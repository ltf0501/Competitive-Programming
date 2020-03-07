#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
char c[maxn];
struct P
{
    char c;
    int k;
}a[maxn];
main()
{
    int n;scanf("%d",&n);
    scanf("%s",c);
    int cnt=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(c[i]=='A' || c[i]=='B' || c[i]=='C')
        {
            a[++cnt]=(P){c[i],i};
            if(c[i]=='C')ans++;
        }
    }
    a[0]=(P){'C',-1};
    a[++cnt]=(P){'C',n};
    for(int i=0;i<cnt;i++)
    {
        if(a[i].c=='C' || a[i+1].c=='C')continue;
        if((a[i].c-'A')+(a[i+1].c-'A')!=1)
        {
            if((a[i+1].k-a[i].k)%2!=0 && a[i+1].k-a[i].k>=3)ans++;
        }
        else
        {
            if((a[i+1].k-a[i].k)%2==0)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

