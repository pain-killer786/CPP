#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100; // Maximum number of rooms

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

// Customer Class
class Customer
{
private:
    int booking_id;

public:
    char name[100];
    char address[100];
    char phone[15];
    char from_date[20];
    char to_date[20];
    float payment_advance;

    // Constructor
    Customer() : booking_id(0), payment_advance(0)
    {
        strcpy(name, "");
        strcpy(address, "");
        strcpy(phone, "");
        strcpy(from_date, "");
        strcpy(to_date, "");
    }
};

// Room Class
class Room
{
public:
    char ac;        // AC/Non-AC (A/N)
    char type;      // Comfort (S/N)
    char size;      // Size (K/Q/S)
    int roomNumber; // Room number
    float rent;     // Daily rent
    int status;     // 0 = available, 1 = reserved
    Customer cust;  // Associated customer

    // Constructor
    Room() : ac('N'), type('N'), size('S'), roomNumber(0), rent(0), status(0) {}

    // Room management methods
    Room addRoom(int);
    void searchRoom(int);
    void displayRoom(Room);
};

// Hotel Class
class Hotel : protected Room
{
private:
    Room rooms[MAX]; // Array of rooms
    int count;       // Number of rooms

public:
    // Constructor
    Hotel() : count(0) {}

    // Hotel management methods
    void checkIn();
    void getAvailRooms();
    void searchCustomer(const char *);
    void checkOut(int);
    void guestSummaryReport();
};

// Room Class Method Definitions
Room Room::addRoom(int roomNo)
{
    Room room;
    room.roomNumber = roomNo;
    cout << "\nEnter Type AC/Non-AC (A/N): ";
    cin >> room.ac;
    cout << "Enter Type Comfort (S/N): ";
    cin >> room.type;
    cout << "Enter Type Size (K/Q/S): ";
    cin >> room.size;
    cout << "Enter Daily Rent: ";
    cin >> room.rent;
    room.status = 0; // Mark room as available
    cout << "Room added successfully!\n";
    return room;
}

void Room::searchRoom(int roomno)
{
    for (int i = 0; i < MAX; i++)
    {
        if (room[i].roomNumber == roomno)
        {
            cout << "\nRoom Details:\n";
            displayRoom(rooms[i]);
            cout << (rooms[i].status ? "Room is Reserved\n" : "Room is Available\n");
            return;
        }
    }
    cout << "Room not found!\n";
}

void Room::displayRoom(Room room)
{
    cout << "\nRoom Number: " << room.roomNumber;
    cout << "\nAC/Non-AC: " << room.ac;
    cout << "\nComfort: " << room.type;
    cout << "\nSize: " << room.size;
    cout << "\nRent: " << room.rent << endl;
}

// Hotel Class Method Definitions
void Hotel::checkIn()
{
    int roomno, found = 0;
    cout << "Enter Room Number: ";
    cin >> roomno;

    for (int i = 0; i < count; i++)
    {
        if (rooms[i].roomNumber == roomno)
        {
            found = 1;
            if (rooms[i].status == 1)
            {
                cout << "Room is already booked!\n";
                return;
            }

            cout << "Enter Booking ID: ";
            cin >> rooms[i].cust.booking_id;
            cout << "Enter Customer Name: ";
            cin.ignore();
            cin.getline(rooms[i].cust.name, 100);
            cout << "Enter Address: ";
            cin.getline(rooms[i].cust.address, 100);
            cout << "Enter Phone: ";
            cin.getline(rooms[i].cust.phone, 15);
            cout << "Enter From Date (dd/mm/yyyy): ";
            cin.getline(rooms[i].cust.from_date, 20);
            cout << "Enter To Date (dd/mm/yyyy): ";
            cin.getline(rooms[i].cust.to_date, 20);
            cout << "Enter Advance Payment: ";
            cin >> rooms[i].cust.payment_advance;

            rooms[i].status = 1; // Mark room as booked
            cout << "Customer Checked-in Successfully!\n";
            return;
        }
    }

    if (!found)
        cout << "Room not found!\n";
}

