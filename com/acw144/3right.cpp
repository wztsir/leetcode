#include <bits/stdc++.h>

using namespace std;
const int N = 100010, M = 2 * N;
int n, m, k, s;
int dist[N][101];
int h[N], e[M], ne[M], idx;
int q[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs(vector<int> &begin, int c) {
    int hh = 0, tt = -1;
    for(int i = 1;i <= n; ++ i) dist[i][c] = 1e9;
    for(auto it: begin) {
        q[ ++ tt] = it;
        dist[it][c] = 0;
    }
    while(hh <= tt) {
        auto u = q[hh ++ ];
        for(int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if(dist[j][c] > dist[u][c] + 1) {
                dist[j][c] = dist[u][c] + 1;
                q[ ++ tt] = j;
            }
        }
    }
}

void work(int u) {
    static int tmp[101];
    int cnt = 0;
    for(int i = 1;i <= k; ++ i) tmp[i] = dist[u][i];
    sort(tmp + 1, tmp + k + 1);
    int res = 0;
    for(int i = 1;i <= s; ++ i) res += tmp[i];
    printf("%d ", res);
}

int main() {
    cin >> n >> m >> k >> s;    
    memset(h, -1, sizeof h);
    vector<int> a(n + 1);
    vector<vector<int>> color(k + 1);
    for(int i = 1;i <= n; ++ i) {
        scanf("%d", &a[i]);
        color[a[i]].push_back(i);
    }

    while(m -- ) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    for(int i = 1;i <= k; ++ i) {
        bfs(color[i], i);
    }
    for(int i = 1;i <= n; ++ i) work(i);
    return 0;
}
