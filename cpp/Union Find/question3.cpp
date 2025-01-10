/*小美认为，在人际交往中，但是随着时间的流逝，朋友的关系也是会慢慢变淡的，
最终朋友关系就淡忘了。现在初始有一些朋友关系，存在事件会导致两个人淡忘
了朋友关系。小美想知道某一时刻中，某两人是否可以通过朋友介绍互相认识？
事件共有 2 种：
1 u v：代表编号 u 的人和编号 v 的人淡忘了他们的朋友关系。
2 u v：代表小美查询编号 u 的人和编号 v 的人是否能通过朋友介绍互相认识。
注：介绍可以有多层，比如 2 号把 1 号介绍给 3 号，然后 3 号再把 1 号介绍给 4 号，这样 1 号和 4 号就认识了。
输入描述: 
第一行输入三个正整数n,m,q，代表总人数，初始的朋友关系数量，发生的事件数
量。接下来的m行，每行输入两个正整数u,v，代表初始编号u的人和编号v的人是

朋友关系。接下来的q行，每行输入三个正整数op,u,v，含义如题目描述所述。

1 <= n <= 10^9，1 <= m,q <= 10^5，1 <= u,v <= n，1 <= op <= 2
保证至少存在一次查询操作。

输出描述: 
对于每次 2 号操作，输出一行字符串代表查询的答案。如果编号 u 的人和编号 v 

的人能通过朋友介绍互相认识，则输出"Yes"。否则输出"No"。*/


//https://blog.csdn.net/weixin_62517188/article/details/136777830 大佬AC代码 看湿了

#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
const int N = 1e5;
using PII = pair<int,int>;

int n, m, q;
map<int,int>f;// 并查集父亲数组
struct node{
    int op, u, v;
}ord[N+5];// 新的操作数组

int find(int x){// 路径压缩
    while(f[x] != x) x = f[x] = f[f[x]];
    return x;
}
void merge(int u,int v){// 并查集合并
    int fa = find(u);
    int fb = find(v);
    f[fb] = fa;
}
int main() 
{
    cin >> n >> m >> q;
    set<PII>st;// 关系集合

    for(int i=0, u, v; i<m; i++){
        cin >> u >> v;
        st.insert({u, v}); // u, v放进关系集合中
        f[u] = u, f[v] = v;// 把出现的结点父节点设置为自己
    }

    int num = 0;// 新的操作数组长度
    for(int i=0; i<q; i++){
        int op, u, v; cin >> op >> u >> v;
        //如果是查询操作，可以直接存入
        // 如果是删除操作，需要判断原关系集合中是否存在
        if(op == 1){
        	// 可能是 {u,v} 形式存储
            if(st.find({u, v}) != st.end()) st.erase({u, v});
            // 可能是 {v,u} 形式存储
            else if(st.find({v, u}) != st.end()) st.erase({v, u});
            // 如果不存在直接跳过，不储存此次删除操作
            else continue; 
        }
        // 存入新的操作数组中
        ord[num++] = {op, u, v};
    }
    // 删除之后，剩余关系集合就是没有涉及到的，也是最终的并查集
    for(auto [u,v]:st) merge(u, v);

    vector<bool>ans;// 存储答案
    for(int i=num-1; i>=0; i--){// 倒着重新进行操作
        int op = ord[i].op, u = ord[i].u, v = ord[i].v;
        if(op == 1) merge(u, v);// 如果是删除操作，反过来进行合并
        else{
            // 当 f[u] = 0时，就是第一次出现该节点，需要初始化f[i]=i,方便进行路径压缩
            if(!f[u]) f[u] = u;
            if(!f[v]) f[v] = v;
            ans.emplace_back(find(u) == find(v));// 查询操作，就储存答案
        }
    }
	//因为是倒着遍历操作的，所以答案是倒着存储的
    for(int i=ans.size()-1; i>=0; i--) 
        if(ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
}
