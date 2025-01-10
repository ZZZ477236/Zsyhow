/*
题目描述:幼儿园老师安排小朋友做游戏，现在需要安排给N个小朋友分组，老师让每个同学写一个
名字，代表这个小朋友想和谁分到一组。请问老师在满足所有小朋友意愿的情况下，最多可以将班级
分为几组?
输入描述:
第一行输入N，0<N<= 10000
2接下来是N行代表小朋友希望和谁分到一组，如"john jack"，代表john希望和jack分为一组，两个名
输出描述:
1分组的最多数量*/
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
class unionfind
{
public:
    void makeset(const string& x)
    {
        if (parent.find(x) == parent.end())
        {
            parent[x] = x;
            rank[x] = 0;
        }
    }

    string find(const string& x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionset(string x, string y)
    {
        string rootx = find(x);
        string rooty = find(y);
        if (rootx != rooty)
        {
            if (rank[rootx] > rank[rooty])
                parent[rooty] = rootx;

            else if (rank[rootx] < rank[rooty])
            {
                parent[rootx] = rooty;
            }
            else
            {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }

    unordered_map<string, string> getparentmap() const 
    {
        return parent;
    }

private:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;
};

int main()
{
    int N;
    cin >> N;
    unionfind f;
    string a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        f.makeset(a);
        f.makeset(b);
        f.unionset(a, b);
    }
    unordered_map<string, int> groupcount;
    for (const auto& pair : f.getparentmap())
    {
        groupcount[f.find(pair.first)]++;
    }
    cout << groupcount.size() << endl;



    return 0;
}