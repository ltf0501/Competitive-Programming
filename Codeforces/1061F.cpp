#include<bits/stdc++.h>
using namespace std;
#define maxn 1510
#define umr fflush(stdout)
int n,k;
main()
{
    scanf("%d%d",&n,&k);
    int dep=0,now=1,sum=0;
    while(sum<n)sum+=now,dep++,now*=k;
    vector<int> v;
    int x,y;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while(1)
    {
        v.clear();v.resize(0);
        x=uniform_int_distribution<int>(1,n)(rng);
        y=uniform_int_distribution<int>(1,n)(rng);
        for(int i=1;i<=n;i++)
        {
            printf("? %d %d %d\n",x,i,y);umr;
            char c[5];scanf("%s",c);
            if(c[0]=='Y')v.push_back(i);
        }
        if(v.size()==(dep<<1)-1)break;
    }
    for(int u : v)
    {
        int cnt=0;
        for(int m : v)
        {
            printf("? %d %d %d\n",x,m,u);umr;
            char c[5];scanf("%s",c);
            if(c[0]=='Y')cnt++;
        }
        if(cnt==dep)
        {
            printf("! %d\n",u);umr;
            break;
        }
    }
    return 0;
}
