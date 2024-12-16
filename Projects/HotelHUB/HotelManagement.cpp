#include <bits/stdc++.h>
#define MAX 100
using namespace std;

// ---------- Global Declarations ----------
int Qrooms = 0, Qpasta = 0, Qburger = 0, Qnoodles = 0, Qshake = 0, Qchicken = 0;                               // Available quantities
int Srooms = 0, Spasta = 0, Sburger = 0, Snoodles = 0, Sshake = 0, Schicken = 0;                               // Sold quantities
int Total_rooms = 0, Total_pasta = 0, Total_burger = 0, Total_noodles = 0, Total_shake = 0, Total_chicken = 0; // Total revenue

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
};

class Room
{
public:
    char ac, type, size;
    int roomNumber, rent, status;
    Customer cust;

    Room addRoom(int);
    void searchRoom(int);
    void displayRoom(Room);
};

class Hotel : protected Room 
{
public:
    void checkIn();
    void getAvailRooms();
    void searchCustomer(char *);
    void checkOut();
    void guestSummaryReport();
};

class Restaurant
{
    
}

Room rooms[MAX];
int count = 0;

Room Room ::addRoom(int roomNo)
{
    Room room;
    room.roomNumber = roomNo;
    cout << "\n Type AC/Non-AC (A/N): ";
    cin >> room.ac;
    cout << "\n Type Comfort (S/N): ";
    cin >> room.type;
    cout << "\n Type Size (K/Q/S): ";
    cin >> room.size;
    cout << "\n Daily rent: ";
    cin >> room.rent;
    room.status = 0; // Mark Room as available
    cout << "\n Room added successfully!\n";
    return room;
}

void Room::searchRoom(int roomno)
{
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].roomNumber == roomno)
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
    cout << "\nSize: " << room.stype;
    cout << "\nRent: " << room.rent << endl;
}

// ---------- Hotel Management Methods ----------
void Hotel::checkIn()
{
    int roomno, found = 0;
    cout << "Enter Room Number: ";
    cin >> rno;

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
            cin >> rooms[i].cust.name;
            cout << "Enter Address: ";
            cin >> rooms[i].cust.address;
            cout << "Enter Phone: ";
            cin >> rooms[i].cust.phone;
            cout << "Enter From Date: ";
            cin >> rooms[i].cust.from_date;
            cout << "Enter To Date: ";
            cin >> rooms[i].cust.to_date;
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
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].status == 0)
        {
            displayRoom(rooms[i]);
            cout << "----------------------\n";
        }
    }
}

void Hotel::searchCustomer(char *pname)
{
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].status == 1 && strcmp(rooms[i].cust.name, pname) == 0)
        {
            cout << "Customer Name: " << rooms[i].cust.name;
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
            cout << "Total Bill: " << bill;
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
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].status == 1)
        {
            cout << "Customer Name: " << rooms[i].cust.name;
            cout << "\nRoom Number: " << rooms[i].roomNumber;
            cout << "\n----------------------\n";
        }
    }
}

void manageRestaurant()
{
    int choice, quant;
    while (true)
    {
        cout << "\n1. Rooms\n2. Pasta\n3. Burger\n4. Noodles\n5. Shake\n6. Chicken-Roll\n7. Sales Summary\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 8)
            break;

        switch (choice)
        {
        case 1:
            // Handling room booking
            cout << "\n\n Enter the number of rooms you want: ";
            cin >> quant;

            // Check if requested quantity is available
            if (Qrooms - Srooms >= quant)
            {
                Srooms += quant;             // Update the rooms sold
                Total_rooms += quant * 1200; // Calculate total price (1200 per room)
                cout << "\n\n\t\t" << quant << " room/rooms have been alloted to you! " << endl;
            }

            else
            {
                // If requested quantity is not available
                cout << "\n\tOnly " << Qrooms - Srooms << " Rooms remaining in hotel " << endl;
            }
            break;

        case 2:
            // Handling pasta order
            cout << "\n\n Enter Pasta Quantity: ";
            cin >> quant;

            if (Qpasta - Spasta >= quant)
            {
                Spasta += quant;            // Update pasta sold
                Total_pasta += quant * 250; // Calculate total price (250 per pasta)
                cout << "\n\n\t\t" << quant << " Pasta is the order! " << endl;
            }

            else
            {
                cout << "\n\tOnly " << Qpasta - Spasta << " Pasta remaining in hotel " << endl;
            }
            break;

        case 3:
            // Handling burger order
            cout << "\n\n Enter Burger Quantity: ";
            cin >> quant;

            if (Qburger - Sburger >= quant)
            {
                Sburger += quant;            // Update burgers sold
                Total_burger += quant * 100; // Calculate total price (100 per burger)
                cout << "\n\n\t\t" << quant << " Burger is the order! ";
            }

            else
            {
                cout << "\n\tOnly " << Qburger - Sburger << " Burger remaining in hotel " << endl;
            }
            break;

        case 4:
            // Handling noodles order
            cout << "\n\n Enter Noodles Quantity: ";
            cin >> quant;

            if (Qnoodles - Snoodles >= quant)
            {
                Snoodles += quant;            // Update noodles sold
                Total_noodles += quant * 140; //// Calculate total price (140 per noodles)
                cout << "\n\n\t\t" << quant << " Noodles is the order! " << endl;
            }

            else
            {
                cout << "\n\tOnly " << Qnoodles - Snoodles << " Noodles remaining in hotel " << endl;
            }
            break;

        case 5:
            // Handling shake order
            cout << "\n\n Enter Shake Quantity: ";
            cin >> quant;

            if (Qshake - Sshake >= quant)
            {
                Sshake += quant;            // Update shakes sold
                Total_shake += quant * 120; // Calculate total price (120 per shake)
                cout << "\n\n\t\t" << quant << " Shake is the order! " << endl;
            }

            else
            {
                cout << "\n\t Only " << Qshake - Sshake << " Shake remaining in hotel " << endl;
            }
            break;

        case 6:
            // Handling chicken-roll order
            cout << "\n\n Enter Chicken-Roll Quantity: ";
            cin >> quant;

            if (Qchicken - Schicken >= quant)
            {
                Schicken += quant;            // Update chicken-rolls sold
                Total_chicken += quant * 150; // Calculate total price (150 per chicken-roll)
                cout << "\n\n\t\t" << quant << " Chicken-Roll is the order! " << endl;
            }

            else
            {
                cout << "\n\t Only " << Qchicken - Sburger << " Chicken remaining in hotel " << endl;
            }
            break;

            // Add similar cases for burger, noodles, shakes, and chicken-roll

        case 7:
            cout << "\nTotal Rooms Revenue: " << Total_rooms;
            cout << "\nTotal Pasta Revenue: " << Total_pasta << endl;
            cout << "\nTotal Burger Revenue: " << Total_burger << endl;
            cout << "\nTotal Noodles Revenue: " << Total_noodles << endl;
            cout << "\nTotal Shake Revenue: " << Total_shake << endl;
            cout << "\nTotal Chicken-Roll Revenue: " << Total_chicken << endl;
            break;

        case 8:
            // Exit the program
            cout << "Thank You for Visiting us! " << endl;
            exit(0);

        default:
            cout << "Invalid Choice!\n";
        }
    }
}

// ---------- Main Function ----------
int main()
{
    Hotel hm;
    int choice;

    while (true)
    {
        cout << "\n1. Manage Restaurant\n2. Manage Rooms\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3)
            break;

        switch (choice)
        {
        case 1:
            manageRestaurant();
            break;

        case 2:
            hm.getAvailRoom();
            break;

        default:
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}