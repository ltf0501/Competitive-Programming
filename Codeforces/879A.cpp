#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
#define ll long long
int s[maxn],d[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&s[i],&d[i]);
    int now=s[1];
    for(int i=2;i<=n;i++)
    {
        int j=ceil(((double)(now-s[i]+1)/(double)d[i]));

        //while(now>=s[i]+j*d[i])j++;
        //printf("%d\n",j);
        now=s[i]+j*d[i];
    }
    printf("%d\n",now);
    return 0;
}
