#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

// Employee Class
class Employee
{
private:
    struct EmployeeDetails
    {
        int id;
        string name;
        double salary;
    };
    vector<EmployeeDetails> employees;           // Vector to store employee details
    const string filename = "employee_data.txt"; // File to store employee data

    // Helper to load employees from file
    void loadFromFile()
    {
        ifstream file(filename);
        if (!file)
            return;        // File not found; skip loading
        employees.clear(); // Clear any existing data
        EmployeeDetails emp;
        while (file >> emp.id)
        {
            file.ignore(); // Ignore newline after ID
            getline(file, emp.name);
            file >> emp.salary;
            file.ignore(); // Ignore newline after salary
            employees.push_back(emp);
        }
        file.close();
    }

    // Helper to save employees to file
    void saveToFile() const
    {
        ofstream file(filename);
        for (const auto &emp : employees)
        {
            file << emp.id << "\n"
                 << emp.name << "\n"
                 << emp.salary << "\n";
        }
        file.close();
    }

public:
    // Constructor to load data when program starts
    Employee()
    {
        loadFromFile();
    }

    // Destructor to save data when program ends
    ~Employee()
    {
        saveToFile();
    }

    // Add Employee Details
    void addEmployee(int id, string name, double salary)
    {
        employees.push_back({id, name, salary});
        cout << "Employee added successfully!\n";
    }

    // Delete Employee by ID
    void deleteEmployee(int id)
    {
        for (auto it = employees.begin(); it != employees.end(); ++it)
        {
            if (it->id == id)
            {
                employees.erase(it);
                cout << "Employee with ID " << id << " deleted successfully!\n";
                return;
            }
        }
        cout << "Employee with ID " << id << " not found!\n";
    }

    // View All Employee Details
    void viewEmployees() const
    {
        if (employees.empty())
        {
            cout << "No employees to display.\n";
            return;
        }
        cout << "Employee Details:\n";
        cout << "ID\tName\t\tSalary\n";
        cout << "-----------------------------------\n";
        for (const auto &emp : employees)
        {
            cout << emp.id << "\t" << emp.name << "\t\t" << emp.salary << "\n";
        }
    }

    // Search Employee by Name
    void searchByName(const string &name) const
    {
        bool found = false;
        cout << "Search Results:\n";
        cout << "Id\tname\t\tSalary\n";
        cout << "-------------------------------------\n";
        for (const auto &emp : employees)
        {
            if (emp.name.find(name) != string::npos)
            { // Partial match
                cout << emp.id << "\t" << emp.name << "\t\t" << emp.salary << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No employee found with name containing" << name << endl;
        }
    }
};

// Main Function
int main()
{
    Employee empManager;
    int choice;

    do
    {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. View All Employees\n";
        cout << "4. Search Employee by Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name;
            double salary;
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Employee Salary: ";
            cin >> salary;
            empManager.addEmployee(id, name, salary);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter Employee ID to delete: ";
            cin >> id;
            empManager.deleteEmployee(id);
            break;
        }
        case 3:
            empManager.viewEmployees();
            break;
        case 4:
        {
            string name;
            cout << "Enter Employee Name to search: ";
            cin.ignore();
            getline(cin, name);
            empManager.searchByName(name);
            break;
        }
        case 5:
            cout << "Exiting Employee Management System.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } 
    while (choice != 4);

    return 0;
}