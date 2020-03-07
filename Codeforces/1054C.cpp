#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int l[maxn],r[maxn],tot[maxn];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&l[i]);
    for(int i=1;i<=n;i++)scanf("%d",&r[i]);
    for(int i=1;i<=n;i++)tot[i]=l[i]+r[i];
    for(int i=1;i<=n;i++)
    {
        int le=0,ri=0;
        for(int j=1;j<=n;j++)
        {
            if(j<i)le+=(tot[j]<tot[i]);
            else if(j>=i)ri+=(tot[j]<tot[i]);
        }
        if(l[i]!=le || r[i]!=ri)return 0*puts("NO");
    }
    puts("YES");
    for(int i=1;i<=n;i++)printf("%d ",n-tot[i]);
    return 0;
}
