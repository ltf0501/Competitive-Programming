#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 10000
typedef pair<int,int> P;
vector<P> v[maxn+5],nv[maxn+5];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
    int n;
    while(cin>>n,n!=0)
    {
        int l,u,r,d;
        long long ans=0;
        for(int i=0;i<n;++i)
        {
            cin>>l>>u>>r>>d;
            v[u+1].push_back({l+1,1});
            v[u+1].push_back({r+1,-1});
            nv[d+1].push_back({l+1,1});
            nv[d+1].push_back({r+1,-1});
        }
        multiset<P> s;
        for(int i=1;i<=maxn;++i)
        {
            for(P j:nv[i]) s.erase(s.find(j));
            for(P j:v[i]) s.insert(j);
            int la=1,sum=0;
            for(P j:s)
            {
                ans+=(1LL<<sum)*(j.first-la);
                sum+=j.second;
                la=j.first;
            }
            if(s.size()) ans+=( maxn - ((--s.end())->first) )+1;
            else ans+=maxn;
        }
        cout<<ans<<endl;
        for(int i=0;i<=maxn;++i) v[i].clear(),nv[i].clear();
    }
}
