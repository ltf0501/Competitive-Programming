#include<bits/stdc++.h>
using namespace std;
char s[10];
main()
{
    scanf("%s",s);
    if(s[0]==s[4] && s[1]==s[3]){puts("0");return 0;}
    int h=(s[1]-'0')+10*(s[0]-'0');
    int invh=(s[0]-'0')+10*(s[1]-'0'),m=(s[4]-'0')+10*(s[3]-'0');
    //printf("%d %d %d\n",h,invh,m);
    if(h==23 && m>32)printf("%d\n",60-m);
    else if(s[1]<'5')
    {
        if(m>invh)printf("%d\n",70+invh-m);
        else printf("%d\n",invh-m);
    }
    else
    {
        if(s[1]=='5' && invh>=m)printf("%d\n",invh-m);
        else
        {
            if(h<10)printf("%d\n",(9-h)*60+(60-m)+1);
            else printf("%d\n",(19-h)*60+(60-m)+2);
        }

    }
    return 0;
}

