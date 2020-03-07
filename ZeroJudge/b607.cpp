#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
bool is_prime[maxn],vis[maxn];
void build()
{
    for(ll i=2;i<=maxn;i++)if(!vis[i])
    {
        vis[i]=is_prime[i]=1;
        for(ll j=i*i;j<=maxn;j+=i)vis[j]=1;
    }
}
main()
{
    build();
    int n;
    vector<int> ans;
    while(~scanf("%d",&n) && n)
    {
        if(n==2){puts("1 2");continue;}
        int cnt=0;
        ans.clear();
        if(is_prime[n])cnt++,ans.push_back(n);
        else
        {
            if(n&1)
            {
                if(is_prime[n-2])ans.push_back(2),ans.push_back(n-2),cnt+=2;
                else
                {
                    int k=n/3;
                    while(!is_prime[k])k++;
                    ans.push_back(k);
                    n-=k;
                    k=n/2;
                    while(!(is_prime[k] && is_prime[n-k]))k--;
                    ans.push_back(k),ans.push_back(n-k);
                    cnt+=3;
                    sort(ans.begin(),ans.end());
                }
            }
            else
            {
                int k=n/2;
                while(!(is_prime[k] && is_prime[n-k]))k--;
                ans.push_back(k),ans.push_back(n-k);
                cnt+=2;
            }
        }
        printf("%d ",cnt);
        for(int s : ans)printf("%d ",s);
        puts("");
    }
    return 0;
}
