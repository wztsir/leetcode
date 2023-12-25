#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

//全遍历节点
//每个点的邻边两两配对
//后标记为被访问

//困难在于优化，使其不超时
// 早期停止：在寻找最小三元组的过程中，
// 如果你发现某个节点的度已经大于当前最小值，可以立即停止对该节点的检查，因为它不可能是最小三元组的一部分。

// 使用更快的查找方式：在你的代码中，
// 使用了 std::find 来查找元素。对于大型数据集，这可能会变得很慢。你可以考虑使用更快的查找数据结构，如哈希表，来查找元素。
int minTrioDegree(int n, vector<vector<int>>& edges) {
    vector<unordered_set<int>> map(n+1); 
    unordered_set<int> vis;//为了避免变量命名冲突，将内层循环中的变量名 v 修改为 v1。
    for(auto& it : edges){//使用 auto& it 来遍历 edges 中的元素，以避免不必要的拷贝。
        int a = it[0], b = it[1];
        map[a].insert(b);
        map[b].insert(a);
    }
    int d = INT_MAX;
    for(int i = 1; i <= n; ++i){
        int flag = 0;
        int temp = 0;
        if(map[i].size()-2 >= d){//早期停止，没用
            vis.insert(i);
            continue;
        }
        for (auto a = map[i].begin(); a != map[i].end(); ++a) {
            if(vis.count(*a))continue;
            for(auto b = next(a); b != map[i].end(); ++b){
                if(vis.count(*b))continue;

                if(map[*a].find(*b) != map[*a].end()){
                    temp = map[i].size() + map[*a].size() + map[*b].size() - 6;
                    d = min(d, temp);
                }
            }
        }
        vis.insert(i);
    }
    return d == INT_MAX ? -1 : d;
}

//做的太复杂了，直接暴力即可
    int minTrioDegree2(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>(n));
        vector<int> degree(n);

        for (auto&& edge: edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            g[x][y] = g[y][x] = 1;
            ++degree[x];
            ++degree[y];
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (g[i][j] == 1) {
                    for (int k = j + 1; k < n; ++k) {
                        if (g[i][k] == 1 && g[j][k] == 1) {
                            ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                        }
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }

