#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    // 使用 vector 代替大数组
    vector<int> array(n);
    
    // 输入数组元素
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    // 查询 m 次并输出结果
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        cout << array[t-1] << " ";  // 输出元素，空格分隔
    }
    cout << endl;  // 最后输出一个换行
}

int main() {
    solve();
    return 0;
}