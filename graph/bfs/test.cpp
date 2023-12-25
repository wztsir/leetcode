#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << std::endl;
    }
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << std::endl;
        for (auto its = std::next(it) ; its != mySet.end(); ++its) {
            std::cout << *its << std::endl;
        }
    }


    return 0;
}
