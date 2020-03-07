#include<bits/stdc++.h>
using namespace std;
#define maxn 200000+10
char s[maxn],t[maxn];
int a[maxn];
main()
{
    scanf("%s%s",s,t);
    int len_s=strlen(s),len_t=strlen(t);
    int k;
    for(int i=0;i<len_s;i++)scanf("%d",&k),a[k-1]=i;
    //for(int i=0;i<len_s;i++)printf("%d ",a[i]);puts("");
    int l=0,r=len_s;
    while(r-l>1)
    {
        int m=(l+r)/2;
        int j=0;
        for(int i=0;i<len_s;i++)
            if(j<len_t)
            {
                if(t[j]==s[i] && m<=a[i])j++;
            }
        if(j==len_t)l=m;
        else r=m;
        //printf("%d %d\n",l,r);
    }
    printf("%d\n",l);
    return 0;
}
