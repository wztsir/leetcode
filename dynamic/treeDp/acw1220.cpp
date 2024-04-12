#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> node(n+1);
    vector<int, vector<int>> tree(n+1);
    for(int i = 1; i <= n; i++){
        scanf("%d", node[i]);
    }
    int a, b;
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for()
}