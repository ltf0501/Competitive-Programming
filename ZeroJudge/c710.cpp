#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300010
int n,m;
vector<int> v,pos[maxn];
void gao(int x,int id)
{
    for(int i=1;i*i<=x;i++)if(x%i==0)
    {
        v.push_back(i);
        if(x!=i*i)v.push_back(x/i);
    }
    for(int s : v)pos[s].push_back(id);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        gao(x,i);
        v.clear(),v.resize(0);
    }
    for(int i=1;i<=m;i++)
    {
        int l,r,k;scanf("%d%d%d",&l,&r,&k);
        int num1=upper_bound(pos[k].begin(),pos[k].end(),r)-pos[k].begin();
        int num2=upper_bound(pos[k].begin(),pos[k].end(),l-1)-pos[k].begin();
        printf("%d\n",num1-num2);
    }
    return 0;
}
