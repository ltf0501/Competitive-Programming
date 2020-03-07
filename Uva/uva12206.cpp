//hash解題
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define maxn 40000+10
const int x=123;
int n,m,pos;
unsigned long long H[maxn],xp[maxn];
unsigned long long Hash[maxn];
int Rank[maxn];

bool cmp(const int& a,const int& b)
{
    return Hash[a]<Hash[b] || (Hash[a]==Hash[b] && a<b);
}
int possble(int L)
{
    int c=0;
    pos=-1;
    for(int i=0;i<n-L+1;i++)
    {
        Rank[i]=i;
        Hash[i]=H[i]-H[i+L]*xp[L];
    }
    sort(Rank,Rank+n-L+1,cmp);
    for(int i=0;i<n-L+1;i++)
    {
        if(i==0 || Hash[Rank[i]]!=Hash[Rank[i-1]])c=0;
        if(++c>=m)pos=max(pos,Rank[i]);
    }
    return pos>=0;
}
main()
{
    char s[maxn];
    while(scanf("%d",&m)==1 && m)
    {
        scanf("%s",s);
        n=strlen(s);
        H[n]=0;
        for(int i=n-1;i>=0;i--)H[i]=H[i+1]*x+(s[i]-'a');
        xp[0]=1;
        for(int i=1;i<=n;i++)xp[i]=xp[i-1]*x;

        if(!possble(1))printf("none\n");
        else
        {
            int L=1,R=n+1;
            while(R-L>1)
            {
                int M=L+(R-L)/2;//二分答案L
                if(possble(M))L=M;else R=M;
            }
            possble(L);
            printf("%d %d\n",L,pos);
        }
    }
    return 0;
}
/*
3
baaaababababbababbab
11
baaaababababbababbab
3
cccccc
0

5 12
none
4 2
*/
