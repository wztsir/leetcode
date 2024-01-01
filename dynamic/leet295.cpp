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

//堆
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> large;
    priority_queue<int, vector<int>, greater<int>> small;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(small.size() > large.size()){
            small.push(num);
            large.push(small.top());
            small.pop();
        }else{
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()){
            return small.top();
        }else if(small.size() > large.size()){
            return large.top();
        }
        return( small.top() + large.top()) * 1.0 / 2;
    }
};
int main()
{
    priority_queue<int, vector<int>, less<int>> large;
    large.push(1);
    large.push(2);
    large.push(3);
    large.push(4);
    large.push(5);
    large.push(6);
   system("pause");
   return 0;
}
