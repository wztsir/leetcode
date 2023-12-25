//#include<iostream>
//#include<stack>
//#include<unordered_map>
//using namespace std;
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		int n;
//		cin >> n;
//		stack<int> s;
//		unordered_map<int, bool> map;
//		vector<int> v(2 * n);
//		for (int i = 0; i < 2 * n; i++) {
//			cin >> v[i];
//		}
//		int i;
//		for (i = 0; i < 2 * n; i++) {
//			int key = v[i];
//			if (map.find(key) == map.end()) {
//				s.push(key);
//				map[key] = false;
//			}
//			else {
//				if (map[key] == true) {
//					cout << "No\n";
//					break;
//				}
//				else {
//					if (s.top() != key) {
//						cout << "No\n";
//						break;
//					}
//					else {
//						s.pop();
//						map[key] = true;
//					}
//				}
//
//			}
//		}
//		if(i == 2*n)cout << "Yes\n";
//	}
//	
//}
////3
////3
////1 2 2 1 3 3
////2
////1 2 1 2
////2
////1 1 1 1