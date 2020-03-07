#include<bits/stdc++.h>
using namespace std;
#define M 1005
#define W 10000
#define P 100007
#define LL long long
struct Bigint
{
    int num,val[M];
    Bigint operator * (const int &A)const
    {
        Bigint res;res.num=num;
        for(int i=1;i<=num;i++)res.val[i]=val[i]*A;
        for(int i=1;i<=num;i++)
            if(res.val[i]>=W)
            {
                res.val[i+1]+=res.val[i]/W;
                res.val[i]%=W;
            }
        if(res.val[res.num+1])res.num++;
        return res;
    }
    Bigint operator / (const int &A)const
    {
        Bigint res;res.num=num;int tmp=val[num];
        for(int i=num;i>=1;i--)
        {
            res.val[i]=tmp/A;
            tmp=tmp%A*W+val[i-1];
        }
        if(!res.val[num])res.num--;
        return res;
    }
    bool operator < (const Bigint &A)const
    {
        if(num!=A.num)return num<A.num;
        for(int i=num;i>=1;i--)
            if(val[i]!=A.val[i])return val[i]<A.val[i];
        return false;
    }
}ans[M],ANS;
struct node
{
    int a,b,k;
    bool operator <(const node &A)const
    {
        return k<A.k;
    }
}s[M];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%d %d",&s[0].a,&s[0].b);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&s[i].a,&s[i].b);
        s[i].k=s[i].a*s[i].b;
    }
    sort(s+1,s+n+1);
    Bigint tmp;tmp.val[1]=s[0].a;tmp.num=1;
    tmp=tmp*s[1].a;
    ans[1]=tmp/s[1].k;ANS=ans[1];
    for(int i=2;i<=n;i++)
    {
        tmp=tmp*s[i].a;
        ans[i]=tmp/s[i].a/s[i].b;
        if(ANS<ans[i])ANS=ans[i];
    }
    printf("%d",ANS.val[ANS.num]);
    for(int i=ANS.num-1;i>=1;i--)printf("%04d",ANS.val[i]);
    puts("");
    return 0;
}
