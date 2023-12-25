#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>> process(vector<vector<char>>& arr, char a, char b){
    vector<vector<char>> res(arr.size(), vector<char>(2));
    int index = 0;
    for(int i = 0; i < arr[0].size(); i++){
        if(arr[0][i] == a || arr[0][i] == b){
            res[0][index] = arr[0][i];
            for(int j = 1; j < arr.size(); j++){
                res[j][index] = arr[j][i];
            }
            index++;
        }
    }
    return res;
}
int main() {
    vector<vector<char>>  arr = {{'A', 'B', 'C'}, {'1', '4', '7'}, {'2','5','6'}, {'4', '3', '5'}};
    char a = 'A', b = 'C';
    vector<vector<char>> ouput =  process(arr, a, b);
    
    std::cout << "Hello World!" << std::endl;
    return 0;
}