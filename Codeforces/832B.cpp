#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
char a[30],s[maxn],t[maxn];
bool good[30];
main()
{
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++)good[a[i]-'a']=1;
    scanf("%s",s);
    int star=strlen(s);
    for(int i=0;i<strlen(s);i++)if(s[i]=='*'){star=i;break;}
    int q;scanf("%d",&q);
    while(q--)
    {
        bool flag=1;
        scanf("%s",t);
        int s1=0,t1=0;
        while(s1<star && flag)
        {
            if(s[s1]=='?')
            {
                if(good[t[t1]-'a'])s1++,t1++;
                else flag=0;
            }
            else
            {
                if(s[s1]==t[t1])s1++,t1++;
                else flag=0;
            }
        }
        int l=t1;
        s1=strlen(s)-1,t1=strlen(t)-1;
        while(s1>star && flag)
        {
            if(s[s1]=='?')
            {
                if(good[t[t1]-'a'])s1--,t1--;
                else flag=0;
            }
            else
            {
                if(s[s1]==t[t1])s1--,t1--;
                else flag=0;
            }
        }
        int r=t1;
        if(l>r && (star!=strlen(s) && star!=0 && star!=strlen(s)-1))flag=0;
        printf("%d %d\n",l,r);
        for(int i=l;i<=r;i++)
            if(good[t[i]-'a']){flag=0;break;}
        puts(flag ? "YES" : "NO");
    }
    return 0;
}

