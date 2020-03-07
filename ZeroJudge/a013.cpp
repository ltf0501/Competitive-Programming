#include<bits/stdc++.h>
using namespace std;
char s1[30],s2[30];
map<char,int> mp1;
map<int,char> mp2;
int val[30],a[30];
int get_num(char c[])
{
    int n=strlen(c);
    int ret=0;
    int cur=0;
    while(cur<n)
    {
        if(cur<n-1 && mp1[c[cur]]<mp1[c[cur+1]])
            ret+=(mp1[c[cur+1]]-mp1[c[cur]]),cur+=2;
        else ret+=mp1[c[cur]],cur++;
    }
    return ret;
}
void pre()
{
    mp2[1]='I',mp2[5]='V',mp2[10]='X',mp2[50]='L',mp2[100]='C',mp2[500]='D',mp2[1000]='M';
    mp1['I']=1,mp1['V']=5,mp1['X']=10,mp1['L']=50,mp1['C']=100,mp1['D']=500,mp1['M']=1000;
}
main()
{
    pre();
    while(1)
    {
        scanf("%s",s1);
        if(s1[0]=='#')break;
        scanf("%s",s2);
        int n=get_num(s1),m=get_num(s2);
        if(n==m){puts("ZERO");continue;}
        int k=abs(n-m);
        int cur=0,tt=1;
        while(k)
        {
            a[cur]=k%10;
            val[cur]=a[cur]*tt;
            k/=10;
            tt*=10,cur++;
        }
        for(int i=cur-1;i>=0;i--)
        {
            if(a[i]==4)printf("%c%c",mp2[val[i]/4],mp2[val[i]*5/4]);
            else if(a[i]==9)printf("%c%c",mp2[val[i]/9],mp2[val[i]*10/9]);
            else if(a[i]>=5)
            {
                putchar(mp2[val[i]*5/a[i]]);
                for(int j=0;j<a[i]-5;j++)putchar(mp2[val[i]/a[i]]);
            }
            else for(int j=0;j<a[i];j++)putchar(mp2[val[i]/a[i]]);
        }
        puts("");
    }
    return 0;
}
