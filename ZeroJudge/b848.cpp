#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MOD 1000007
struct Matrix
{
    int a1,a2,b1,b2;
};
Matrix F[31];
Matrix fac(Matrix m,int n)//¨Dm^(2^n)
{
    if(n==0)return F[0]=m;
    if(F[n].a1!=-1)return F[n];
    Matrix s=m;
    /*
    for(int i=1;i<=n;i++)
    {
        Matrix r=s;
        s.a1=(r.a1*r.a1+r.a2*r.b1)%MOD;
        s.a2=(r.a1*r.a2+r.a2*r.b2)%MOD;
        s.b1=(r.b1*r.a1+r.b2*r.b1)%MOD;
        s.b2=(r.b1*r.a2+r.b2*r.b2)%MOD;
    }
    */
    s.a1=(fac(m,n-1).a1*fac(m,n-1).a1+fac(m,n-1).a2*fac(m,n-1).b1)%MOD;
    s.a2=(fac(m,n-1).a1*fac(m,n-1).a2+fac(m,n-1).a2*fac(m,n-1).b2)%MOD;
    s.b1=(fac(m,n-1).b1*fac(m,n-1).a1+fac(m,n-1).b2*fac(m,n-1).b1)%MOD;
    s.b2=(fac(m,n-1).b1*fac(m,n-1).a2+fac(m,n-1).b2*fac(m,n-1).b2)%MOD;
    return F[n]=s;
}
Matrix fac2(Matrix m,int n)//¨Dm^n;
{
    Matrix s=(Matrix){1,0,0,1};
    //if(n%2)s=m;
    //if(n==1)return m;
    for(int i=0;i<=31;i++)
    {
        if(n&(1<<i))
        {
            Matrix t=s;
            s.a1=(t.a1*F[i].a1+t.a2*F[i].b1)%MOD;
            s.a2=(t.a1*F[i].a2+t.a2*F[i].b2)%MOD;
            s.b1=(t.b1*F[i].a1+t.b2*F[i].b1)%MOD;
            s.b2=(t.b1*F[i].a2+t.b2*F[i].b2)%MOD;
        }
    }
    return s;
}
main()
{
    int t;scanf("%d",&t);
    Matrix a=(Matrix){0,1,1,2},s;
    for(int i=1;i<=31;i++)F[i].a1=-1;
    Matrix T=fac(a,31);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);//¨Dak+1,ak

       // Matrix b=(Matrix){1,1,2,1};
        //Matrix c=fac(b,1);
        //printf("%d %d %d %d",c.a1,c.a2,c.b1,c.b2);
        int x,y;
        if(n>=m)
        {
            x=2*n+m;
            y=n;
        }
        else
        {
            x=3*m;
            y=n;
        }

        if(k==1){printf("%d %d\n",x,y);continue;}
        s=fac2(a,k-1);

        //printf("%d %d %d %d\n",s.a1,s.a2,s.b1,s.b2);

        int p=s.a1*y+s.a2*x,q=s.b1*y+s.b2*x;
        printf("%d %d\n",q,p);

    }
    return 0;
}
