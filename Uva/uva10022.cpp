#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int abs(int n)
{
    if(n<0)return -n;
    return n;
}
int main()
{
    int t;
    cin>>t;
    for(int g=0;g<t;g++)
    {
        if(g)printf("\n");
        int n,m,k,l,p,q,f=0;
        cin>>n>>m;
        if(n>m)swap(n,m);
        k=sqrt(n-1);
        l=sqrt(m-1);
        p=n-k*k;
        q=m-l*l;
        if(q%2)f++;if(p%2)f--;
        k++;l++;
        p=p-k;
        q=q-l;
        printf("%d\n",max(l-k+abs(p-q),(l-k)*2+f));
    }
return 0;
}
