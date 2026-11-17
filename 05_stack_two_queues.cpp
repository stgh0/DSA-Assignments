// Shivtej Ghorpade | PRN: 202501110185 | AIML B3
#include <iostream>
#include <queue>
#include <vector>
#include <stdexcept>
class StackTwoQueues {
    std::queue<int> active, spare;
public:
    void push(int value) {
        spare.push(value);
        while (!active.empty()) { spare.push(active.front()); active.pop(); }
        active.swap(spare);
    }
    int pop() {
        if (active.empty()) throw std::underflow_error("Stack is empty");
        int value = active.front(); active.pop(); return value;
    }
    int peek() const {
        if (active.empty()) throw std::underflow_error("Stack is empty");
        return active.front();
    }
    std::size_t size() const { return active.size(); }
    bool empty() const { return active.empty(); }
    std::vector<int> traverse() const {
        auto copy = active; std::vector<int> values;
        while (!copy.empty()) { values.push_back(copy.front()); copy.pop(); }
        return values;
    }
    bool search(int value) const {
        auto copy = active;
        while (!copy.empty()) {
            if (copy.front() == value) return true;
            copy.pop();
        }
        return false;
    }
};
#ifndef DSA_NO_MAIN
int main() {
    StackTwoQueues s;
    for (int x : {10,20,30}) s.push(x);
    std::cout << "Top to bottom: ";
    for (int x : s.traverse()) std::cout << x << ' ';
    std::cout << "\nContains 20: " << std::boolalpha << s.search(20)
              << "\nPop: " << s.pop() << "\nPeek: " << s.peek() << '\n';
    while (!s.empty()) s.pop();
    try { s.pop(); } catch (const std::underflow_error& e) { std::cout << e.what() << '\n'; }
}
#endif
