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
#include<queue>
#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  priority_queue<string, vector<string>, greater<string>> heap;
  while(n--){
    string temp;
    cin >> temp;
    heap.push(temp);
  }
  while(!heap.empty()){
    cout << heap.top() << endl;
    heap.pop();
  }
  return 0;
}

