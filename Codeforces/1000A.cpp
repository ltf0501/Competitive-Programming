#include<bits/stdc++.h>
using namespace std;
#define maxn 105
map<string,int> mp;
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        mp[s]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        if(mp[s])mp[s]--;
        else ans++;
    }
    printf("%d\n",ans);
    return 0;
}
