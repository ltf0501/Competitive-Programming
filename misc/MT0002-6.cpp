#include<bits/stdc++.h>
using namespace std;
set<vector<int>>arrays;
void add_partial_sorted_array(vector<int> array,int i,int j){
    sort(array.begin()+i,array.begin()+j);
    arrays.insert(array);
}
int main(){
    int N;
    vector<int>input;
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        input.push_back(x);
    }
    for(int i=0;i<N;i++)for(int j=i+1;j<=N;j++)
    {
        add_partial_sorted_array(input,i,j);
        for(auto s : arrays)
        {
            for(int v : s)printf("%d ",v);
            puts("");
        }
        puts("");
    }
    printf("%d\n",(int)arrays.size());
    return 0;
}
