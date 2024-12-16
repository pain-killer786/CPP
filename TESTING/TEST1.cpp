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
    struct EmployeeRecord
    {
        int id;
        string name;
        string position;
        double salary;
    };

    vector<EmployeeRecord> employees;                // Vector to store employee details
    const string employeeFile = "employee_data.txt"; // File to store employee data

    // Helper to save employees to file
    void saveEmployeesToFile() const
    {
        ofstream file(employeeFile);
        if (!file)
        {
            cout << "Error: Unable to save employee data." << endl;
            return;
        }

        for (const auto &emp : employees)
        {
            file << emp.id << "\n"
                 << emp.name << "\n"
                 << emp.position << "\n"
                 << emp.salary << "\n";
        }
        file.close();
    }

    // Helper to load employees from file
    void loadEmployeesFromFile()
    {
        ifstream file(employeeFile);
        if (!file)
        {
            cout << "No existing employee data found. " << endl;
            return; // File not found; skip loading
        }

        employees.clear(); // Clear any existing data
        while (file)
        {
            EmployeeRecord emp;
            file >> emp.id;
            file.ignore(); // Ignore newline after ID
            getline(file, emp.name);
            getline(file, emp.position);
            file >> emp.salary;
            file.ignore(); // Ignore newline after salary
            employees.push_back(emp);
        }
        file.close();
    }

    // Add a new employee (private)
    void addEmployee(int id, const string &name, const string &position, double salary)
    {
        employees.push_back({id, name, position, salary});
        cout << "Employee added successfully!\n";
    }

    // Calculate payroll (private)
    void calculatePayroll() const
    {
        double totalPayroll = 0.0;
        for (const auto &emp : employees)
        {
            totalPayroll += emp.salary;
        }
        cout << "Total Payroll: " << totalPayroll << "\n";
    }

