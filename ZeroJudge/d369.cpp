#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
map<char,int> m;
void init()
{
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
}
main()
{
    init();
    int t;scanf("%d",&t);
    while(t--)
    {
        int c;scanf("%d",&c);
        if(c==1)
        {
            int ans=0;
            char s[15];
            scanf("%s",s+1);
            int n=strlen(s+1);
            for(int i=1;i<=n;i++)
            {
                if(i!=n)
                {
                    if(m[s[i]]<m[s[i+1]])ans-=m[s[i]];
                    else ans+=m[s[i]];
                }
                else ans+=m[s[i]];
            }
            printf("%d\n",ans);
        }
        if(c==2)
        {
            vector<char> ans;
            int a;
            scanf("%d",&a);
            int b[4];
            for(int i=0;i<=3;i++)
            {
                int t=a%10;
                b[i]=t;
                a/=10;
            }
            //for(int i=3;i>=0;i--)printf("%d ",b[i]);
            for(int i=3;i>=0;i--)
            {
                int t=b[i];
                if(i==3)
                {
                    if(t==1)ans.push_back('M');
                    if(t==2){ans.push_back('M');ans.push_back('M');}
                }
                if(i==2)
                {
                    if(t==1)ans.push_back('C');
                    if(t==2){ans.push_back('C');ans.push_back('C');}
                    if(t==3){ans.push_back('C');ans.push_back('C');ans.push_back('C');}
                    if(t==4){ans.push_back('C');ans.push_back('D');}
                    if(t==5)ans.push_back('D');
                    if(t==6){ans.push_back('D');ans.push_back('C');}
                    if(t==7){ans.push_back('D');ans.push_back('C');ans.push_back('C');}
                    if(t==8){ans.push_back('D');ans.push_back('C');ans.push_back('C');ans.push_back('C');}
                    if(t==9){ans.push_back('C');ans.push_back('M');}
                }
                if(i==1)
                {
                    if(t==1)ans.push_back('X');
                    if(t==2){ans.push_back('X');ans.push_back('X');}
                    if(t==3){ans.push_back('X');ans.push_back('X');ans.push_back('X');}
                    if(t==4){ans.push_back('X');ans.push_back('L');}
                    if(t==5)ans.push_back('L');
                    if(t==6){ans.push_back('L');ans.push_back('X');}
                    if(t==7){ans.push_back('L');ans.push_back('X');ans.push_back('X');}
                    if(t==8){ans.push_back('L');ans.push_back('X');ans.push_back('X');ans.push_back('X');}
                    if(t==9){ans.push_back('X');ans.push_back('C');}
                }
                if(i==0)
                {
                    if(t==1)ans.push_back('I');
                    if(t==2){ans.push_back('I');ans.push_back('I');}
                    if(t==3){ans.push_back('I');ans.push_back('I');ans.push_back('I');}
                    if(t==4){ans.push_back('I');ans.push_back('V');}
                    if(t==5)ans.push_back('V');
                    if(t==6){ans.push_back('V');ans.push_back('I');}
                    if(t==7){ans.push_back('V');ans.push_back('I');ans.push_back('I');}
                    if(t==8){ans.push_back('V');ans.push_back('I');ans.push_back('I');ans.push_back('I');}
                    if(t==9){ans.push_back('I');ans.push_back('X');}
                }
            }
            for(int i=0;i<ans.size();i++)printf("%c",ans[i]);
                puts("");
        }
    }
    return 0;
}
