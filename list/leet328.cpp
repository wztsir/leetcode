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
ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr || head ->next == nullptr)return head;
    ListNode* odd  = new ListNode();
    ListNode* even = new ListNode();
    ListNode* second = new ListNode();
    odd = head;
    even = head->next;
    second = head->next;
    while(odd && even && even->next){
        odd->next  = even->next;
        odd = odd->next;
        even->next =  odd->next;
        even = even -> next;
    }
    odd->next = second;
    return head;
}
int main()
{
   system("pause");
   return 0;
}
