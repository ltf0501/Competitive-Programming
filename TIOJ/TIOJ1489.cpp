#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int cnt[27];
char c[maxn];
main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        memset(cnt,0,sizeof(cnt));
        int L=n+1,R=3*n;
        scanf("%s",c+1);
        int now=0;
        int l=1,r=1;
        while(r<=n+1)
        {
            if(r<=n)
            {
                if(!cnt[c[r]-'a'])now++;
                cnt[c[r]-'a']++;
            }
            if(now<26)r++;
            else
            {
                while(cnt[c[l]-'a']>1)cnt[c[l]-'a']--,l++;
                if(r-l<R-L)L=l,R=r;
                r++;
            }
        }
        if(L==n+1)printf("not found");
        else for(int i=L;i<=R;i++)printf("%c",c[i]);
        puts("");
    }
    return 0;
}
