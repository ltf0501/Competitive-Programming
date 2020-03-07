#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > list;

struct Entry{

    int target,degree;

    Entry(int target,int degree) : target(target), degree(degree) {}

    bool operator<(const Entry rhs)const
    {
        return rhs.degree<degree;
    }

};

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        list.clear();
        int n,e;
        scanf("%d %d",&n,&e);
        int* degree=new int[n];
        int* original=new int[n];
        for(int i=0;i<n;i++)degree[i]=original[i]=0;
        for(int i=0;i<n;i++)list.push_back(vector<int>());
        for(int i=0;i<e;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            list[a].push_back(b);
            list[b].push_back(a);
            if(a>b)original[b]++;
            else original[a]++;
            degree[a]++;
            degree[b]++;
        }
        int before=0,result=0;
        priority_queue<Entry> pq;
        for(int i=0;i<n;i++)
        {
            if(original[i]>before)before=original[i];
            pq.push(Entry(i,degree[i]));
        }
        while(!pq.empty())
        {
            const Entry& temp=pq.top();
            int now=temp.target;
            pq.pop();
            if(degree[now]==-1)continue;
            if(result<degree[now])result=degree[now];
            degree[now]=-1;
            for(int i=0;i<list[now].size();i++)
            {
                int v=list[now][i];
                if(degree[v]==-1)continue;
                degree[v]--;
                pq.push(Entry(v,degree[v]));
            }
        }
        delete[] degree;
        delete[] original;
        printf("%d %d\n",before,result);
    }
    return 0;
}
