#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> node(n+1);
    vector<int> visit(n+1, 0);
    vector<vector<int>> tree(n+1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &node[i]);
    }
    int a, b;
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    long long ans = -1000000;
    function<long long(int)> dfs = [&](int cur){
        visit[cur] = 1;
        long long res = node[cur];
        for(auto& son : tree[cur]){
            if(visit[son] == 0 ){
                long long temp = dfs(son);
                if(temp > 0)res += temp;
            }
        }
        visit[cur] = 0;
        ans = max(ans, res);
        return res;
    };
    dfs(1);
    printf("%lld", ans);// 又犯同样的错误
    return 0;
}