#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
pii a[maxn];
int n,p,q;
vector<int> ans[2];
bool check(int x,int y)
{
    int i,j;
    for(i=n;i>0;i--)
        if(1ll*a[i].F*(n-i+1)>=(ll)x)break;
    if(i)
    {
        for(j=i-1;j>0;j--)
            if(1ll*a[j].F*(i-j)>=(ll)y)break;
        if(j)
        {
            for(;j<i;j++)ans[1].push_back(a[j].S);
            for(;i<=n;i++)ans[0].push_back(a[i].S);
            return 1;
        }
        else return 0;
    }
    else return 0;
}
void print(vector<int> a,vector<int> b)
{
    puts("Yes");
    printf("%d %d\n",a.size(),b.size());
    for(int s : a)printf("%d ",s);puts("");
    for(int s : b)printf("%d ",s);puts("");
}
main()
{
    scanf("%d%d%d",&n,&p,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].F),a[i].S=i;
    sort(a+1,a+n+1);
    if(check(p,q)){print(ans[0],ans[1]);return 0;}
    else if(check(q,p)){print(ans[1],ans[0]);return 0;}
    puts("No");
    return 0;
}
