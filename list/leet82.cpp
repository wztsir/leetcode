#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>
#include"ListNode.h"
using namespace std;
ListNode* deleteDuplicates(ListNode* head) {

    if(head == nullptr)return nullptr;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* cur = head;
    int x = -101;
    while(cur != nullptr){
        if(cur->next != nullptr && cur->next->next != nullptr && cur->next->val == cur->next->next->val){
            x = cur->next->val;
            cur->next = cur->next->next;
        }
        else if(cur->next != nullptr && cur->next->val == x){
            cur->next = cur->next->next;
        }else{
            cur = cur->next;
        }
    }
    return dummy->next;
}