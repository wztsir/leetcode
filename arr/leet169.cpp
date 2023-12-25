#include<vector>
using namespace std;
//可以形象的理解为开心消消乐
int majorityElement(vector<int>& nums) {
    int can = nums[0];
    int v = 0;
    for(auto it :nums){
        if(it == can)v++;
        else{
            v--;
            if(v < 0){can = it;v=1;}
        }
    }
    return can;
}
int main(){
    vector<int> n = {10,9,9,9,10};
    majorityElement(n);
}