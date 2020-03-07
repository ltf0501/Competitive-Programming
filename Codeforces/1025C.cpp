#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
char c[maxn];
main()
{
    scanf("%s",c);
    int n=strlen(c);
    int ans=0,now=1;
    for(int i=1;i<n;i++)
    {
        if(c[i]!=c[i-1])now++;
        else ans=max(ans,now),now=1;
    }
    ans=max(ans,now);
    if(c[0]!=c[n-1])
    {
        int sum=2;
        for(int i=1;;i++)
        {
            if(c[i]!=c[i-1])sum++;
            else break;
        }
        for(int i=n-2;;i--)
        {
            if(c[i]!=c[i+1])sum++;
            else break;
        }
        sum=min(sum,n);
        ans=max(ans,sum);
    }
    printf("%d\n",ans);
    return 0;
}
