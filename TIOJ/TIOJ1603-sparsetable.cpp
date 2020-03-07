#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll spM[17][100001];
ll spm[17][100001];
int main()
{
    #ifdef DBG
    //freopen("case.in", "r" , stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,Q,gap,jmp;
    cin>>N>>Q;
    for(int i=1;i<=N;++i)
    {
        cin>>spM[0][i];
        spm[0][i]=spM[0][i];
    }
    for(int i=1;(1<<i)<=N;i++)
    {
        jmp=1<<(i-1);
        for(int j=1;j+jmp<=N;j++)
        {
            spM[i][j]=max(spM[i-1][j],spM[i-1][j+jmp]);
            spm[i][j]=min(spm[i-1][j],spm[i-1][j+jmp]);
        }
    }
    while(Q--)
    {
        int L,R;
        cin>>L>>R;
        gap=31-__builtin_clz(abs(L-R)+1);
        cout<< max(spM[gap][L],spM[gap][R-(1<<gap)+1])
              -min(spm[gap][L],spm[gap][R-(1<<gap)+1])<<'\n';
    }
}
