#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
#define maxn 4001*1000
#define maxsz 62
int tree[maxn][maxsz],val[maxn],End[maxn];

inline int change(char c)
{
    if(c>='a'&&c<='z') return c-'a';
    if(c>='A'&&c<='Z') return c-'A'+26;
    return c-'0'+52;
}

int cnt;
LL ans;

inline void Insert(char *s)
{
    int id=0,l=strlen(s);
    ans+=val[0];
    val[0]++;
    for(int i=0; i<l; ++i)
    {
        int c=change(s[i]);
        if(!tree[id][c])
        {
            memset(tree[cnt],0,sizeof(tree[cnt]));
            val[cnt]=0;
            End[cnt]=0;
            tree[id][c]=cnt++;
        }
        id=tree[id][c];
        ans+=2LL*val[id];
        val[id]++;
    }
    ans+=End[id];
    End[id]++;
}


void init()
{
    cnt=1;
    ans=0;
    memset(tree[0],0,sizeof(tree[0]));
    val[0]=End[0]=0;
}

char s[1005];

int main()
{
    int n,i,ca=1;
    while(~scanf("%d",&n)&&n)
    {
        init();
        for(i=0;i<n;++i)
        {
            scanf("%s",s);
            Insert(s);
        }
        printf("Case %d: %lld\n",ca++,ans);
    }
    return 0;
}
