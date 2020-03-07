#include<bits/stdc++.h>
using namespace std;
string s,t;
char c[5];
main()
{
    int n;scanf("%d",&n);
    int x=1,y=1;
    while(x+y<n+1)
    {
        if(y<n)printf("? %d %d %d %d\n",x,y+1,n,n),fflush(stdout);
        scanf("%s",c);
        if(c[0]=='Y')s+='R',y++;
        else s+='D',x++;
    }
    x=n,y=n;
    while(x+y>n+1)
    {
        if(x>1)printf("? %d %d %d %d\n",1,1,x-1,y),fflush(stdout);
        scanf("%s",c);
        if(c[0]=='Y')t+='D',x--;
        else t+='R',y--;
    }
    reverse(t.begin(),t.end());
    s+=t;
    cout<<'!'<<' '<<s<<endl;
    return 0;
}
