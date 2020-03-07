#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
char c[maxn];
int check(char s)
{
    if(s=='!')return -1;
    return 'a'<=s && s<='z';
}
main()
{
    int k;scanf("%d",&k);
    scanf("%s",c+1);
    int len=strlen(c+1);
    int cnt=1;
    bool flag=check(c[1]);
    c[len+1]='!';
    int mx=0,cur=0,pre=0,now=0;
    for(int i=1;i<=len+1;i++)
    {
        //printf("%d\n",check(c[i]));
        if(check(c[i])==flag)now++;
        else
        {
            //printf("%d %d\n",pre,now);
            if(now<k)cur=0;
            else if(pre==k)cur++;
            else if(pre<k)cur=1;
            else cur=2;
            mx=max(mx,cur);
            pre=now;
            now=1;
            flag^=1;
        }
    }
    printf("%d\n",k*mx);
    return 0;
}
