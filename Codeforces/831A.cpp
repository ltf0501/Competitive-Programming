#include<bits/stdc++.h>
using namespace std;
int n,a[105];
main()
{
    scanf("%d",&n);
    int pos=0;
    int now=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    bool ok=1;
    for(int i=1;i<n;i++)
    {
        if(pos==0)
        {
            if(a[i]==a[i+1])pos++;
            else if(a[i]>a[i+1])pos+=2;
        }
        else if(pos==1)
        {
            if(a[i]<a[i+1]){ok=0;break;}
            else if(a[i]>a[i+1])pos++;
        }
        else
        {
            if(a[i]<=a[i+1]){ok=0;break;}
        }
    }
    puts(ok ? "YES" : "NO");
    return 0;
}

