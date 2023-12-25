#include <iostream>
#include <deque>

using namespace std;

class MonotonicQueue {
public:
    // 构造函数
    MonotonicQueue(bool isIncreasing = true) {
        increasing = isIncreasing;
    }

    // 向队尾添加元素，并维护单调性
    void push(int val) {
        while (!dq.empty() && (increasing ? dq.back() < val : dq.back() > val)) {
            dq.pop_back();
        }
        dq.push_back(val);
    }

    // 弹出队头元素，如果队列为空则返回-1
    int pop() {
        if (dq.empty()) {
            return -1; // 队列为空
        }
        int front = dq.front();
        dq.pop_front();
        return front;
    }

    // 获取队头元素，如果队列为空则返回-1
    int front() {
        if (dq.empty()) {
            return -1; // 队列为空
        }
        return dq.front();
    }

    // 判断队列是否为空
    bool empty() {
        return dq.empty();
    }

private:
    deque<int> dq; // 用于存储元素的双端队列
    bool increasing; // 标志队列是维护单调递增还是单调递减
};

int main() {
    MonotonicQueue incQueue(true); // 单调递增队列
    MonotonicQueue decQueue(false); // 单调递减队列

    // 向单调递增队列中添加元素
    incQueue.push(3);
    incQueue.push(1);
    incQueue.push(5);

    // 输出单调递增队列的队头元素
    cout << "Front of Increasing Queue: " << incQueue.front() << endl;

    // 弹出单调递增队列的队头元素
    incQueue.pop();

    // 向单调递减队列中添加元素
    decQueue.push(10);
    decQueue.push(7);
    decQueue.push(15);

    // 输出单调递减队列的队头元素
    cout << "Front of Decreasing Queue: " << decQueue.front() << endl;

    return 0;
}
