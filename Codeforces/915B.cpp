#include<bits/stdc++.h>
using namespace std;
int n,pos,l,r;
main()
{
    scanf("%d%d%d%d",&n,&pos,&l,&r);
    if(l==1 && r==n){puts("0");return 0;}
    else if(l==1){printf("%d\n",abs(r-pos)+1);return 0;}
    else if(r==n){printf("%d\n",abs(pos-l)+1);return 0;}
    int ans;
    if(l<=pos && pos<=r)ans=min(pos-l,r-pos)+1+r-l+1;
    else if(pos<l)ans=r-pos+2;
    else ans=pos-l+2;
    printf("%d\n",ans);
    return 0;
}
