#include<bits/stdc++.h>
using namespace std;
#define maxn 5050
int cnt[3];
char s[maxn];
main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='a')
        {
            if(cnt[1] || cnt[2])return 0*puts("NO");
            cnt[0]++;
        }
        else if(s[i]=='b')
        {
            if(!cnt[0] || cnt[2])return 0*puts("NO");
            cnt[1]++;
        }
        else
        {
            if(!cnt[0] || !cnt[1])return 0*puts("NO");
            cnt[2]++;
        }
    }
    if(!cnt[0] || !cnt[1] || !cnt[2])return 0*puts("NO");
    if(cnt[0]!=cnt[2] && cnt[1]!=cnt[2])return 0*puts("NO");
    puts("YES");
    return 0;
}

