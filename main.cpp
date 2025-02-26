#include <iostream>
#include <string>
#include <vector>

class Task {
public:
    std::string description;

    Task(std::string desc) {
        description = desc;
    }
};

class TodoList {
public:
    std::vector<Task> tasks;

    void addTask(std::string description) {
        tasks.push_back(Task(description));
        std::cout << "Task added: " << description << std::endl;
    }
};

int main() {
    TodoList todo;
    std::string taskDesc;

    std::cout << "Enter a task description: ";
    std::getline(std::cin, taskDesc);
    todo.addTask(taskDesc);

    return 0;
}

