#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
char s[maxn],t[maxn];
int cc[maxn];
main()
{
    scanf("%s",s);
    int n=strlen(s);
    printf("? ");
    for(int i=0;i<n;i++)putchar('a'+i%26);puts("");fflush(stdout);
    scanf("%s",t);
    for(int i=0;i<n;i++)cc[i]+=(t[i]-'a');
    printf("? ");
    for(int i=0;i<n;i++)putchar('a'+i/26%26);puts("");fflush(stdout);
    scanf("%s",t);
    for(int i=0;i<n;i++)cc[i]+=(t[i]-'a')*26;
    printf("? ");
    for(int i=0;i<n;i++)putchar('a'+i/26/26%26);puts("");fflush(stdout);
    scanf("%s",t);
    for(int i=0;i<n;i++)cc[i]+=(t[i]-'a')*26*26;
    printf("! ");
    for(int i=0;i<n;i++)t[cc[i]]=s[i];
    for(int i=0;i<n;i++)putchar(t[i]);puts("");fflush(stdout);
    return 0;
}
