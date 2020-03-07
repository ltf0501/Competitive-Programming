#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    int sum=0,mx=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        sum+=x;
        mx=max(mx,x);
    }
    for(int i=mx;;i++)
    {
        int tmp=n*i;
        if(sum<tmp-sum)return 0*printf("%d\n",i);
	}
    return 0;
}
