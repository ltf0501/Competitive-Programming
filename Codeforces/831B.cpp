#include<bits/stdc++.h>
using namespace std;
char s[26],t[26],c[1005];
int a[26];
main()
{
    scanf("%s %s",s,t);
    for(int i=0;i<26;i++)a[s[i]-'a']=t[i]-'a';
    //for(int i=0;i<26;i++)printf("%d ",a[i]);
    scanf("%s",c);
    for(int i=0;i<strlen(c);i++)
    {
        if('0'<=c[i] && c[i]<='9')printf("%c",c[i]);
        else if('A'<=c[i] && c[i]<='Z')printf("%c",a[c[i]-'A']+'A');
        else printf("%c",a[c[i]-'a']+'a');
    }
    return 0;
}
