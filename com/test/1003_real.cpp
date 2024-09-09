// #include<vector>
// #include<set>
// #include<map>
// #include<unordered_set>
// #include<unordered_map>
// #include<queue>
// #include<stack>
// #include<iostream>
// #include<algorithm>
// #include<cmath>
// #include<cstring>
// #include<numeric> // 为了使用std::accumulate()函数 
// #include<sstream>
// #include<functional>
// using namespace std;

// int main(){
//     int n, lower, upper, a;
//     cin >> n >> lower >> upper;
//     vector<int> arr(n+1, 0);
//     for(int i = 1; i <= n; i++){
//         cin >> a;
//         arr[i] = arr[i-1] + a;
//     }
//     int cnt = 0;
//     for(int i = 1; i <= n; i++){
//         for(int j = i-1; j >= 0; j--){
//             int val = arr[i] - arr[j]; 
//             if(val >= lower && val <= upper)cnt++;
//         }
//     }
//     cout << cnt;
//    return 0;
// }

// #include <iostream>
// #include <vector>
// #include <set>
// using namespace std;

// int main() {
//     int n, lower, upper, a;
//     cin >> n >> lower >> upper;
//     vector<int> arr(n + 1, 0);
//     for (int i = 1; i <= n; i++) {
//         cin >> a;
//         arr[i] = arr[i - 1] + a;
//     }
//     int cnt = 0;
//     multiset<int> prefixSums;
//     prefixSums.insert(0); 
//     for (int i = 1; i <= n; i++) {
//         int lowerBound = arr[i] - upper;
//         int upperBound = arr[i] - lower;
//         cnt += distance(prefixSums.lower_bound(lowerBound), prefixSums.upper_bound(upperBound));
//         prefixSums.insert(arr[i]);
//     }

//     cout << cnt << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <map>
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

// Fenwick Tree for range sum queries
class FenwickTree {
private:
    vector<int> tree;
public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void update(int index, int delta) {
        while (index < tree.size()) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index; 
        }
        return sum;
    }
};

int main() {
    int n, lower, upper;
    cin >> n >> lower >> upper;
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + val[i - 1];
    }

    // Coordinate compression
    vector<long long> allSums(prefixSum.begin(), prefixSum.end());
    for (int i = 0; i <= n; i++) {//是为了low_bound的时候好找到范围
        allSums.push_back(prefixSum[i] - lower);
        allSums.push_back(prefixSum[i] - upper);
    }

    sort(allSums.begin(), allSums.end());
    allSums.erase(unique(allSums.begin(), allSums.end()), allSums.end());//优化速度

    FenwickTree fenwick(allSums.size());
    int cnt = 0;

    for (int i = 0; i <= n; i++) {
        int current = lower_bound(allSums.begin(), allSums.end(), prefixSum[i]) - allSums.begin() + 1;
        int left = lower_bound(allSums.begin(), allSums.end(), prefixSum[i] - upper) - allSums.begin() + 1;
        int right = lower_bound(allSums.begin(), allSums.end(), prefixSum[i] - lower) - allSums.begin() + 1;
        
        cnt += fenwick.query(right) - fenwick.query(left - 1);
        fenwick.update(current, 1);
    }

    cout << cnt << endl;
    return 0;
}