#include<bits/stdc++.h>
using namespace std;
#define maxn 1010

vector<int> v;
main()
{
    int n;scanf("%d",&n);
    int pre=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(i!=1 && x==1)v.push_back(pre);
        pre=x;
    }
    v.push_back(pre);
    printf("%d\n",v.size());
    for(int s : v)printf("%d ",s);
    return 0;
}

