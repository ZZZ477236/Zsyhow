#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int T,n,m;
string a[110];
int dis[110][110];
queue<pair<int,int>>q;
int ans=inf;


int main()
{
    int mvx[]={0,0,1,-1};
int mvy[]={1,-1,0,0};
    cin>>n>>m;
for(int i=0;i<n;i++)
{
    cin>>a[i];
    for(int j=0;j<m;j++)
    {
        dis[i][j]=inf;
        if(a[i][j]=='r')
        {
            dis[i][j]=0;
            q.push(make_pair(i,j));
        }
    }

}
while(!q.empty())
{
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    for(int i=0;i<4;i++)
    {
        int nx=x+mvx[i];int ny=y+mvy[i];
        if(nx<0||nx>=n||ny<0||ny>=m)
        continue;
        if(dis[nx][ny]>dis[x][y]+1&&a[nx][ny]=='.')
        {
            dis[nx][ny]=dis[x][y]+1;
            q.push(make_pair(nx,ny));
        }
        if(dis[nx][ny]>dis[x][y]+2&&a[nx][ny]=='x')
    {

        dis[nx][ny]=dis[x][y]+2;
        q.push(make_pair(nx,ny));
    }
    if(a[nx][ny]=='a')
    {
        ans=min(ans,dis[x][y]+1);
    }
    }
}
cout<<ans<<endl;
return 0;
}
