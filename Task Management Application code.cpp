#include <bits/stdc++.h>
using namespace std;

// Define ANSI color codes for terminal output
const string RED = "\033[31m";    // Red color
const string GREEN = "\033[32m";  // Green color
const string YELLOW = "\033[33m"; // Yellow color (for menu options)
const string BLUE = "\033[34m";   // Blue color
const string RESET = "\033[0m";   // Reset to default color

int main() {
    // Create an unordered_map to store tasks categorized by their respective categories
    unordered_map<string, vector<string>> taskCategories;
    int choice; // Variable to store user's menu choice

    while (true) {
        // Display the menu with color coding
        cout << "\n" << BLUE << "To-Do List Menu:" << RESET << "\n";
        cout << "1. " << YELLOW << "Add a Task" << RESET << "\n";
        cout << "2. " << YELLOW << "View Tasks by Category" << RESET << "\n";
        cout << "3. " << YELLOW << "Remove a Task" << RESET << "\n";
        cout << "4. " << YELLOW << "Exit" << RESET << "\n";
        cout << "Choose an option: ";
        
        cin >> choice; // Get user input for menu choice

        // Check for invalid input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << RED << "Invalid input! Please enter a number." << RESET << "\n";
            continue; // Restart the loop to show the menu again
        }

        cin.ignore(); // Ignore the leftover newline character from the input

        if (choice == 1) {
            // Adding a new task
            string taskDescription, category;
            cout << RED << "Enter the task description: " << RESET;
            getline(cin, taskDescription); // Read the task description
            cout << RED << "Enter the category: " << RESET;
            getline(cin, category); // Read the category

            // Add the task to the specified category
            taskCategories[category].push_back(taskDescription);
            cout << GREEN << "Task added successfully!" << RESET << "\n";
        } else if (choice == 2) {
            // Viewing tasks by category
            if (taskCategories.empty()) {
                // Inform the user if no tasks are available
                cout << YELLOW << "No tasks available." << RESET << "\n";
            } else {
                cout << "\n" << GREEN << "Tasks by Category:" << RESET << "\n";
                // Iterate over each category
                for (auto it = taskCategories.begin(); it != taskCategories.end(); ) {
                    const string& category = it->first; // Category name
                    vector<string>& tasks = it->second; // List of tasks for this category
                    if (tasks.empty()) {
                        // Remove the category if there are no tasks
                        it = taskCategories.erase(it);
                    } else {
                        // Display the category and its tasks
                        cout << BLUE << category << ":" << RESET << "\n";
                        for (const auto& task : tasks) {
                            cout << "- " << task << "\n";
                        }
                        ++it; // Move to the next category
                    }
                }
            }
        } else if (choice == 3) {
            // Removing a task
            string category, taskDescription;
            cout << RED << "Enter the category: " << RESET;
            getline(cin, category); // Read the category
            cout << RED << "Enter the task description to remove: " << RESET;
            getline(cin, taskDescription); // Read the task description

            auto& tasks = taskCategories[category]; // Get the list of tasks for the category
            auto it = find(tasks.begin(), tasks.end(), taskDescription); // Find the task to remove
            if (it != tasks.end()) {
                tasks.erase(it); // Remove the task from the list
                cout << GREEN << "Task completed successfully!" << RESET << "\n";
                
                // Check if the category is empty and remove it if necessary
                if (taskCategories[category].empty()) {
                    taskCategories.erase(category);
                }
            } else {
                // Inform the user if the task was not found
                cout << RED << "Task not found in the specified category!" << RESET << "\n";
            }
        } else if (choice == 4) {
            // Exit the program
            cout << RED << "Exiting the program..." << RESET << "\n";
            break; // Exit the while loop
        } else {
            // Inform the user if an invalid menu option was chosen
            cout << RED << "Invalid option! Please try again." << RESET << "\n";
        }
    }

    return 0; // End of the program
}
