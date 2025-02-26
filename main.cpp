#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(std::string desc) : description(desc), completed(false) {}

    void markCompleted() {
        completed = true;
        std::cout << "Task completed: " << description << std::endl;
    }
};

class TodoList {
public:
    std::vector<Task> tasks;

    void addTask(std::string description) {
        tasks.push_back(Task(description));
    }

    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markCompleted();
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    TodoList todo;
    todo.addTask("Buy groceries");
    todo.addTask("Finish homework");

    todo.completeTask(1); // Mark "Buy groceries" as completed

    return 0;
}
