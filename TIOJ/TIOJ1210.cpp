//Haval
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 10000+5
int n;
int a[maxn];
bool solve()
{
    for(int i=0;i<n;i++)
    {
        sort(a+i,a+n,greater<int>());
        for(int j=i+1;j<n && a[i]>0;j++)
        {
            a[i]--;a[j]--;
            if(a[j]<0)return 0;
        }
        if(a[i]>0)return 0;
    }
    return 1;
}
main()
{
    while(~scanf("%d",&n) && n)
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        if(solve())puts("Yes");
        else puts("No");
    }
    return 0;
}
