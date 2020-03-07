#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
const int C=1e9;
int n;
int a[maxn];
main()
{
    scanf("%d",&n);
    int ok=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i==1)continue;
        if(a[i]==a[i-1] || (ok && abs(a[i]-a[i-1])!=1 && abs(a[i]-a[i-1])!=ok))return 0*puts("NO");
        if(abs(a[i]-a[i-1])!=1)ok=abs(a[i]-a[i-1]);
    }
    if(!ok)return 0*printf("YES\n%d %d\n",C,C);
    //printf("%d\n",ok);

    for(int i=1;i<n;i++)
    {
        if(abs(a[i+1]-a[i])!=1 && (a[i]-1)/ok==(a[i+1]-1)/ok)return 0*puts("NO");
        if(abs(a[i+1]-a[i])==1 && (a[i]-1)/ok!=(a[i+1]-1)/ok)return 0*puts("NO");
    }
    puts("YES");
    printf("%d %d\n",C,ok);
    return 0;
}
