#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 1000000+5
#define LL long long
vector<int> prime;
int vis[maxn/2];
void get_prime()
{
    prime.push_back(2);
    for(int i=1;i<maxn/2;i++)
    {
        if(!vis[i])
        {
            prime.push_back(2*i+1);
            for(int j=i;j<maxn/2;j+=2*i+1)vis[j]=1;
        }
    }
}
main()
{
    int a,b;
    get_prime();
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a>b)swap(a,b);
        int idx=upper_bound(prime.begin(),prime.end(),a)-prime.begin();
        int ans=idx;
        LL t=1;
        for(int i=a+1;i<=b;i++)t*=i;
        t++;
        for(int i=0;i<idx;i++)
            while(t%prime[i]==0)t/=prime[i];
        for(int i=idx;i<prime.size();i++)
        {
            if(t%prime[i]==0)
            {
                ans++;
                while(t%prime[i]==0)t/=prime[i];
            }
        }
        if(t!=1)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
