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
int calPoints(vector<string>& operations) {
    vector<int> record;// 增删改查
    //record.push_back(3);
    //record.pop_back();
    //sort(record.begin(), record.end());
    for(int i = 0; i < operations.size(); i++){
        
        if(operations[i] == "C")record.pop_back();
        else if(operations[i] == "D")record.push_back(2 * record.back());
        else if(operations[i] == "+"){
            int n = record.size();
            record.push_back(record[n-1] + record[n-2]);
        }else{
            record.push_back(stoi(operations[i]));
        }
    }
    int ans = 0;
    // for(int i = 0; i < record.size(); i++){
    //     record[i]
    // }
    for(auto r : record){
        ans += r;
    }
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
