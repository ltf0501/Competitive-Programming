#include<bits/stdc++.h>
using namespace std;
#define pii pair<double,double>
#define F first
#define S second
pii operator + (const pii a,const pii b)
{
    return pii(a.F+b.F,a.S+b.S);
}
double R,x1,y1,x2,y2;
double dist(pii a,pii b)
{
    return sqrt((a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S));
}
pii gao()
{
    if(x1==x2 && y1==y2)return pii(x1+R,y1);
    pii tmp=pii(x1-x2,y1-y2);
    double d=R/dist(pii(0,0),tmp);
    tmp.F*=d,tmp.S*=d;
    return pii(x1,y1)+tmp;
}
main()
{
    cin>>R>>x1>>y1>>x2>>y2;
    //scanf("%f %f %f %f %f",&R,&x1,&y1,&x2,&y2);
    //printf("%f %f %f %f %f\n",R,x1,y1,x2,y2);
    if(dist(pii(x1,y1),pii(x2,y2))>R)return 0*printf("%f %f %f\n",x1,y1,R);
    pii t=gao();
    //cout<<t.F<<' '<<t.S<<'\n';
    pii cen=pii((t.F+x2)/2,(t.S+y2)/2);
    double r=dist(cen,t);
    printf("%.10f %.10f %.10f\n",cen.F,cen.S,r);
    return 0;
}
