#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define maxn 105
#define inf 2147483647
char s[maxn];
int vis[maxn][maxn],f[maxn][maxn],flag[maxn][maxn],pos[maxn][maxn];
bool match(char a,char b)
{
    return (a=='(' && b==')') && (a=='[' && b==']');
}
int dp(int L,int R)
{
    if(L>R)return 0;
    if(vis[L][R])return f[L][R];
    vis[L][R]=1;
    f[L][R]=inf;
    if(s[L]=='(' || s[L]=='[')
    {
        for(int i=L;i<=R;i++)
        {
            if(match(s[L],s[i]))
            {
                int sx=dp(L+1,i-1),sy=dp(i+1,R);//S=(S')=>轉到d(S')
                if(f[L][R]>sx+sy)
                {
                    f[L][R]=sx+sy;
                    flag[L][R]=-1;
                    pos[L][R]=i;
                }
            }
            int dx=dp(L+1,i),dy=dp(i+1,R);//S=AB=>轉到d(A)+d(B)
            if(f[L][R]>dx+dy+1)
            {
                f[L][R]=dx+dy+1;
                flag[L][R]=1;
                pos[L][R]=i;
            }
        }
    }
    else
    {
        int sx=dp(L+1,R);
        if(f[L][R]>sx+1)
        {
            f[L][R]=sx+1;
            flag[L][R]=1;
            pos[L][R]=L;
        }
    }
    return f[L][R];
}
void output(int L,int R)
{
    if(L<=R)
    {
        int p=pos[L][R];
        if(flag[L][R]<0)
        {
            putchar(s[L]);
            output(L+1,p-1);
            putchar(s[p]);
            output(p+1,R);
        }
        else
        {
            if(s[L]==')' || s[L]==']')
            {
                if(s[L]==')')putchar('(');
                else putchar('[');
                putchar(s[L]);
                output(L+1,R);
            }
            else
            {
                putchar(s[L]);
                output(L+1,p);
                if(s[L]=='(')putchar(')');
                else putchar(']');
                output(p+1,R);
            }

        }
    }
}
main()
{
    int t;scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        gets(s);
        memset(vis,0,sizeof(vis));
        int len=strlen(s);
        dp(0,len-1);
        putchar('\n');
        output(0,len-1);
        if(t)putchar('\n');
    }
    return 0;
}
