#include<bits/stdc++.h>
using namespace std;
vector<int> v;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        v.clear();
        int n,q;scanf("%d%d",&n,&q);
        v.push_back(1),v.push_back(n+1);
        while(q--)
        {
            int l,r,d;scanf("%d%d%d",&l,&r,&d);
            if(!d)continue;
            v.push_back(l),v.push_back(r+1);
        }
        sort(v.begin(),v.end());
        //for(int s : v)printf("%d ",s);puts("");
        int ans=0,flag=1;
        for(int i=1;i<v.size();i++)
            ans+=flag*(v[i]-v[i-1]),flag=-flag;
        ans=abs(ans);
        printf("%d\n",ans);
    }
    return 0;
}
