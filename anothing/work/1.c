#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX_SIZE 100//输入数据的默认最多个数
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}
void calculate_hours(int num_hours, float charging_rate, float demand, float* pollution_hour, bool* charging_state_hour){
    int num_charge = ceil(demand/charging_rate); //需要的充电小时数
    //选择 pollution_hour中最小的前num_charge数 

    int index[num_hours]; // 用于记录每次冒泡操作中交换的下标

    // 初始化原始下标数组
    for (int i = 0; i < size; ++i) {
        index[i] = i;
    }

    // 冒泡排序
     for (int i = 0; i < num_hours - 1; ++i) {
        for (int j = 0; j < num_hours - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&pollution_hour[j], &pollution_hour[j + 1]);
                swap(&index[j], &index[j + 1]);
            }
        }
    }
    for(int i = 0; i < num_hours; ++i){
        charging_state_hour[i] = 0;
    }
    
    for (int i = 0; i < num_charge; ++i) {
        charging_state_hour[index[i]] = 1;
    }

}


int main() {
    FILE *file = fopen("input.txt", "r");  

    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    float data[MAX_SIZE];
    int size = 0;

    // 从文件中读取数据到数组
    while (fscanf(file, "%f", &data[size]) == 1) {
        size++;
        if (size >= MAX_SIZE) {
            printf("Array size exceeded maximum limit\n");
            break;
        }
    }

    fclose(file);
    int num_hours = data[0];
    float charging_rate = data[size-2];
    float demand = data[size-1];

    float pollution_hour[num_hours];
    bool charging_state_hour[num_hours];
    for(int i = 0; i < num_hours; i++){
        pollution_hour[i] = data[i+1];
    }
    calculate_hours(num_hours, charging_rate, demand, pollution_hour, charging_state_hour)

    return 0;
}