public:
    // Constructor to load data when program starts
    Employee()
    {
        loadEmployeesFromFile();
    }

    // Destructor to save data when program ends
    ~Employee()
    {
        saveEmployeesToFile();
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
        cout << "ID\tName\tPosition\t\tSalary\n";
        cout << "----------------------------------------------\n";
        for (const auto &emp : employees)
        {
            cout << emp.id << "\t" << emp.name << "\t\t" << emp.position << "\t\t" << emp.salary << "\n";
        }
    }

    // Search Employee by Name
    void searchByName(const string &name) const
    {
        bool found = false;
        cout << "Search Results:\n";
        cout << "ID\tName\t\tSalary\n";
        cout << "-----------------------------------\n";
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
            cout << "No employee found with name containing " << name << endl;
        }
    }

    // Friend Function for admin access
    friend void employeeAdminPanel(Employee &employeeManager);

    void employeeAdminPanel(Employee &employeeManager)
    {
        int adminChoice;
        do
        {
            cout << "\n--- Employee Admin Panel ---\n";
            cout << "1. Add Employee\n";
            cout << "2. Calculate Payroll\n";
            cout << "3. Delete Employee by ID\n";
            cout << "4. Search Employee by Name\n";
            cout << "5. Exit Admin Panel\n";
            cout << "Enter your choice: ";
            cin >> adminChoice;

            switch (adminChoice)
            {
            case 1:
            {
                int id;
                string name, position;
                double salary;
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Position: ";
                getline(cin, position);
                cout << "Enter Salary: ";
                cin >> salary;
                employeeManager.addEmployee(id, name, position, salary);
                break;
            }
            case 2:
                employeeManager.calculatePayroll();
                break;

            case 3:
            {
                int id;
                cout << "Enter Employee ID to Delete: ";
                cin >> id;
                employeeManager.deleteEmployee(id);
                break;
            }
            case 4:
            {
                string name;
                cout << "Enter Name or Part of Name to Search: ";
                cin.ignore();
                getline(cin, name);
                employeeManager.searchByName(name);
                break;
            }
            case 5:
                cout << "Exiting Admin Panel.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } while (adminChoice != 5);
    }
};

// Customer Class
class Customer
{
public:
    int booking_id;
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

    void displayRoom()
    {
        cout << "\nRoom Number: " << roomNumber;
        cout << "\nAC/Non-AC: " << ac;
        cout << "\nComfort: " << type;
        cout << "\nSize: " << size;
        cout << "\nRent: " << rent << endl;
    }
};

// Hotel Class
class Hotel
{
private:
    Room rooms[MAX];
    int count; // Number of rooms
    const string employeeFile = "Customer_data.txt";

    void saveCustomerData()
    {
        ofstream file(employeeFile);
        if (!file)
        {
            cout << "Error: Unable to save customer data.\n";
            return;
        }
        for (int i = 0; i < count; i++)
        {
            if (rooms[i].status == 1) // Only save booked rooms
            {
                file << rooms[i].roomNumber << "\n";
                file << rooms[i].cust.booking_id << "\n";
                file << rooms[i].cust.name << "\n";
                file << rooms[i].cust.address << "\n";
                file << rooms[i].cust.phone << "\n";
                file << rooms[i].cust.from_date << "\n";
                file << rooms[i].cust.to_date << "\n";
                file << rooms[i].cust.payment_advance << "\n";
            }
        }
        file.close();
    }

    // Load customer data from file
    void loadCustomerData()
    {
        ifstream file(employeeFile);
        if (!file)
        {
            cout << "No existing customer data found.\n";
            return;
        }
        while (file)
        {
            Room room;
            Customer cust;

            file >> room.roomNumber;
            if (file.eof())
                break; // Prevent reading garbage at the end
            file >> cust.booking_id;
            file.ignore();
            file.getline(cust.name, 100);
            file.getline(cust.address, 100);
            file.getline(cust.phone, 15);
            file.getline(cust.from_date, 20);
            file.getline(cust.to_date, 20);
            file >> cust.payment_advance;

            room.cust = cust;
            room.status = 1; // Mark room as booked
            rooms[count++] = room;
        }
        file.close();
    }

public:
    Hotel() : count(0)
    {
        loadCustomerData();
    }
    ~Hotel()
    {
        saveCustomerData();
    }

    Room addRoom(int roomNo)
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
        rooms[count++] = room;
        cout << "Room added successfully!\n";
        return room;
    }

    void searchRoom(int roomno)
    {
        for (int i = 0; i < MAX; i++)
        {
            if (rooms[i].roomNumber == roomno)
            {
                cout << "\nRoom Details:\n";
                displayRoom(rooms[i].roomNumber);
                cout << (rooms[i].status ? "Room is Reserved\n" : "Room is Available\n");
                return;
            }
        }
        cout << "Room not found!\n";
    }

    void displayRoom(int roomNo)
    {
        for (int i = 0; i < count; i++)
        {
            if (rooms[i].roomNumber == roomNo)
            {
                cout << "\nRoom Details:";
                cout << "\nRoom Number: " << rooms[i].roomNumber;
                cout << "\nAC/Non-AC: " << rooms[i].ac;
                cout << "\nComfort: " << rooms[i].type;
                cout << "\nSize: " << rooms[i].size;
                cout << "\nRent: " << rooms[i].rent;
                cout << "\nStatus: " << (rooms[i].status == 0 ? "Available" : "Reserved") << endl;
                return;
            }
        }
        cout << "Room not found!\n";
    }

    void getAvailRooms()
    {
        cout << "\nAvailable Rooms:\n";
        for (int i = 0; i < count; i++)
        {
            if (rooms[i].status == 0)
            {
                displayRoom(rooms[i].roomNumber);
                cout << "----------------------\n";
            }
        }
    }

    void searchCustomer(const char *pname)
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

    void checkIn()
    {
        int roomNo, found = 0;
        cout << "Enter Room Number: ";
        cin >> roomNo;

        for (int i = 0; i < count; i++)
        {
            if (rooms[i].roomNumber == roomNo)
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

    void checkOut(int roomNo)
    {
        for (int i = 0; i < count; i++)
        {
            if (rooms[i].roomNumber == roomNo)
            {
                if (rooms[i].status == 1)
                {
                    int days;
                    cout << "Enter Number of Days Stayed: ";
                    cin >> days;

                    float bill = days * rooms[i].rent;
                    cout << "\nTotal Bill: " << bill;
                    cout << "\nAdvance Paid: " << rooms[i].cust.payment_advance;
                    cout << "\nRemaining Payment: " << bill - rooms[i].cust.payment_advance << endl;

                    rooms[i].status = 0; // Mark room as available
                    return;
                }
            }
        }

        cout << "Room not found or already vacant!\n";
    }

    void guestSummaryReport()
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
};

class Restaurant
{
private:
    struct MenuItem
    {
        string name;  // Dish name
        double price; // Dish price
        int quantity; // Available quantity in inventory
    };

    vector<MenuItem> menu;                           // List of menu items
    double totalSales;                               // Total sales of the day
    const string menuFile = "restaurant_menu.txt";   // File to save/load menu
    const string salesFile = "restaurant_sales.txt"; // File to save/load total sales

    // Save menu and inventory to file
    void saveMenuToFile()
    {
        ofstream file(menuFile);
        if (!file)
        {
            cout << "Error: Unable to save menu data.\n";
            return;
        }

        for (const auto &item : menu)
        {
            file << item.name << "\n"
                 << item.price << "\n"
                 << item.quantity << "\n";
        }
        file.close();
    }

    // Load menu and inventory from file
    void loadMenuFromFile()
    {
        ifstream file(menuFile);
        if (!file)
        {
            cout << "No existing menu data found.\n";
            return;
        }

        menu.clear(); // Clear existing menu data
        while (file)
        {
            MenuItem item;
            getline(file, item.name);
            if (file.eof())
                break; // Prevent reading garbage at the end
            file >> item.price >> item.quantity;
            file.ignore(); // Ignore newline after quantity
            menu.push_back(item);
        }
        file.close();
    }

    // Save total sales to file
    void saveSalesToFile()
    {
        ofstream file(salesFile);
        if (!file)
        {
            cout << "Error: Unable to save sales data.\n";
            return;
        }
        file << totalSales;
        file.close();
    }

    // Load total sales from file
    void loadSalesFromFile()
    {
        ifstream file(salesFile);
        if (!file)
        {
            totalSales = 0.0; // Default total sales
            return;
        }
        file >> totalSales;
        file.close();
    }

    // Add menu item (private method, only accessible by admin)
    void addMenuItem(const string &name, double price, int quantity)
    {
        menu.push_back({name, price, quantity});
        cout << "Menu item added successfully!\n";
    }

    // Display total sales (private method, only accessible by admin)
    void displayTotalSales() const
    {
        cout << "Total Sales of the Day: " << totalSales << "\n";
    }

public:
    // Constructor to load data when program starts
    Restaurant()
    {
        loadMenuFromFile();
        loadSalesFromFile();
    }

    // Destructor to save data when program ends
    ~Restaurant()
    {
        saveMenuToFile();
        saveSalesToFile();
    }

    // Add menu item
    void addMenuItem(const string &name, double price, int quantity)
    {
        menu.push_back({name, price, quantity});
        cout << "Menu item added successfully!\n";
    }

    // Display menu
    void displayMenu() const
    {
        if (menu.empty())
        {
            cout << "Menu is empty.\n";
            return;
        }
        cout << "Menu:\n";
        cout << "Name\t\tPrice\t\tQuantity\n";
        cout << "---------------------------------------\n";
        for (const auto &item : menu)
        {
            cout << item.name << "\t\t" << item.price << "\t\t" << item.quantity << "\n";
        }
    }

    // Order food
    void orderFood(const string &dishName, int quantity)
    {
        for (auto &item : menu)
        {
            if (item.name == dishName)
            {
                if (item.quantity >= quantity)
                {
                    double cost = item.price * quantity;
                    item.quantity -= quantity; // Reduce stock
                    totalSales += cost;        // Update total sales
                    cout << "Order successful! Total cost: " << cost << "\n";
                    return;
                }
                else
                {
                    cout << "Insufficient stock for " << dishName << "!\n";
                    return;
                }
            }
        }
        cout << "Dish " << dishName << " not found in the menu.\n";
    }

    // Friend Function for Administrative access
    friend void adminPanel(Restaurant &restaurant);

    void adminPanel(Restaurant &restaurant)
    {
        int adminChoice;
        do
        {
            cout << "\n--- Restaurant Admin Panel ---\n";
            cout << "1. Add Menu Item\n";
            cout << "2. Display Total Sales\n";
            cout << "3. Exit Admin Panel\n";
            cout << "Enter your choice: ";
            cin >> adminChoice;

            switch (adminChoice)
            {
            case 1:
            {
                string name;
                double price;
                int quantity;
                cout << "Enter Dish Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Quantity: ";
                cin >> quantity;
                restaurant.addMenuItem(name, price, quantity);
                break;
            }
            case 2:
                restaurant.displayTotalSales();
                break;

            case 3:
                cout << "Exiting Admin Panel.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } while (adminChoice != 3);
    }

    // Display total sales
    void displayTotalSales() const
    {
        cout << "Total Sales of the Day: " << totalSales << "\n";
    }
};

// Main Function
int main()
{
    Employee empManager;
    Hotel hotelManager;
    Restaurant restaurantManager;

    int mainChoice;

    do
    {
        cout << "\n--- Hotel Management System ---\n";
        cout << "1. Employee Management\n";
        cout << "2. Hotel Management\n";
        cout << "3. Restaurant Management\n";
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
                    string name, position;
                    double salary;
                    cout << "Enter Employee ID: ";
                    cin >> id;
                    cout << "Enter Employee Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout<<"Enter Employee Position: ";
                    cin.ignore();
                    getline(cin,position);
                    cout << "Enter Employee Salary: ";
                    cin >> salary;
                    empManager.addEmployee(id, name, position, salary);
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
            } while (empChoice != 5);
            break;
        }
        case 2:
        {
            int hotelChoice;
            do
            {
                cout << "\n--- Hotel Management ---\n";
                cout << "1. Add Room\n"; //
                cout << "2. Search Room\n";
                cout << "3. Display Room\n";
                cout << "4. Get Available Rooms\n";  //
                cout << "5. Search Customer\n";      //
                cout << "6. Check In\n";             //
                cout << "7. Check Out\n";            //
                cout << "8. Guest Summary Report\n"; //
                cout << "9. Back to Main Menu\n";    //
                cout << "Enter your choice: ";
                cin >> hotelChoice;

                switch (hotelChoice)
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
                {
                    int roomNo;
                    cout << "Enter Room Number to Search: ";
                    cin >> roomNo;
                    hotelManager.searchRoom(roomNo);
                    break;
                }
                case 3:
                {
                    int roomNo;
                    cout << "Enter Room Number to Display: ";
                    cin >> roomNo;
                    hotelManager.displayRoom(roomNo);
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
                    hotelManager.checkIn();
                    break;
                case 7:
                {
                    int roomNo;
                    cout << "Enter Room Number to Check Out: ";
                    cin >> roomNo;
                    hotelManager.checkOut(roomNo);
                    break;
                }
                case 8:
                    hotelManager.guestSummaryReport();
                    break;
                case 9:
                    cout << "Returning to Main Menu.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (hotelChoice != 9);
            break;
        }
        case 3:
        {
            int restaurantChoice;
            do
            {
                cout << "\n--- Restaurant Management ---\n";
                cout << "1. Display Menu\n";
                cout << "2. Order Food\n";
                cout << "3. Admin Panel (Restricted)\n";
                cout << "4. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> restaurantChoice;

                switch (restaurantChoice)
                {
                case 1:
                    restaurantManager.displayMenu();
                    break;

                case 2:
                {
                    string dishName;
                    int quantity;
                    cout << "Enter Dish Name to Order: ";
                    cin.ignore();
                    getline(cin, dishName);
                    cout << "Enter Quantity: ";
                    cin >> quantity;
                    restaurantManager.orderFood(dishName, quantity);
                    break;
                }
                case 3:
                    adminPanel(restaurantManager); // Restricted Access
                    break;

                case 4:
                    cout << "Returning to Main Menu.\n";
                    break;

                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (restaurantChoice != 4);
            break;
        }
        case 4:
            cout << "Exiting Program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (mainChoice != 4);

    return 0;
}
