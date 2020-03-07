#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 300000+10
#define sz 4096
int n,m,u,A[maxn],block[5500][5500];
void init()
{
    scanf("%d%d%d",&n,&m,&u);
    int b=0,j=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        block[b][j]=A[i];
        if(++j==sz)b++,j=0;
    }
    for(int i=0;i<b;i++)sort(block[i],block[i]+sz);
    if(j)sort(block[b],block[b]+j);
}
int query(int L,int R,int v)
{
    int lb=L/sz,rb=R/sz;
    //printf("%d %d\n",lb,rb);
    int ans=0;
    if(lb==rb){for(int i=L;i<=R;i++)if(A[i]<v)ans++;}
    else
    {
        for(int i=L;i<(lb+1)*sz;i++)if(A[i]<v)ans++;
        for(int i=rb*sz;i<=R;i++)if(A[i]<v)ans++;
        for(int b=lb+1;b<rb;b++)
            ans+=lower_bound(block[b],block[b]+sz,v)-block[b];
    }
    return ans;
}
void change(int p,int x)
{
    if(A[p]==x)return ;
    int old=A[p],pos=0,*B=&block[p/sz][0];
    A[p]=x;

    while(B[pos]<old)pos++;
    B[pos]=x;
    if(x>old)
        while(pos<sz-1 && B[pos]>B[pos+1]){swap(B[pos],B[pos+1]);pos++;}
    else
        while(pos>0 && B[pos]<B[pos-1]){swap(B[pos],B[pos-1]);pos--;}
}
main()
{
    init();
    while(m--)
    {
        int L,R,v,p;
        scanf("%d%d%d%d",&L,&R,&v,&p);L--,R--,p--;
        int k=query(L,R,v);
        //printf("k = %d\n",k);
        change(p,(long long)u*k/(R-L+1));
    }
    for(int i=0;i<n;i++)printf("%d\n",A[i]);
    return 0;
}
