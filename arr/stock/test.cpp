#include <iostream>  
#include <set>  
  
int main() {  
    std::multiset<int> s;  
  
    // 插入元素  
    s.insert(30);  
    s.insert(10);
    s.insert(10);  
    s.insert(20);  
    s.insert(40);  
    s.insert(20); // 插入重复元素，但会被忽略  
  
    // // 查找元素  
    // if (s.find(20) != s.end()) {  
    //     std::cout << "Found 20" << std::endl;  
    // } else {  
    //     std::cout << "Did not find 20" << std::endl;  
    // }  
  
    // 打印所有元素  
    s.erase(10);
    for (const auto& elem : s) {  
        std::cout << elem << ' ';  
    }  
    std::cout << '\n';  
  
    return 0;  
}