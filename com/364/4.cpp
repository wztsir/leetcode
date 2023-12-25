#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 

using namespace std;
#include <iostream>
#include <vector>

using namespace std;

// 判断一个数是否为质数
vector<bool> prime;
vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    return isPrime;
}
// DFS函数，用于遍历树的路径
long long dfs(int node, int parent, int primes, const vector<vector<int>>& tree, vector<int>& v) {
    long long count = 0;
    if (prime[node]) {
        primes += 1;
    }
    if(primes == 1 && v[node] == 0)count=1;
    if(primes == 2)return 0;

    for (int neighbor : tree[node]) {
        if (neighbor != parent ) {
            count += dfs(neighbor, node, primes, tree, v);
        }
    }
    
    return count;
}

long long countPaths(int n, vector<vector<int>>& edges) {
    vector<vector<int>> tree(n+1);
    vector<int> v(n+1,0);
    prime = sieveOfEratosthenes(n);
    // 构建树的邻接表
    for (const vector<int>& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    long long result = 0;

    // 从每个节点开始DFS
    for (int i = 1; i <= n; ++i) {
        result += dfs(i, -1, 0, tree, v);
        v[i] = 1;
        if(prime[i])result--;
    }

    return result;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{1,2},{1,3},{2,4},{2,5}};
    long long ans = countPaths(n, edges);
    // cout << ans << endl; // 输出：5

    return 0;
}


