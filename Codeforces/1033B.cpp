#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxp=1e6;
int t;
bool notp[maxp];
vector<int> p;
void init()
{
    for(int i=2;i<maxp;i++)if(!notp[i])
    {
        p.push_back(i);
        for(ll j=1ll*i*i;j<maxp;j+=i)notp[j]=1;
    }
    //printf("%d\n",p.size()*500);
}
main()
{
    init();
    scanf("%d",&t);
    while(t--)
    {
        ll a,b;scanf("%lld%lld",&a,&b);
        if(a-b!=1){puts("NO");continue;}
        ll k=a+b;
        //printf("%lld\n",k);
        bool flag=1;
        for(int s : p)
        {
            if(1ll*s*s>k)break;
            if(k%s==0){flag=0;break;}
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
