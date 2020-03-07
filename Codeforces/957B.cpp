#include<bits/stdc++.h>
using namespace std;
char c[55][55];
int n,m;
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
    {
        bool is=0;
        for(int k=1;k<=m;k++)
        {
            if(c[i][k]=='#' && c[j][k]=='#')is=1;
        }
        if(is)
        {
            for(int k=1;k<=m;k++)
            {
                if(((c[i][k]=='#')^(c[j][k]=='#'))==1)return 0*puts("No");
            }
        }
    }
    puts("Yes");
    return 0;
}
