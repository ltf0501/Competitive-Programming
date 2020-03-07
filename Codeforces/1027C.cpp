#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int cnt[maxn];
vector<int> v;
void init()
{
    memset(cnt,0,sizeof(cnt));
    v.clear();
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        init();
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            cnt[x]++;
            if(cnt[x]>=2)v.push_back(x),cnt[x]=0;
        }
        sort(v.begin(),v.end());
        int id=0;
        for(int i=1;i<v.size()-1;i++)
            if(v[id+1]*v[i]>v[id]*v[i+1])id=i;
        printf("%d %d %d %d\n",v[id],v[id],v[id+1],v[id+1]);

    }
    return 0;
}
