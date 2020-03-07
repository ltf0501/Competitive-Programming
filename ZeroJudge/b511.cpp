#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int A[105],s[105],n;
void check_print(int m,int cur)
{

    if(cur==n+1)
    {

       if(!m)
       {
            cout<<"(";
            for(int i=1;i<=n;i++)
            {
                cout<<s[i];
                if(i!=n)
                    cout<<",";
            }
            cout<<")"<<endl;
       }
       return ;
    }
    for(int i=0;i<=100;i++)
    {
        s[cur]=i;
        if(m-A[cur]*s[cur]<0)break;
        //printf("%d %d\n",cur,i);
        m-=A[cur]*s[cur];
        check_print(m,cur+1);
        m+=A[cur]*s[cur];
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        int m;
        memset(s,n+5,sizeof(0));
        for(int i=1;i<=n;i++)
            cin>>A[i];
        cin>>m;
        check_print(m,1);

    }

}
