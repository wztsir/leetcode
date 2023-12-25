#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<numeric> // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
using namespace std;
bool cmp(vector<int>& a, vector<int>& b) {
    if (a[1] == b[1])return a[0] < b[0];
    return a[1] < b[1];
}
bool cmp1(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0])return a[1] < b[1];
    return a[0] < b[0];
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> students(n, vector<int>(2, 0));
    vector<vector<int>> ans;
    map<int, int> s;
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> students[i][0] >> students[i][1];
        if (s.count(students[i][1])) {
            k = 1;
        }
        s[students[i][1]]++;

    }
    sort(students.begin(), students.end(), cmp);
    int m = 3000;
    if (k == 1) {
        for (int i = 0; i + 1 < n; i++) {
            if (students[i][1] == students[i + 1][1]) {
                int size = i + s[students[i][1]];
                for (int u = i; u < size; u++) {
                    for (int v = i + 1; v < size; v++) {
                        ans.push_back({ students[u][0], students[v][0] });
                    }
                }
                i = size - 1;
            }
        }
    }
    else {
        for (int i = 0; i + 1 < n; i++) {
            int temp = students[i + 1][1] - students[i][1];
            int p1 = min(students[i][0], students[i + 1][0]);
            int p2 = students[i][0] + students[i + 1][0] - p1;
            if (temp < m) {
                ans.clear();
                m = temp;
                ans.push_back({ p1, p2 });
            }
            else if (temp == m) {
                ans.push_back({ p1, p2 });
            }
        }
    }

    sort(ans.begin(), ans.end(), cmp1);
    for (auto& p : ans) {
        cout << p[0] << " " << p[1] << endl;
    }
    return 0;
}