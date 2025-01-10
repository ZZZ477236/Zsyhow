#include<bits/stdc++.h>
using namespace std;
int visit[10004],d[10004];	int n,m,k;
queue <int>q;vector<int> v[10004];
void bfs()
{
	
	while(!q.empty()) 
	{
		int t=q.front();
		visit[t]=1;q.pop();
		for(int i=0;i<v[t].size();i++)
		{
			if(!visit[v[t][i]]&&!d[v[t][i]])
			
			{
				q.push(v[t][i]);
				d[v[t][i]]=d[t]+1;
			}
		}
	}
	int maxx=-1;
	for(int i=0;i<=n;i++)
	{
		if(d[i]>maxx) maxx=d[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(d[i]==maxx)
		{
			cout<<i<<endl;break;
		}
	}
}

int main()
{

	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);v[b].push_back(a);
	}
	for(int i=0;i<k;i++)
	{int cao;
		cin>>cao;
		q.clear();
		q.push(cao);
		memset(d,0,sizeof(d));
		memset(visit,0,sizeof(visit));
		bfs();
	}
}