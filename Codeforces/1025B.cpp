#include<bits/stdc++.h>
using namespace std;
#define maxn 150010
#define ll long long
const int N=2e9;
bool notp[maxn];
int id[maxn],a[maxn],b[maxn];
int n;
vector<int> P;
void pre()
{
    for(int i=2;i<(int)sqrt(N+0.5);i++)if(!notp[i])
    {
        P.push_back(i);
        id[i]=P.size();
        for(ll j=1ll*i*i;j<(int)sqrt(N+0.5);j+=i)notp[j]=1;
    }
    //printf("%d\n",P.size());
}
bool check(int x)
{
    for(int i=1;i<n;i++)
        if((a[i]%x) && (b[i]%x))return 0;
    return 1;
}
main()
{
    pre();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for(int p : P)
    {
        if(a[0]%p==0)
        {
            while(a[0]%p==0)a[0]/=p;
            if(check(p))return 0*printf("%d\n",p);
        }
        if(b[0]%p==0)
        {
            while(b[0]%p==0)b[0]/=p;
            if(check(p))return 0*printf("%d\n",p);
        }
    }
    if(a[0]!=1)
    {
        if(check(a[0]))return 0*printf("%d\n",a[0]);
    }
    if(b[0]!=1)
    {
        if(check(b[0]))return 0*printf("%d\n",b[0]);
    }
    puts("-1");
    return 0;
}
