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
#include<climits>
using namespace std;

int main(){
    int n;
    while(true){
        cin >> n;
        if(n == 0)break;
        int ans = INT_MIN;
        int temp = 0, a;
        for(int i = 0; i < n; i++){
            cin >> a;
            if(temp >= 0)temp += a;
            else temp = a;
            ans = max(temp, ans);
        }
        cout << ans << endl;   
    }
   return 0;
}
