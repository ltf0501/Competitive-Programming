#include<bits/stdc++.h>
using namespace std;
#define maxn 2000100
char c[maxn],t[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<maxn;i++)c[i]=' ';
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%s %d",t,&k);
        int len=strlen(t);
        for(int j=1;j<=k;j++)
        {
            int x;scanf("%d",&x);
            mx=max(mx,x+len);
            for(int l=x;l<x+len;l++)c[l]=t[l-x];
        }
    }
    for(int i=1;i<mx;i++)
        printf("%c",c[i]==' ' ? 'a' : c[i]);
    return 0;
}
