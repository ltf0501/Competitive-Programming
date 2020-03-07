#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
char s[maxn],t[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    scanf("%s %s",s,t);
    int idx=-1;
    for(int i=0;i<n;i++)if(s[i]=='*')idx=i;
    if(idx==-1)
    {
        if(n!=m)return 0*puts("NO");
        for(int i=0;i<n;i++)if(s[i]!=t[i])return 0*puts("NO");
        return 0*puts("YES");
    }
    if(m<n-1)return 0*puts("NO");
    for(int i=0;i<idx;i++)if(s[i]!=t[i])return 0*puts("NO");
    for(int i=n-1;i>idx;i--)if(s[i]!=t[i+m-n])return 0*puts("NO");
    puts("YES");
    return 0;
}
