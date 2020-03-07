#include<bits/stdc++.h>
using namespace std;
int k,s;
string n;
int main()
{
	int i;
	cin>>n>>k;
	for(i=n.size()-1;i>=0 && k;i--)
		n[i]=='0' ? k--:s++;
	cout<<(i<0 ? n.size()-1:s);
	return 0;
}
