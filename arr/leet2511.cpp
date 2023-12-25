#include<vector>
#include<unordered_set>
#include<algorithm>
#include<climits>
using namespace std;
//题目很复杂，直接看示例，1，-1的区间即可，-1
int captureForts(vector<int>& forts) {
    int r = -1, l = -1;
    int m = INT_MIN;
    for(int i = 0; i < forts.size(); ++i){
        if(forts[i] == -1){
            if(r != -1 && l > r)r = -1;
            l = i;
            if(r == -1)continue;
            m = max(m, l - r -1);
        }
        if(forts[i] == 1){
            if(l != -1 && r > l)l = -1;
            r = i;
            if(l == -1)continue;
            m = max(m, r - l -1);
        }
    }
    return m == INT_MIN ? 0 : m;
}
//更简洁
    int captureForts2(vector<int>& forts) {
        int ans = 0, pre = -1;
        for (int i = 0; i < forts.size(); i++) {
            if (forts[i] == 1 || forts[i] == -1) {
                if (pre >= 0 && forts[i] != forts[pre]) {
                    ans = max(ans, i - pre - 1);
                }
                pre = i;
            }
        }
        return ans;
    }

