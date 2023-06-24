#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Plan
{
public:
    std::string start_time;
    std::string end_time;
    std::string description;
};

std::vector<Plan> plan;

void savePlanToFile(const std::string &filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        for (const Plan &task : plan)
        {
            file << task.start_time << "," << task.end_time << "," << task.description << "\n";
        }
        file.close();
        std::cout << "Plan saved successfully.\n";
    }
    else
    {
        std::cout << "Unable to open file for writing.\n";
    }
}

void loadPlanFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        plan.clear();
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string startTime, endTime, description;
            if (std::getline(iss, startTime, ',') &&
                std::getline(iss, endTime, ',') &&
                std::getline(iss, description))
            {
                Plan task;
                task.start_time = startTime;
                task.end_time = endTime;
                task.description = description;
                plan.push_back(task);
            }
        }
        file.close();
        std::cout << "Plan loaded successfully.\n";
    }
    else
    {
        std::cout << "Unable to open file for reading.\n";
    }
}

void addTask(const std::string &startTime, const std::string &endTime, const std::string &description)
{
    // Check for time conflicts
    for (const Plan &task : plan)
    {
        if ((startTime >= task.start_time && startTime <= task.end_time) ||
            (endTime >= task.start_time && endTime <= task.end_time))
        {
            std::cout << "There is a time conflict with an existing task.\n";
            return;
        }
    }

    Plan newTask;
    newTask.start_time = startTime;
    newTask.end_time = endTime;
    newTask.description = description;
    plan.push_back(newTask);
    std::cout << "Plan added successfully.\n";
}

void removeTask(int index)
{
    if (index >= 0 && index < plan.size())
    {
        plan.erase(plan.begin() + index);
        std::cout << "Plan removed successfully.\n";
    }
    else
    {
        std::cout << "Invalid task index.\n";
    }
}

void removeAllTasks()
{
    plan.clear();
    std::cout << "All tasks removed successfully.\n";
}

void listTasks()
{
    if (plan.empty())
    {
        std::cout << "No tasks found.\n";
    }
    else
    {
        for (const Plan &task : plan)
        {
            std::cout << task.start_time << " - " << task.end_time << " " << task.description << "\n";
        }
    }
}
int main()
{
    std::string filename = ".plan";
    loadPlanFromFile(filename);

    std::string command;
    while (true)
    {
        std::cout << "Enter a command ('add', 'remove', 'list', 'quit'): ";
        std::cin >> command;
        if (command == "add")
        {
            std::string startTime, endTime, description;
            std::cout << "Enter start time (HH:MM:am/pm): ";
            std::cin >> startTime;
            std::cout << "Enter end time (HH:MM:am/pm): ";
            std::cin >> endTime;
            std::cout << "Enter task description: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            addTask(startTime, endTime, description);
        }
        else if (command == "remove")
        {
            std::string option;
            std::cout << "Enter option ('-i' or '-a'): ";
            std::cin >> option;
            if (option == "-i")
            {
                int index;
                std::cout << "Enter task index: ";
                std::cin >> index;
                removeTask(index);
            }
            else if (option == "-a")
            {
                removeAllTasks();
            }
            else
            {
                std::cout << "Invalid option.\n";
            }
        }
        else if (command == "list")
        {
            listTasks();
        }
        else if (command == "quit")
        {
            savePlanToFile(filename);
            std::cout << "Exiting the program. Plan saved to '" << filename << "'.\n";
            break;
        }
        else
        {
            std::cout << "Invalid command.\n";
        }
    }

    return 0;
}
