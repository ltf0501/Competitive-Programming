#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<int> v(n);
    for(int i=0;i<n;i++)v[i]=i+1;
    int id=0;
    while(k--)
    {
        id=(id+m-1)%v.size();
        v.erase(v.begin()+id);
    }
    id=id%v.size();
    printf("%d\n",v[id]);
    return 0;
}
