#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
char c[maxn];
int f[maxn];
int cnt[maxn];
vector<int> v;
main()
{
    scanf("%s",c);
    int n=strlen(c);
    for(int i=1;i<n;i++)
    {
        int j=f[i];
        while(j && c[i]!=c[j])j=f[j];
        f[i+1]=(c[i]==c[j]) ? j+1 : 0;
    }
    for(int i=1;i<=n;i++)cnt[i]=1;
    for(int i=n;i;i--)cnt[f[i]]+=cnt[i];
    int cur=n;
    while(cur)
    {
        v.push_back(cur);
        cur=f[cur];
    }
    printf("%d\n",v.size());
    reverse(v.begin(),v.end());
    for(int s : v)
        printf("%d %d\n",s,cnt[s]);
    return 0;
}

