#include<bits/stdc++.h>
using namespace std;
int n;
char c[205];
int cnt[30];
vector<int> v;
main()
{
    scanf("%d%s",&n,c+1);
    v.push_back(0);
    for(int i=1;i<=n;i++)if(isupper(c[i]))v.push_back(i);
    v.push_back(n+1);
    int mx=0;
    for(int i=0;i<v.size()-1;i++)
    {
        int l=v[i],r=v[i+1];
        memset(cnt,0,sizeof(cnt));
        for(int j=l+1;j<r;j++)cnt[c[j]-'a']++;
        int cur=0;
        for(int j=0;j<26;j++)if(cnt[j])cur++;
        mx=max(mx,cur);
    }
    printf("%d\n",mx);
    return 0;
}
