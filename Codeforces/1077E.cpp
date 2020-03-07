#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
vector<int> num;
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        mp[x]++;
    }
    for(auto s : mp)num.push_back(s.second);
    sort(num.begin(),num.end());
    int m=num.size();
    int ans=1;
    for(int st=1;st<=n;st++)
    {
        int tmp=0,pre_cal=m+1,cnt=0;
        for(int now=st;now<=n;now<<=1)
        {
            int k=lower_bound(num.begin(),num.end(),now)-num.begin();
            int cal=m-k;
            cnt+=pre_cal-cal+1;
            cnt=max(0,cnt);
            cal-=cnt;
            if(cal<=0)break;
            tmp+=now,pre_cal=cal;
        }
        ans=max(ans,tmp);
    }
    printf("%d\n",ans);
    return 0;
}
