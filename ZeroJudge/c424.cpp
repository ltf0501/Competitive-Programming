#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
int a[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            int mi=a[i],mx=a[i];
            for(int j=i+1;j<=n;j++)
            {
                mi=min(mi,a[j]),mx=max(mx,a[j]);
                if(((a[j]==mx && a[i]==mi) || (a[j]==mi && a[i]==mx)) && mx-mi==j-i)cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
