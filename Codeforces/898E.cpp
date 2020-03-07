#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 200010
vector<int> v;
main()
{
    int n;cin>>n;
    int cnt=0,cnt0=0;
    for(int i=1;i<=n;i++)
    {
        int c;cin>>c;
        int k=(int)sqrt(c+0.5);
        //printf("%d ",k);
        if(k*k==c)
        {
            cnt++;
            if(c==0)cnt0++;
        }
        else
        {
            v.push_back(min(c-k*k,(k+1)*(k+1)-c));
        }
    }
    sort(v.begin(),v.end());
    //for(int s : v)printf("%d ",s);puts("");
    if(cnt==n/2){puts("0");return 0;}
    if(cnt>n/2)
    {
        int t=cnt-n/2;
        cnt-=cnt0;
        //printf("%d\n",cnt);
        int a=(cnt>=t)?t:cnt+2*(t-cnt);
        cout<<a;
    }
    else
    {
        int t=n/2-cnt;
        int a=0;
        for(int i=0;i<t;i++)a+=v[i];
        cout<<a;
    }
    return 0;
}
