#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,x;scanf("%d%d",&n,&x);
    if(x>n || x==0){puts("-1");return 0;}
    for(int i=1;i<=n;i++)printf("%d ",i);puts("");
    for(int i=1;i<x;i++)printf("%d ",i);
    for(int i=n;i>=x;i--)printf("%d ",i);puts("");
    return 0;
}
