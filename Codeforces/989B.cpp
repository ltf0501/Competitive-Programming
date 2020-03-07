#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
char c[maxn];
int n,k;
bool check[2][maxn];
int yes[maxn];
main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",c);
    for(int i=0;i<n;i++)
    {
        int a=i/k,b=i%k;
        if(c[i]=='.')yes[b]++;
        else if(c[i]=='0')check[0][b]=1;
        else if(c[i]=='1')check[1][b]=1;
    }
    bool flag=0;
    for(int i=0;i<k;i++)
    {
        //printf("%d %d %d\n",check[0][i],check[1][i],yes[i]);
        if((check[0][i] && check[1][i]) || yes[i]>=2 || (yes[i]==1 && (check[0][i] || check[1][i])))flag=1;
    }
    if(!flag)return 0*puts("No");
    for(int i=0;i<n;i++)
    {
        int a=i/k,b=i%k;
        if(c[i]!='.'){putchar(c[i]);continue;}
        char s;
        if(check[0][b])putchar('1'),check[1][b]=1;
        else putchar('0'),check[0][b]=1;
    }
    return 0;
}
