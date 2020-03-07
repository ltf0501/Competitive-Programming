#include<bits/stdc++.h>
using namespace std;
vector<int> v[45];
void init()
{
    v[1].push_back(1);
    for(int i=2;i<=40;i++)
    {
        int cur=0,cnt=0,now=v[i-1][0];
        while(cur<v[i-1].size())
        {
            if(v[i-1][cur]==now)cnt++;
            else
            {
                v[i].push_back(cnt);
                v[i].push_back(now);
                cnt=1;
                now=v[i-1][cur];
            }
            if(cur==v[i-1].size()-1)
            {
                v[i].push_back(cnt);
                v[i].push_back(now);
                break;
            }
            cur++;
        }
    }
}
main()
{
    init();
    int n;
    while(~scanf("%d",&n))
    {
        for(int j : v[n])printf("%d",j);
        puts("");
    }
    return 0;
}
