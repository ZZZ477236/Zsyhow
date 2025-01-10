#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	unordered_map<int ,int > a;
	for(int i=0;i<n;i++)
	{
		int b;cin>>b;
		a[b]++;
	}
	for(auto i: a)
	{
		if(i.second>n/2)
		{
			cout<<i.first;return 0;		}
		
	}
	cout<<"0";
}