#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string _description;
    Task(std::string description) : _description(description) {}
};

class TodoList {
public:
    std::vector<Task> todolist;
    
    void addTask(std::string description) {
        todolist.push_back(Task(description));
    }

    void viewTasks() {
        for (const auto& task : todolist) {
            std::cout << "- " << task._description << std::endl;
        }
    }
};

int main() {
    TodoList todo;
    todo.addTask("Buy groceries");
    todo.addTask("Complete assignment");

    std::cout << "Your tasks:\n";
    todo.viewTasks();

    return 0;
}
