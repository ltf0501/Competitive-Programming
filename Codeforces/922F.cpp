#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
int n,k;
ll cnt;
vector<int> v;
int num[maxn];
bool no[maxn];
void pre()
{
    for(int i=1;i<maxn;i++)
        for(int j=i*2;j<maxn;j+=i)num[j]++;
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)cnt+=n/i-1;
    if(cnt<k)return 0*puts("No");
    pre();
    //for(int i=1;i<=n;i++)printf("%d ",num[i]);puts("");
    for(int i=2;i<=n;i++)if(cnt>k && cnt-k>=num[i]+n/i-1)
    {
        //printf("%d %d\n",i,cnt);
        cnt-=(num[i]+n/i-1);
        for(int j=i*2;j<maxn;j+=i)num[j]--;
        no[i]=1;
    }
    for(int i=1;i<=n;i++)if(!no[i])v.push_back(i);
    puts("Yes");
    printf("%d\n",v.size());
    for(int s : v)printf("%d ",s);
    return 0;
}
