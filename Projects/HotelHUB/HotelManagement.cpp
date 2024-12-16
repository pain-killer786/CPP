#include <iostream>
#include <string.h>
#define MAX 1000
using namespace std;

// ---------- Global Declarations ----------
int Qrooms = 0, Qpasta = 0, Qburger = 0, Qnoodles = 0, Qshake = 0, Qchicken = 0;  // Available quantities
int Srooms = 0, Spasta = 0, Sburger = 0, Snoodles = 0, Sshake = 0, Schicken = 0;  // Sold quantities
int Total_rooms = 0, Total_pasta = 0, Total_burger = 0, Total_noodles = 0, Total_shake = 0, Total_chicken = 0;  // Total revenue

// ---------- Customer Class ----------
class Customer {
public:
    char name[100];
    char address[200];
    char phone[15];
    char from_date[20];
    char to_date[20];
    float payment_advance;
    int booking_id;
};

// ---------- Room Class ----------
class Room {
public:
    char ac, type, stype;
    int roomNumber, rent, status;
    Customer cust;

    Room addRoom(int);
    void searchRoom(int);
    void displayRoom(Room);
};

// ---------- Hotel Management Class ----------
class HotelMgnt : protected Room {
public:
    void checkIn();
    void getAvailRoom();
    void searchCustomer(char*);
    void checkOut(int);
    void guestSummaryReport();
};

// Global Room Array
Room rooms[MAX];
int count = 0;

// ---------- Room Methods ----------
Room Room::addRoom(int rno) {
    Room room;
    room.roomNumber = rno;
    cout << "\nType AC/Non-AC (A/N): ";
    cin >> room.ac;
    cout << "Type Comfort (S/N): ";
    cin >> room.type;
    cout << "Type Size (B/S): ";
    cin >> room.stype;
    cout << "Daily Rent: ";
    cin >> room.rent;
    room.status = 0;  // Mark room as available
    cout << "\nRoom Added Successfully!\n";
    return room;
}

void Room::searchRoom(int rno) {
    for (int i = 0; i < count; i++) {
        if (rooms[i].roomNumber == rno) {
            cout << "\nRoom Details:\n";
            displayRoom(rooms[i]);
            cout << (rooms[i].status ? "Room is Reserved\n" : "Room is Available\n");
            return;
        }
    }
    cout << "Room not found!\n";
}

void Room::displayRoom(Room room) {
    cout << "\nRoom Number: " << room.roomNumber;
    cout << "\nAC/Non-AC: " << room.ac;
    cout << "\nComfort: " << room.type;
    cout << "\nSize: " << room.stype;
    cout << "\nRent: " << room.rent << endl;
}

// ---------- Hotel Management Methods ----------
void HotelMgnt::checkIn() {
    int rno, found = 0;
    cout << "Enter Room Number: ";
    cin >> rno;

    for (int i = 0; i < count; i++) {
        if (rooms[i].roomNumber == rno) {
            found = 1;
            if (rooms[i].status == 1) {
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

            rooms[i].status = 1;  // Mark room as booked
            cout << "Customer Checked-in Successfully!\n";
            return;
        }
    }

    if (!found)
        cout << "Room not found!\n";
}

void HotelMgnt::getAvailRoom() {
    for (int i = 0; i < count; i++) {
        if (rooms[i].status == 0) {
            displayRoom(rooms[i]);
            cout << "----------------------\n";
        }
    }
}

void HotelMgnt::searchCustomer(char* pname) {
    for (int i = 0; i < count; i++) {
        if (rooms[i].status == 1 && strcmp(rooms[i].cust.name, pname) == 0) {
            cout << "Customer Name: " << rooms[i].cust.name;
            cout << "\nRoom Number: " << rooms[i].roomNumber << endl;
            return;
        }
    }
    cout << "Customer not found!\n";
}

void HotelMgnt::checkOut(int rno) {
    for (int i = 0; i < count; i++) {
        if (rooms[i].status == 1 && rooms[i].roomNumber == rno) {
            int days;
            cout << "Enter Number of Days Stayed: ";
            cin >> days;

            float bill = days * rooms[i].rent;
            cout << "Total Bill: " << bill;
            cout << "\nAdvance Paid: " << rooms[i].cust.payment_advance;
            cout << "\nRemaining Payment: " << (bill - rooms[i].cust.payment_advance) << endl;

            rooms[i].status = 0;  // Mark room as available
            return;
        }
    }
    cout << "Room not found or already vacant!\n";
}

void HotelMgnt::guestSummaryReport() {
    for (int i = 0; i < count; i++) {
        if (rooms[i].status == 1) {
            cout << "Customer Name: " << rooms[i].cust.name;
            cout << "\nRoom Number: " << rooms[i].roomNumber;
            cout << "\n----------------------\n";
        }
    }
}

// ---------- Item Management Functions ----------
void manageItems() {
    int choice, quant;
    while (true) {
        cout << "\n1. Rooms\n2. Pasta\n3. Burger\n4. Noodles\n5. Shake\n6. Chicken-Roll\n7. Sales Summary\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 8)
            break;

        switch (choice) {
            case 1:
                cout << "Enter Rooms Quantity: ";
                cin >> quant;
                if (Qrooms - Srooms >= quant) {
                    Srooms += quant;
                    Total_rooms += quant * 1200;
                } else
                    cout << "Not enough rooms available!\n";
                break;

            case 2:
                cout << "Enter Pasta Quantity: ";
                cin >> quant;
                if (Qpasta - Spasta >= quant) {
                    Spasta += quant;
                    Total_pasta += quant * 250;
                } else
                    cout << "Not enough pasta available!\n";
                break;

            // Add similar cases for burger, noodles, shakes, and chicken-roll

            case 7:
                cout << "\nTotal Rooms Revenue: " << Total_rooms;
                cout << "\nTotal Pasta Revenue: " << Total_pasta << endl;
                break;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}

// ---------- Main Function ----------
int main() {
    HotelMgnt hm;
    int choice;

    while (true) {
        cout << "\n1. Manage Items\n2. Manage Rooms\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3)
            break;

        switch (choice) {
            case 1:
                manageItems();
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