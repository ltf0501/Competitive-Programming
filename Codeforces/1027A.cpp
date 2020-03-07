#include<bits/stdc++.h>
using namespace std;
char c[105];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        scanf("%s",c);
        bool flag=1;
        for(int i=0;i<n;i++)
            if(abs(c[i]-c[n-1-i])!=0 && abs(c[i]-c[n-1-i])!=2){flag=0;break;}
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
