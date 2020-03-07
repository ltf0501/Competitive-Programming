#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,int> d[2][100000];
    int N[2];
    int X,Y;
    int ans[2];
    int i,j,mx,ed;
    bool flag;
    while(cin>>N[0]>>N[1])
    {
        ans[0]=ans[1]=INT_MAX;
        for(i=0;i<2;i++)
            for(j=0;j<N[i];j++)
                cin>>d[i][j].first>>d[i][j].second;
        cin>>X>>Y;
        flag = false;
        if(X==Y)
        {
            for(i=0;i<2;i++)
                for(j=0;j<N[i];j++)
                    if(d[i][j].first<=X && X<=d[i][j].second)
                    {
                        ans[i]=1;
                        break;
                    }
        }
        else
        {
            sort(d[0],d[0]+N[0]);
            sort(d[1],d[1]+N[1]);
            for(i=0;i<2;++i)
            {
                ed=mx=X;
                j=0;
                while(j!=N[i] && ed<Y)
                {
                    ans[i]++;
                    ed=mx;
                    flag=0;
                    while(j!=N[i] && d[i][j].first<=ed)
                    {
                        if(d[i][j].second>mx)
                        {
                            flag=1;
                            mx=d[i][j].second;
                        }
                        j++;
                    }
                    if(!flag) break;
                }
                if(mx<Y)ans[i]=INT_MAX;
            }
        }
        if(ans[0]==ans[1] && ans[0]==INT_MAX)cout<<"TIE\n";
        else if(ans[0]<=ans[1])cout<<"A WIN\n";
        else cout<<"B WIN\n";
    }
}
