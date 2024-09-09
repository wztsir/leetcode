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

int main()
{
   system("pause");
   return 0;
}

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
	sort(potions.begin(), potions.end());
	int n = spells.size(), m = potions.size();
	vector<int> ans(spells.size());
	for (int i = 0; i < n; i++) {
		//int temp = success / spells[i];
		int left = 0, right = m-1;
        
		while (left <= right) {
			int num = left + (right - left) / 2;
            long long temp = (long long)potions[num] * spells[i];
			if (temp >= success) {
				right = num - 1;
			}
			// else if (temp > success) {
			// 	right = num - 1;
			// }
			else if (temp < success) {
				left = num + 1;
			}
		}
        ans[i] = m - left;
	}
    return ans;
}