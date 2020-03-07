#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a,b,c;
set<int> s;
main()
{
    scanf("%d%d%d",&a,&b,&c);
    a%=b;
    s.insert(a);
    for(int i=1;;i++)
    {
        if(a*10/b==c){printf("%d\n",i);return 0;}
        a=(a*10)%b;
        if(s.find(a)!=s.end())break;
        s.insert(a);
    }
    puts("-1");
    return 0;
}
