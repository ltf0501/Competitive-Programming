#include<bits/stdc++.h>
using namespace std;
char c[5050];
main()
{
    scanf("%s",c+1);
    int n=strlen(c+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=0,t=0,cur=0;
        for(int j=i;j<=n;j++)
        {
            if(c[j]=='(')l++;
            else if(c[j]==')')r++;
            else t++;
            if(r>l+t)break;
            cur=max(cur,t-(l+t-r)/2);
            if((j-i)%2==0)continue;
            //printf("%d %d: %d %d %d\n",i,j,l,r,t);
            if((r+t-l)/2>=cur)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

