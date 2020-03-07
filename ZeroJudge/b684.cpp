#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int f[maxn];
int inv[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&f[i]),inv[f[i]]=i;
    int cnt=0;
    int flag=1;
    for(int i=1;i<n;i++)
    {
        if(flag*(inv[i+1]-inv[i])>0)continue;
        cnt++,flag=-flag;
    }
    printf("%d\n",cnt);
    return 0;
}
