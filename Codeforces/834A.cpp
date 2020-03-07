#include<bits/stdc++.h>
using namespace std;
const char c[]={118,60,94,62};
main()
{
    char c1,c2;
    cin>>c1>>c2;
    int n;scanf("%d",&n);
    //if(n>=4){puts("undefine");return 0;}
    int st,ed;
    for(int i=0;i<=3;i++)
    {
        if(c[i]==c1)st=i;
        if(c[i]==c2)ed=i;
    }
    int k=ed-st+4;
    if(k%2==0){puts("undefined");return 0;}
    else if((k%4==1 && n%4==1) || (k%4==3 && n%4==3))puts("cw");
    else puts("ccw");
    return 0;
}

