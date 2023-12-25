#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;



bool isCloneSubstring(string& str) {
    int n = str.length();
    
    for (int i = 0; i < n; i++) {
        for (int length = 2; length + i <= n; length+=2) {
            if (str.substr(i, length / 2) == str.substr(i + length / 2, length / 2)) {
                return true;
            }
        }
    }
    return false;
}

//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        string s;
//        cin >> s;
//        if (isCloneSubstring(s)) {
//            cout << "YES\n";
//        }
//        else {
//            cout << "NO\n";
//        }
//    }
//}
//3
//abab
//abcde
//zaat
