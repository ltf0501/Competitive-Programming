#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<map>

#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define INF 0x7fffffff

using namespace std;

struct one_node
{
    vector<int> link;
    bool vis;
};

vector<one_node> node;
map<string,int> name;

int get_hash(string s)
{
    if(!name.count(s))
    {
        name[s]=node.size();
        one_node n;
        n.vis=false;
        node.push_back(n);
    }
    return name[s];
}

int BFS(int src,int des)
{
    queue<int> que;
    int u,v,d,n;

    if(src==des)return 0;

    que.push(src);
    n=d=1;
    while(!que.empty())
    {
        u=que.front();
        que.pop();
        node[u].vis=true;
        foreach(node[u].link,it)
        {
            v=*it;
            if(v==des)return d;
            if(!node[v].vis)
                que.push(v);
        }
        if(--n==0)
        {
            n=que.size();
            d++;
        }
    }
    return -1;
}

int main(void)
{
    int N,u,v;
    string s;

    while(cin>>N)
    {
        node.clear();
        name.clear();
        getline(cin,s);    // trim first line's '\n'
        for(int i=0;i<N;i++)
        {
            getline(cin,s);
            stringstream ss(s);
            ss>>s;
            u=get_hash(s);
            while(ss>>s)
            {
                v=get_hash(s);
                node[u].link.push_back(v);
                node[v].link.push_back(u);
            }
        }

        cin>>s;u=get_hash(s);
        cin>>s;v=get_hash(s);
        cout<<BFS(u,v)<<endl;
    }

    return 0;
}
