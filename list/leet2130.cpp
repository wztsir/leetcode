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
int pairSum2(ListNode* head) {
    vector<int> arr;
    while(head){
        arr.push_back(head->val);
        head = head->next;
    }
    int size = arr.size(), ans = 0;
    for(int i = 0; i < size - 1 - i; i++){
        ans = max(ans, arr[i] + arr[size-1-i]);
    }
    return ans;
}
int pairSum(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    ListNode* pre = nullptr;
    ListNode* temp = new ListNode();
    while(fast && fast->next){
        fast = fast->next->next;
        temp = slow->next;
        slow->next = pre;
        pre = slow;
        slow = temp;
    }
    int ans = 0;
    while(temp){
        ans = max(ans, temp->val + slow->val);
        temp = temp->next;
        slow = slow->next;
    }
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
