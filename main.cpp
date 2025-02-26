#include <string>
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
        std::cout << "Task added: " << description << std::endl;
    }
  
    void viewTasks() {
        for (const auto& task : todolist) {
            std::cout << "- " << task._description << std::endl;

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

    std::string taskDesc;

    std::cout << "Enter a task description: ";
    std::getline(std::cin, taskDesc);
    todo.addTask(taskDesc);

    todo.addTask("Buy groceries");
    todo.addTask("Finish homework");
  
    std::cout << "Your tasks:\n";
    todo.viewTasks();

    todo.completeTask(0);

    return 0;
}

