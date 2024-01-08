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



int numberOfBoomerangs(vector<vector<int>>& points) {
    int size = points.size();
    vector<unordered_map<int, int>> m(size);
    int ans = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size ; j++){
            if(j == i)continue;
            int dist = (points[j][0] - points[i][0]) * (points[j][0] - points[i][0]) + (points[j][1] - points[i][1]) * (points[j][1] - points[i][1]);
            m[i][dist]++;
        }
    }
    for(int i = 0; i < size; i++){
        for(auto& it : m[i]){
            if(it.second >= 2){
                ans += it.second * (it.second-1);

            }
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> m = {{0,0}, {0,1}, {0,2}};
    numberOfBoomerangs(m);
}