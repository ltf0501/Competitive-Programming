#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn],b[maxn],r[maxn];
vector<int> ans;
bool cmp(int i,int j)
{
    return a[i]>a[j];
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)r[i]=i;
    sort(r+1,r+n+1,cmp);
    ans.push_back(r[1]);
    for(int i=1;2*i+1<=n;i++)
    {
        if(b[r[2*i]]>b[r[2*i+1]])ans.push_back(r[2*i]);
        else ans.push_back(r[2*i+1]);
    }
    if(!(n&1))ans.push_back(r[n]);
    printf("%d\n",ans.size());
    for(int v : ans)printf("%d ",v);
    puts("");
    return 0;
}
