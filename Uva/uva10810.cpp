#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 500000+5
int n;
long long cnt;
int A[maxn],T[maxn];
void mrge(int l,int r)
{
    if(r-l==1)return ;
    int m=l+(r-l)/2;
    mrge(l,m);
    mrge(m,r);
    int a=l,b=m,idx=l;
    while(a<m && b<r)
    {
        if(A[a]<=A[b]){T[idx++]=A[a++];}
        else
        {
            T[idx++]=A[b++];
            cnt+=(m-a);
        }
    }
    while(a<m)T[idx++]=A[a++];
    while(b<r)T[idx++]=A[b++];
    for(int i=l;i<r;i++)A[i]=T[i];
}
main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)scanf("%d",&A[i]);
        cnt=0;
        mrge(0,n);
        printf("%lld\n",cnt);
    }
    return 0;
}
