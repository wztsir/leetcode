#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

const int INF = 1e9;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> p(n + 1), a(n + 1), t(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i] >> a[i] >> t[i];
        }
        cout << "0\n";
    }
    return 0;
}