/*输入第一行给出3个正整数n、m和k，其中n（≤10000）是总的山头数（于是假设每个山头从1到n编号）。接下来的
m行，每行给出2个不超过n的正整数，数字间用空格分开，分别代表可以听到彼此的两个山头的编号。这里保证每一对
山头只被输入一次，不会有重复的关系输入。最后一行给出k（≤10）个不超过n的正整数，数字间用空格分开，代表
需要查询的山头的编号。
输出格式：
依次对于输入中的每个被查询的山头，在一行中输出其发出的呼喊能够连锁传达到的最远的那个山头。注意：被输出的
首先必须是被查询的个山头能连锁传到的。若这样的山头不只一个，则输出编号最小的那个。若此山头的呼喊无法传到
任何其他山头，则输出0。*/
//利用vector数组独立处理每组数据 visit避免死循环
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
		q.push(cao);
		memset(d,0,sizeof(d));
		memset(visit,0,sizeof(visit));
		bfs();
	}
}


/*#include<iostream>
using namespace std;
int a[10001][2]={0};
int zu[2]={0};
int xun=1;
int main()
{
	int bu(int m,int lu);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a1,a2;
		cin>>a1>>a2;
		if(a[a1][0]==0)
		{
			a[a1][0]=a2;
		}
		else a[a1][1]=a2;
		if(a[a2][0]==0)
		{
			a[a2][0]=a1;
		}
		else a[a2][1]=a1;
	}
	for(int i=0;i<k;i++)
	{
		int m;
		cin>>m;
		xun=1;
		zu[0]=0,zu[1]=0;
		int k=bu(m,1),l=bu(m,2);
		if(xun!=0)
		{
			
			
			
			if(k>l)
			{cout<< zu[0]<<"\n";
			}
			else if(k<l)
			{cout<< zu[1]<<"\n";
			}
			else
			{
				cout<< min(zu[0],zu[1])<<"\n"; 
			}
		}
		else
		{zu[0]=0,zu[1]=0;
			int q=m;
			int t=m;  
			for(int j=0;j<=k/2;j++)
            {
            	if(a[t][0]==q)
                {
                	q=t;
                	t=a[t][1];
				}
				else 
				{
					q=t;
                	t=a[t][0];
				}
            }
            if(q==m)q=100000;
         if(t==m)t=100000;
         if(k%2==1)cout<<t<<"\n";
         else
            cout<<min(q,t)<<"\n";
		}
		
	}
}
int bu(int m,int lu)
{
	int L=0;
	
		int t=m;
		int p=-1;
		int q=0;
		for(;;)
		{  
			if(q==0&&lu==1)
			{
				if(a[t][0]!=0)
				{   
                    p=t;
                    
					t=a[t][0];
                   
					q++;
					L++;
					continue;
				}
				else 
				{
					return 0;
                }
			}  
			else if(q==0&&lu==2)
			{
				if(a[t][1]!=0)
				{   
                    p=t;
                    
					t=a[t][1];
                   
					q++;
					L++;
					continue;
				}
				else 
				{
					return 0;
                }
			}  
			if(a[t][0]==p)
			{
				if(a[t][1]==0)
				{
				if(zu[0]!=0)zu[1]=t;
				else zu[0]=t;
				return L;
				}
				if(a[t][1]==m)
			   {
				xun=0;
				return L;
			   }
			    else
			    {p=t;
			    t=a[t][1];
			    L++;
				}
			}
			else if(a[t][0]==m)
			{
				xun=0;return L;
			}
			else 
			{    p=t;
				t=a[t][0];
				L++;
			}
		}
}*/