#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
char c[maxn];
int n,k;
bool vis[maxn];
main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",c);
    k>>=1;
    int umr=k;
    for(int i=0;i<n,umr;i++)
        if(c[i]=='(')umr--,vis[i]=1;
    umr=k;
    for(int i=n-1;i>=0,umr;i--)
        if(c[i]==')')umr--,vis[i]=1;
    for(int i=0;i<n;i++)if(vis[i])putchar(c[i]);
    return 0;
}
