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
private: 
    vector<int> p;
    
public:
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
int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    uf u = uf(n/2);
    int cnt = 0;
    for(int i=0; i<n; i+= 2){
        if(u.find(row[i]/2) != u.find(row[i+1]/2)){
            cnt ++;
            u.uni(row[i]/2, row[i+1]/2);
        }
    }
    return cnt;
    
}
int main()
{
    vector<int> r = {0,2,1,3};
    minSwapsCouples(r);
   system("pause");
   return 0;
}
