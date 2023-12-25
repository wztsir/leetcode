#include<vector>
#include<unordered_map>
using namespace std;
//n^2的暴力算法


int maxPoints(vector<vector<int>>& points) {
    int res = 0;
    for(int i = 0; i < points.size()-1; ++i){//选一个一条直线必过的节点，然后和其他的所有的节点画直线
        unordered_map<double, int> ma;
        for(int j = i + 1; j < points.size(); ++j){
            double k;
            if(points[i][0] - points[j][0] == 0) k = 99999999;
            else k = (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
            ma[k]++;
            res = max(res, ma[k]);
        }
    }
    return res + 1;
}