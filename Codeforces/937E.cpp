#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
char s[maxn],t[maxn],tmp[maxn];
int n;
int cnt[26];
vector<int> ans;
void gao(int x)
{
    ans.push_back(x);
    for(int i=0;i<x;i++)tmp[i]=s[n-i-1];
    for(int i=x;i<n;i++)tmp[i]=s[i-x];
    for(int i=0;i<n;i++)s[i]=tmp[i];
}
main()
{
    scanf("%d",&n);
    scanf("%s %s",s,t);
    for(int i=0;i<n;i++)
        cnt[s[i]-'a']++,cnt[t[i]-'a']--;
    for(int i=0;i<26;i++)
        if(cnt[i])return 0*puts("-1");
    for(int i=0;i<n;i++)if(t[0]==s[i])
    {
        gao(n-i-1);gao(1);
        break;
    }
    bool rev=0;
    //printf("%s\n",s);
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)if(t[i]==s[j])
        {
            if(!rev)gao(n-i),gao(j),gao(1);
            else gao(n-j-1),gao(j-i+1),gao(i);
            rev^=1;
            //printf("%d %s\n",j,s);
            break;
        }
    }
    if(rev)gao(n);
    printf("%d\n",ans.size());
    for(int x : ans)printf("%d ",x);
    return 0;
}
