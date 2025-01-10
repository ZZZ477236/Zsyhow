#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> piles;
    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(piles.begin(), piles.end(), a[i], greater<int>());
        
        if (it == piles.end()) {
            piles.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    cout << piles.size() << endl;
    return 0;
}
