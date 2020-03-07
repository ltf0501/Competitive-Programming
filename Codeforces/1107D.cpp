#include<bits/stdc++.h>
using namespace std;
#define maxn 5210
bitset<maxn> b[maxn];
char s[maxn];
int n;
int get_val(char c)
{
    if('0'<=c && c<='9')return c-'0';
    return c-'A'+10;
}
bool r[maxn],c[maxn];
main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<n;j+=4)
        {
            int val=get_val(s[j>>2]);
            for(int k=0;k<4;k++)
                if((val>>(3-k))&1)b[i][j+k]=1;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        bool flag=1;
        for(int j=0;j<n;j++)if(b[i][j]!=b[i+1][j])
        {
            flag=0;break;
        }
        r[i]=flag;
        flag=1;
        for(int j=0;j<n;j++)if(b[j][i]!=b[j][i+1])
        {
            flag=0;break;
        }
        c[i]=flag;
    }
    for(int i=n;i>1;i--)if(n%i==0)
    {
        bool flag=1;
        for(int j=0;j<n;j++)if(j%i!=i-1)
        {
            if(!c[j] || !r[j])flag=0;
        }
        if(flag)return 0*printf("%d\n",i);
    }
    puts("1");
    return 0;
}
