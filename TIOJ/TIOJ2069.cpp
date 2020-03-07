#include<bits/stdc++.h>
using namespace std;
#define maxn 2000010
int n;
vector<int> v1,v2;
main()
{
    scanf("%d",&n);
    if(n==1)return 0*printf("Yes\n%d",1);
    if(n&1)return 0*puts("No");
    for(int i=0;i<n/2;i++)v1.push_back(i);
    for(int i=n-1;i>=n/2;i--)v2.push_back(i);
    puts("Yes");
    printf("%d %d ",n,n-1);
    for(int i=1;i<n/2;i++)printf("%d %d ",(v1[i]-v2[i-1]+n)%n,(v2[i]-v1[i]+n)%n);
    return 0;
}
