// Shivtej Ghorpade | PRN: 202501110185 | AIML B3
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
struct Task { int id; std::string description; int priority; };
class TaskScheduler {
    std::deque<Task> tasks;
public:
    void add(const Task& task, bool atFront = false) {
        if (search(task.id)) throw std::invalid_argument("Duplicate task ID");
        if (atFront) tasks.push_front(task); else tasks.push_back(task);
    }
    const Task* search(int id) const {
        for (const auto& task : tasks) if (task.id == id) return &task;
        return nullptr; // Borrowed pointer: do not retain across mutations.
    }
    Task cancel(int id) {
        auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& t) { return t.id == id; });
        if (it == tasks.end()) throw std::out_of_range("Task ID not found");
        Task result = *it; tasks.erase(it); return result;
    }
    Task processNext() {
        if (tasks.empty()) throw std::underflow_error("Scheduler is empty");
        // First maximum wins, so equal priorities follow front-to-rear order.
        auto it = std::max_element(tasks.begin(), tasks.end(),
            [](const Task& a, const Task& b) { return a.priority < b.priority; });
        Task result = *it; tasks.erase(it); return result;
    }
    std::vector<Task> traverse() const { return {tasks.begin(), tasks.end()}; }
    std::size_t size() const { return tasks.size(); }
    bool empty() const { return tasks.empty(); }
};
#ifndef DSA_NO_MAIN
int main() {
    TaskScheduler s;
    s.add({1,"Backup",1}); s.add({2,"Urgent repair",5}); s.add({3,"Security alert",5},true);
    std::cout << "Pending IDs: ";
    for (const auto& task : s.traverse()) std::cout << task.id << ' ';
    std::cout << '\n';
    while (!s.empty()) {
        Task t = s.processNext();
        std::cout << "Processed: " << t.id << " priority " << t.priority << '\n';
    }
}
#endif
