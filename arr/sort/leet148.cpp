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
//归并排序的模板题
ListNode* sortList(ListNode* head) {
    if(head == nullptr || head->next == nullptr)return head;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode * temp = slow->next;
    slow->next = nullptr;
    ListNode* left = sortList(head);
    ListNode* right = sortList(temp);
    ListNode* h = new ListNode(0);
    ListNode* res = h;
    while(left != nullptr && right != nullptr){
        if(left->val < right->val){
            h->next = left;
            left = left->next;
        }else{
            h->next = right;
            right = right->next;
        }
        h = h->next;
    }
    h->next = left != nullptr ? left : right;
    return res->next;
}
int main()
{
   system("pause");
   return 0;
}
