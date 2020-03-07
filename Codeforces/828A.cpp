#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
main()
{
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    int cnt=0,c=0;
    for(int i=1;i<=n;i++)
    {
        int t;scanf("%d",&t);
        if(t==1)
        {
            if(a>0)a--;
            else if(b>0)b--,c++;
            else if(c>0)c--;
            else cnt++;
        }
        else
        {
            if(b==0)cnt+=2;
            else b--;
        }
    }
    printf("%d\n",cnt);
    return 0;
}

