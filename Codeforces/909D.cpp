#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
char c[maxn];
int nxt[maxn],pre[maxn],n;
bool vis[maxn];
inline bool check(int x)
{
    return (pre[x]!=0 && c[x]!=c[pre[x]]) ||
           (nxt[x]!=n+1 && c[x]!=c[nxt[x]]);
}
inline void del(int x)
{
    nxt[pre[x]]=nxt[x];
    pre[nxt[x]]=pre[x];
}
vector<int> v,tmp;
main()
{
    scanf("%s",c+1);
    n=strlen(c+1);
    for(int i=1;i<=n;i++)nxt[i]=i+1,pre[i]=i-1;
    for(int i=1;i<=n;i++)if(check(i))v.push_back(i),vis[i]=1;
    int ans=0;
    while(!v.empty())
    {
        ans++;
        for(int k : v)
        {
            tmp.push_back(nxt[k]),tmp.push_back(pre[k]);
            del(k);
        }
        v.clear();v.resize(0);
        for(int k : tmp)
        {
            if(1<=k && k<=n && !vis[k] && check(k))vis[k]=1,v.push_back(k);
        }
        tmp.clear();tmp.resize(0);
    }
    printf("%d\n",ans);
    return 0;
}
