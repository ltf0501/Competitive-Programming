#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1048576
char a[maxn],s[maxn];
int p[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(p,0,sizeof(p));
        scanf("%s",a+1);
        int len=strlen(a+1);
        s[0]='$';
        for(int i=1;i<=2*len;i++)
        {
            if(i&1)s[i]='#';
            else s[i]=a[i/2];
        }
        s[2*len+1]='#';
        int mx=0,id=0,ans=0;
        for(int i=1;i<=2*len;i++)
        {
            p[i]=mx>i ? min(p[2*id-i],mx-i) : 1;
            while(s[i+p[i]]==s[i-p[i]])p[i]++;
            if(i+p[i]>mx)mx=i+p[i],id=i;
            ans=max(ans,p[i]);
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
