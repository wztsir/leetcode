#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric> // 为了使用std::accumulate()函数
#include <sstream>
#include <functional>
#include "ListNode.h"
using namespace std;

ListNode* removeNodes(ListNode* head) {
    if (head == nullptr)return head;
    deque<int> q;
    ListNode *node = head;
    while (node != nullptr) {
        // 如果队列不为空且队尾元素小于当前节点值，则弹出队尾元素
        while (!q.empty() && q.back()< node->val) {
            q.pop_back();
        }
        // 将当前节点值入队
        q.push_back(node->val);
        // 移动到下一个节点
        node = node->next;
    }
    // 创建一个虚拟头节点
    ListNode dummy(0);
    ListNode *cur = &dummy;
    // 遍历队列中的元素，构建新的链表
    while (!q.empty()) {
        cur->next = new ListNode(q.front());
        q.pop_front();
        cur = cur->next;
    }
    // 返回新链表的头节点
    return dummy.next;
}
int main()
{
    queue<int> q;
    // 入队操作
    q.push(1);
    q.push(2);
    q.push(3);

    // 队首出队
    int front_value = q.front();
    q.pop();
    cout << "队首元素已出队：" << front_value << endl; // 输出：队首元素已出队：1
}