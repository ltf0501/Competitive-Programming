#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
char c[maxn];
int n;
int val(char c){return c=='U' ? -1 : 1;}
main()
{
    scanf("%d",&n);
    scanf("%s",c+1);
    int cur=0,ans=0;
    for(int i=1;i<n;i++)
    {
        cur+=val(c[i]);
        if(cur==0 && c[i]==c[i+1])ans++;
    }
    printf("%d\n",ans);
    return 0;
}
