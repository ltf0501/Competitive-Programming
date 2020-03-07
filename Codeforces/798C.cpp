#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn];
int gcd(int a,int b)
{
    a=abs(a),b=abs(b);
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int ans=a[1];
    for(int i=2;i<=n;i++)ans=gcd(ans,a[i]);
    if(ans!=1){puts("YES\n0");return 0;}
    int cnt=0,cur=1;
    while(cur<n)
    {
        //printf("a[cur] = %d\n",a[cur]);
        if(a[cur]%2==0)
        {
            if(cur!=n-1){cur++;continue;}
            if(a[n]%2==0)break;
            else {cnt+=2;break;}
        }
        if(a[cur+1]%2==0)
        {
            cnt+=2;
            cur++;
            continue;
        }
        if(a[cur+1]%2==1)
        {
            cnt++;
            a[cur+1]=0;
            cur++;
            continue;
        }
    }
    puts("YES");
    printf("%d\n",cnt);
    return 0;
}
