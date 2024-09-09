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
class uf{    
public:
    vector<int> p;
    uf(int n){
        p.resize(n);
        for(int i = 0; i <n; i++){
            p[i] = i;
        }
    }
    int find(int x){
        if(p[x] != x){
            p[x] = find(p[x]);
        }
        return p[x];
    }
    void uni(int a, int b){
        p[find(a)] = p[find(b)];
    }

};
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mp(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mp[i][j];
        }
    }
    uf u = uf(n*m);
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1},{-1, -1}, {1, -1}, {-1, 1}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == '#'){
                for(int k = 0; k < 8; k++){
                    int a = i + dir[k][0], b = j + dir[k][1];
                    if(a >= 0 && a < n && b >= 0 && b < m && mp[a][b] == '#'){
                        int node_a = i*m + j, node_b = a*m + b;
                        if(u.find(node_a) != u.find(node_b)){
                            u.uni(node_a, node_b);
                        }
                    }
                }
            }
        }
    }
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == '#'){
                s.insert(u.find(i*m + j));
            }
            
        }
    }
    cout << s.size();
    return 0;
}
