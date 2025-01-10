#include<bits/stdc++.h>
using namespace std;
const int  inf=0x3f3f3f3f;

int f[10000];
void init(int n) //初始化 每个人都是自己的祖先
{
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
}

int find1(int i)  //链式 查询 可能过长
{
    if(f[i]==i ) return f[i];
    return find1(f[i]);
}

int find2(int i)
{
    if(f[i]==i) return i;
    else
    {
        f[i]=find2(f[i]);
        return f[i];      //或者简化为  return f[i]==i? i:f[i]=find2(f[i]);
    }
}
//递归算法与循环时间消耗都是o（1）后者不会调用栈，深度树避免栈溢出
/*
int find(int x){// 路径压缩
    while(f[x] != x) x = f[x] = f[f[x]];
    return x;
*/

void unionn (int i, int j)
{
    int i_fa=find2(f[i]);
    int j_fa=find2(f[j]);
    if(j_fa==i_fa) return ;
    f[i_fa]=j_fa;
}


int main()
{
    
    return 0;
}