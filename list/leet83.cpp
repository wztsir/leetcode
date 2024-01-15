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
#include"ListNode.h"
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
	if (head == nullptr)return head;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != nullptr) {
        while(fast != nullptr && fast->val == slow->val){
            fast = fast->next;
        }
        slow->next = fast;
        slow = slow->next;
	}
	if(slow)slow->next = nullptr;
	return head;
}