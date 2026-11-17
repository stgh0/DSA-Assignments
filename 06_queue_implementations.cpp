// Shivtej Ghorpade | PRN: 202501110185 | AIML B3
#include <iostream>
#include <stack>
#include <vector>
#include <stdexcept>
class LinkedQueue {
    struct Node { int value; Node* next; explicit Node(int x) : value(x), next(nullptr) {} };
    Node* frontNode = nullptr;
    Node* rearNode = nullptr;
    std::size_t count = 0;
public:
    LinkedQueue() = default;
    // Raw nodes have unique ownership; prevent accidental shallow copies.
    LinkedQueue(const LinkedQueue&) = delete;
    LinkedQueue& operator=(const LinkedQueue&) = delete;
    ~LinkedQueue() { while (frontNode) { Node* old = frontNode; frontNode = old->next; delete old; } }
    void enqueue(int value) {
        Node* node = new Node(value);
        if (rearNode) rearNode->next = node;
        else frontNode = node;
        rearNode = node; ++count;
    }
    int dequeue() {
        if (!frontNode) throw std::underflow_error("Queue is empty");
        Node* old = frontNode; int value = old->value;
        frontNode = old->next; delete old; --count;
        if (!frontNode) rearNode = nullptr;
        return value;
    }
    int peek() const {
        if (!frontNode) throw std::underflow_error("Queue is empty");
        return frontNode->value;
    }
    std::size_t size() const { return count; }
    bool empty() const { return count == 0; }
    bool search(int value) const {
        for (Node* node = frontNode; node; node = node->next)
            if (node->value == value) return true;
        return false;
    }
    std::vector<int> traverse() const {
        std::vector<int> values;
        for (Node* node = frontNode; node; node = node->next) values.push_back(node->value);
        return values;
    }
};
class QueueTwoStacks {
    std::stack<int> incoming, outgoing;
    void prepare() {
        if (outgoing.empty())
            while (!incoming.empty()) { outgoing.push(incoming.top()); incoming.pop(); }
    }
public:
    void enqueue(int value) { incoming.push(value); }
    int dequeue() {
        prepare();
        if (outgoing.empty()) throw std::underflow_error("Queue is empty");
        int value = outgoing.top(); outgoing.pop(); return value;
    }
    int peek() {
        prepare();
        if (outgoing.empty()) throw std::underflow_error("Queue is empty");
        return outgoing.top();
    }
    std::size_t size() const { return incoming.size() + outgoing.size(); }
    bool empty() const { return size() == 0; }
    std::vector<int> traverse() const {
        auto out = outgoing, in = incoming;
        std::vector<int> values, reversedInput;
        while (!out.empty()) { values.push_back(out.top()); out.pop(); }
        while (!in.empty()) { reversedInput.push_back(in.top()); in.pop(); }
        for (auto it = reversedInput.rbegin(); it != reversedInput.rend(); ++it) values.push_back(*it);
        return values;
    }
    bool search(int value) const {
        auto in = incoming, out = outgoing;
        while (!in.empty()) { if (in.top() == value) return true; in.pop(); }
        while (!out.empty()) { if (out.top() == value) return true; out.pop(); }
        return false;
    }
};
#ifndef DSA_NO_MAIN
template<class Q> void demonstrate(const char* name) {
    Q q; std::cout << name << "\nFront to rear: ";
    for (int x : {10,20,30}) q.enqueue(x);
    for (int x : q.traverse()) std::cout << x << ' ';
    std::cout << "\nDequeue: " << q.dequeue(); q.enqueue(40);
    std::cout << "\nAfter enqueue 40: ";
    for (int x : q.traverse()) std::cout << x << ' ';
    std::cout << "\nContains 30: " << std::boolalpha << q.search(30) << '\n';
}
int main() { demonstrate<LinkedQueue>("Linked queue"); demonstrate<QueueTwoStacks>("Queue using two stacks"); }
#endif
