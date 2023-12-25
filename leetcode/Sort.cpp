#include<vector>
#include<iostream>
using namespace std;


//void insertionSort(vector<int>& arr) {
//    int n = arr.size();
//    for (int i = 1; i < n; i++) {
//        int key = arr[i];
//        int j = i - 1;
//        while (j >= 0 && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            j--;
//        }
//        arr[j + 1] = key;
//    }
//}
//void insertionSort(vector<int>& arr) {
//    int n = arr.size();
//    for (int i = 1; i < arr.size(); i++) {
//        int key = arr[i];
//        int j = i;
//        for(j; j-1 >= 0 && arr[j - 1] > key; j--) {
//            arr[j ] = arr[j - 1];
//        }
//        arr[j] = key;
//    }
//}
//void shellSort(vector<int>& arr) {
//    int n = arr.size();
//    for (int gap = n / 2; gap > 0; gap /= 2) {
//        for (int i = gap; i < n; i++) {
//            int temp = arr[i];
//            int j;
//            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
//                arr[j] = arr[j - gap];
//            }
//            arr[j] = temp;
//        }
//    }
//}

//gap,其他同插入排序
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int key = arr[i];
            int j ;
            for (j = i; j-gap >= 0 && arr[j - gap] > key; j -= gap) {//arr[j - gap] > key极其容易写错，这里是同key比较，给key找一个位置，for循环直接看终止条件，查j的位置
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
        }
    }

}

//归并排序，先拆分，排序，再合并
//void mergeSort(vector<int>& arr, int left, int right) {
//    if (left < right) {
//        int mid = left + (right - left) / 2;
//        mergeSort(arr, left, mid);
//        mergeSort(arr, mid + 1, right);
//        merge(arr, left, mid, right);
//    }
//}
//void merge(vector<int>& arr, int left, int mid, int right) {
//    int n1 = mid - left + 1;
//    int n2 = right - mid;
//
//    std::vector<int> L(n1), R(n2);
//
//    for (int i = 0; i < n1; i++) {
//        L[i] = arr[left + i];
//    }
//    for (int j = 0; j < n2; j++) {
//        R[j] = arr[mid + 1 + j];
//    }
//
//    int i = 0, j = 0, k = left;
//    while (i < n1 && j < n2) {
//        if (L[i] <= R[j]) {
//            arr[k] = L[i];
//            i++;
//        }
//        else {
//            arr[k] = R[j];
//            j++;
//        }
//        k++;
//    }
//
//    while (i < n1) {
//        arr[k] = L[i];
//        i++;
//        k++;
//    }
//
//    while (j < n2) {
//        arr[k] = R[j];
//        j++;
//        k++;
//    }
//}






//int main() {
//    vector<int> arr = { 3, 2,1,8,4,5,3 };
//    shellSort(arr);
//    
//    cout << "wztnb!!";
//}