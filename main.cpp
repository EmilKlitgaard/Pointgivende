#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Task {
public:
    std::string description;
    int priority;
    bool completed;

    Task(std::string desc, int prio) 
        : description(desc), priority(prio) , completed(false) {}

    void markCompleted() {
        completed = true;
        std::cout << "Task completed: " << description << std::endl;
    }
};

class TodoList {
public:
    std::vector<Task> tasks;

    void addTask(std::string description, int priority) {
        tasks.push_back(Task(description, priority));
        std::cout << "Task added: " << description << std::endl;
    }
  
    void viewTasks() {
        std::cout << "Your tasks:\n";
        for (const auto& task : tasks) {
            std::cout << "- " << task.description << std::endl;
        }
    }

    void prioritizeTasks() {
        std::sort(
            tasks.begin(), 
            tasks.end(), 
            [](const Task& a, const Task& b) {return a.priority > b.priority;}
        );
    }
    
    void viewTasksByStatus(bool showCompleted) {
        std::cout <<(showCompleted?"\nCompleted tasks:\n":"\nPending Tasks:\n");
        for (int i = 0; i<tasks.size();i++){
            if (tasks[i].completed==showCompleted) {
                std::cout << i << ": " << tasks[i].description << " | " << tasks[i].priority;
                if (tasks[i].completed){
                    std::cout << " | completed";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl; 
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

    std::string taskDesc;

    std::cout << "Enter a task description: ";
    std::getline(std::cin, taskDesc);
    todo.addTask(taskDesc, 1);

    todo.addTask("Buy groceries", 0);
    todo.addTask("Finish homework", 2);

    todo.completeTask(0);
  
    todo.viewTasks();
    todo.viewTasksByStatus(true);

    todo.prioritizeTasks();
    todo.viewTasks();

    return 0;
};