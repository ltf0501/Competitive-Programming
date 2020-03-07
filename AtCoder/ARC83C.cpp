#include<bits/stdc++.h>
using namespace std;

main()
{
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    int ans[4];
    double mx=0.0;
    for(int m=0;;m++)
    {
        for(int n=0;;n++)
        {
            if(m==0 && n==0)continue;
            if(100*(m*a+n*b)>f)break;
            for(int t=0;;t++)
            {
                for(int s=0;;s++)
                {
                    if(100*(m*a+n*b)+t*c+s*d>f)break;
                    if(t*c+s*d>(m*a+n*b)*e)break;
                    if(t*c+s*d>mx*(m*a+n*b))
                    {
                        ans[0]=m,ans[1]=n,ans[2]=t,ans[3]=s;
                        mx=(double)(t*c+s*d)/(double)(m*a+n*b);
                        //cout<<mx<<' '<<m<<' '<<n<<' '<<t<<' '<<s<<'\n';
                    }
                }
                if(100*(m*a+n*b)+t*c>f)break;
            }
        }
        if(100*m*a>f)break;
    }
    if(mx==0.0)printf("%d %d\n",100*a,0);
    //printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
     else printf("%d %d\n",100*(a*ans[0]+b*ans[1])+c*ans[2]+d*ans[3],c*ans[2]+d*ans[3]);
    return 0;
}
/*
1 2 1 2 100 3000
*/
