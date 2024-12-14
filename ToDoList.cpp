#include <iostream>
#include <string>
using namespace std;

// Function to display tasks
void PrintTasks(string tasks[], int taskCount) {
    cout << "\n========== TO-DO LIST ==========" << endl;
    if (taskCount == 0) {
        cout << "Your to-do list is empty.\n";
    } else {
        for (int i = 0; i < taskCount; i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
    cout << "================================\n";
}

int main() {
    string tasks[10];
    int taskCount = 0;
    int opt = -1;

    while (opt != 0) {
        // Display menu
        cout << "\n========== TO-DO LIST MENU ==========" << endl;
        cout << "1 - Add Task\n";
        cout << "2 - View Tasks\n";
        cout << "3 - Delete Task\n";
        cout << "0 - Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> opt;
        cin.ignore(); // Clear input buffer

        switch (opt) {
        case 1: { // Add task
            if (taskCount >= 10) {
                cout << "\nYour to-do list is full!\n";
            } else {
                cout << "\nEnter the task: ";
                getline(cin, tasks[taskCount]);
                taskCount++;
                cout << "Task added successfully!\n";
            }
            break;
        }

        case 2: { // View tasks
            PrintTasks(tasks, taskCount);
            break;
        }

        case 3: { // Delete task
            if (taskCount == 0) {
                cout << "\nYour to-do list is empty. Nothing to delete.\n";
            } else {
                int del;
                cout << "\nEnter the task number to delete (1-" << taskCount << "): ";
                cin >> del;

                if (del < 1 || del > taskCount) {
                    cout << "Invalid task number!\n";
                } else {
                    for (int i = del - 1; i < taskCount - 1; i++) {
                        tasks[i] = tasks[i + 1];
                    }
                    taskCount--;
                    cout << "Task deleted successfully!\n";
                }
            }
            break;
        }

        case 0: { // Exit
            cout << "\nExiting the program. Goodbye!\n";
            break;
        }

        default: {
            cout << "\nInvalid option. Please try again.\n";
            break;
        }
        }
    }

    return 0;
}
