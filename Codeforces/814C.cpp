#include<bits/stdc++.h>
using namespace std;
#define maxn 1505
int n;
char s[maxn];
vector<int> pos[26];
vector<int> mi[26];
main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)pos[s[i]-'a'].push_back(i);
    for(int i=0;i<26;i++)
    {
        for(int j=1;j<pos[i].size();j++)
        {
            int ans=maxn;
            for(int k=0;k+j<pos[i].size();k++)
                ans=min(ans,pos[i][k+j]-pos[i][k]-j);
            mi[i].push_back(ans);
        }
    }
    int q;scanf("%d",&q);
    while(q--)
    {
        int m;char c;
        cin>>m>>c;
        if(pos[c-'a'].empty()){printf("%d\n",m);continue;}
        //for(int v : mi[c-'a'])printf("%d ",v);
        //puts("");
        int k=(upper_bound(mi[c-'a'].begin(),mi[c-'a'].end(),m)-mi[c-'a'].begin())-1;
        printf("%d\n",min(m+k+2,n));
    }
    return 0;
}
