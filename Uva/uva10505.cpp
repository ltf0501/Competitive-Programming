#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
bool has(vi v,int e)
{
	for(int i=0;i<v.size();i++)
		if(v[i]==e)return 1;
	return 0;
}
int main()
{
	int V,E,v,t;
	vector<vi> g;
	scanf("%d",&t);
	while(t--)
    {
		scanf("%d",&V);
		g.assign(V,vi());
		for (int u=0;u<V;u++)
        {
			scanf("%d",&E);
			for(int j=0;j<E;j++)
            {
				scanf("%d",&v);
				v--;
				if(v<V)
                {
					if(!has(g[u],v))g[u].push_back(v);
					if(!has(g[v],u))g[v].push_back(u);
				}
			}
		}
		vi color(V,1e9);
		bool isBipartite;
		int ans=0;
		for(int s=0;s<V;s++)
        {
			if(color[s]!=1e9)continue;
			isBipartite=1;
			int colorCount[2]={0,0};
			queue<int>q;
			q.push(s);
			color[s]=0;
			colorCount[0]++;
			while(!q.empty())
            {
				int u=q.front();
				q.pop();
				for(int j=0;j<g[u].size();j++)
                {
					int v=g[u][j];
					if(color[v]==1e9)
                    {
						color[v]=1-color[u];
						colorCount[color[v]]++;
						q.push(v);
					}
					else if(color[v]==color[u])
						isBipartite=0;
				}
			}
			if(isBipartite)
				ans+=max(colorCount[0],colorCount[1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