void Hotel::getAvailRooms()
{
    cout << "\nAvailable Rooms:\n";
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].status == 0)
        {
            displayRoom(rooms[i]);
            cout << "----------------------\n";
        }
    }
}

void Hotel::searchCustomer(const char *pname)
{
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].status == 1 && strcmp(rooms[i].cust.name, pname) == 0)
        {
            cout << "\nCustomer Name: " << rooms[i].cust.name;
            cout << "\nRoom Number: " << rooms[i].roomNumber << endl;
            return;
        }
    }
    cout << "Customer not found!\n";
}

void Hotel::checkOut(int rno)
{
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].status == 1 && rooms[i].roomNumber == rno)
        {
            int days;
            cout << "Enter Number of Days Stayed: ";
            cin >> days;

            float bill = days * rooms[i].rent;
            cout << "\nTotal Bill: " << bill;
            cout << "\nAdvance Paid: " << rooms[i].cust.payment_advance;
            cout << "\nRemaining Payment: " << (bill - rooms[i].cust.payment_advance) << endl;

            rooms[i].status = 0; // Mark room as available
            return;
        }
    }
    cout << "Room not found or already vacant!\n";
}

void Hotel::guestSummaryReport()
{
    cout << "\nGuest Summary Report:\n";
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].status == 1)
        {
            cout << "\nCustomer Name: " << rooms[i].cust.name;
            cout << "\nRoom Number: " << rooms[i].roomNumber;
            cout << "\n----------------------\n";
        }
    }
}

// Main Function
int main()
{
    Employee empManager;
    Hotel hotelManager;

    int mainChoice;

    do
    {
        cout << "\n--- Hotel Management System ---\n";
        cout << "1. Employee Management\n";
        cout << "2. Hotel Management\n";
        cout << "3. Restaurant Management (Coming Soon)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
        {
            int empChoice;
            do
            {
                cout << "\n--- Employee Management ---\n";
                cout << "1. Add Employee\n";
                cout << "2. Delete Employee\n";
                cout << "3. View All Employees\n";
                cout << "4. Search Employee by Name\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> empChoice;

                switch (empChoice)
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
                    cout << "Returning to Main Menu.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } 
            while (empChoice != 5);
            break;
        }
        case 2:
        {
            int hotelChoice;
            do
            {
                cout << "\n--- Hotel Management System ---\n";
                cout << "1. Add Room\n";
                cout << "2. Check In\n";
                cout << "3. Check Out\n";
                cout << "4. View Available Rooms\n";
                cout << "5. Search Customer\n";
                cout << "6. Guest Summary Report\n";
                cout << "7. Exit\n";
                cout << "Enter your choice: ";
                cin >> hotelChoice;

                switch(hotelChoice)
                {
                case 1:
                {
                    int roomNo;
                    cout << "Enter Room Number to Add: ";
                    cin >> roomNo;
                    hotelManager.addRoom(roomNo);
                    break;
                }
                case 2:
                    hotelManager.checkIn();
                    break;
                case 3:
                {
                    int roomNo;
                    cout << "Enter Room Number to Check Out: ";
                    cin >> roomNo;
                    hotelManager.checkOut(roomNo);
                    break;
                }
                case 4:
                    hotelManager.getAvailRooms();
                    break;
                case 5:
                {
                    char name[100];
                    cout << "Enter Customer Name to Search: ";
                    cin.ignore();
                    cin.getline(name, 100);
                    hotelManager.searchCustomer(name);
                    break;
                }
                case 6:
                    hotelManager.guestSummaryReport();
                    break;
                case 7:
                    cout << "Exiting Hotel Management System.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } 
            while (hotelChoice != 7);  
        }
    }
    }
    return 0;
}