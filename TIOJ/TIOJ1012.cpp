#include<cstdio>
#include<stack>
using namespace std;

int N,M;
int A[2000];
bool in[2000];
stack<int> s1,s2;
int main()
{
    scanf("%d%d",&N,&M);

    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    int _Ni=0;

    for(int i=1;i<=N;i++)
    {
        while(!in[i])
        {
            s1.push(A[_Ni]);
            in[A[_Ni]]=true;
            _Ni++;
        }
        while(s1.top()!=i && s2.size()<M)
        {
            s2.push(s1.top());
            s1.pop();
        }
        if(s1.top()!=i)
        {
            puts("no");
            return 0;
        }
        s1.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    puts("yes");
    return 0;
}
