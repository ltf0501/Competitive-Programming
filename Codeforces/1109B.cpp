#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
char s[maxn];
int cnt[26];
int solve(int l,int r)
{
    if((r-l)&1)return 2;
    bool flag=1;
    int m=(l+r)>>1;
    for(int i=l;i<m;i++)
        if(s[i]!=s[m+i-l]){flag=0;break;}
    if(!flag)return 1;
    return solve(l,m);
}
main()
{
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++)cnt[s[i]-'a']++;
    if(*max_element(cnt,cnt+26)>=n-1)return 0*puts("Impossible");
    if(n&1)return 0*puts("2");
    printf("%d\n",solve(0,n));
    return 0;
}
