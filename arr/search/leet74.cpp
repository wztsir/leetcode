#include<vector>
using namespace std;
//第一步： 找到第一个小于target的值
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int left = 0, right = matrix.size(), mid = 0;
    while(left < right){
        mid = left + (right - left)/2;
        if(matrix[mid][0] == target){
            return true;
        }else if(matrix[mid][0] < target){
            left = mid + 1;
        }else{
            right = mid;
        }
    }//即left-1是刚小于t的值
    mid = left - 1;
    if(mid < 0)return false;
    left = 0, right = matrix[0].size();
    while(left < right){
        int mid_row = left + (right - left)/2;
        if(matrix[mid][mid_row] == target){
            return true;
        }else if(matrix[mid][mid_row] < target){
            left = mid_row + 1;
        }else{
            right = mid_row;
        }
    }
    return false;
}