#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
char c[maxn];
int cnt[26];
main()
{
    int n;scanf("%d",&n);
    scanf("%s",c);
    if(n==1)return 0*puts("YES");
    for(int i=0;i<n;i++)cnt[c[i]-'a']++;
    bool flag=0;
    for(int i=0;i<26;i++)flag|=(cnt[i]>=2);
    puts(flag ? "YES" : "NO");
    return 0;
}
