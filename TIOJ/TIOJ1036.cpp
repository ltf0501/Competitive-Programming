#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 10000000
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
    get_prime();
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        int idx=upper_bound(prime.begin(),prime.end(),n)-prime.begin();
        printf("%d\n",idx);
    }
    return 0;
}
