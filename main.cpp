#include <iostream>
#include <windows.h> 
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

const int TOTAL_ROOMS = 100;
const int MAX_BOOKINGS = 100;

void typeWriter(string text, int speed) {
    for (char c : text) {
        cout << c << flush;
        Sleep(speed);
    }
}

void displayWelcome(){
    cout<<"====================================\n";
    cout<<"  WELCOME TO HOTEL BOOKING SYSTEM   \n";
    cout<<"====================================\n";

    Sleep(1000);
    typeWriter("\nLoading system, please wait...\n", 60);
}

void displayMenu(){
    cout<< endl;
    cout<< "======== HOTEL MENU ========\n";
    Sleep(300);
    cout<< "1. View Hotel Information\n";
    Sleep(300);
    cout<< "2. View Available Rooms\n";
    Sleep(300);
    cout<< "3. Book a Room\n";
    Sleep(300);
    cout<< "4. Cancel Booking\n";
    Sleep(300);
    cout<< "5. View Booking Details\n";
    Sleep(300);
    cout<< "6. Exit\n";
    Sleep(300);
    cout<< "============================\n";
}

void viewHotelInfo(){
    cout<< "----------------------------\n";
    cout<< "  HOTEL PROFILE INFORMATION \n";
    cout<< "----------------------------\n";
    cout<< endl;
    cout<< "Hotel Name: Grand Plaza Hotel\n";
    cout<< "Address: 123 Main Street, Cityville\n";
    cout<< "Contact: (+63) 912 345 6789\n";
    cout<< "Email: info@grandplazahotel.com\n";
    cout<< endl;
    cout<< "Room Types:\n";
    cout<< "1.Single Room\n";
    cout<< "2.Double Room\n";
    cout<< "3.Twin Room\n";
    cout<< "4.Suite Room\n";
    cout<< "5.Deluxe Room\n";
    cout<< endl;
    cout<< "Check-in: 2:00 PM | Check-out: 12:00 PM\n";
    cout<< "Amenities: Free WiFi, Swimming Pool, Gym, Restaurant\n";
    cout<< endl;
    cout<< "Press Enter to return to Main Menu...\n";
    cin.ignore();
    cin.get();
}

struct Room {
    int roomNo;
    string roomType;
    int capacity;
    bool isAvailable; 
};

Room hotel[TOTAL_ROOMS];

void initializeRooms() {
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        hotel[i].roomNo = i + 1;
        hotel[i].isAvailable = true;

        if (i < 20) {
            hotel[i].roomType = "Single";
            hotel[i].capacity = 2;
        } else if (i < 40) {
            hotel[i].roomType = "Double";
            hotel[i].capacity = 2;
        } else if(i < 60){
            hotel[i].roomType = "Twin";
            hotel[i].capacity = 2;
        }else if(i < 80){
            hotel[i].roomType = "Suite";
            hotel[i].capacity = 4;
        }else{
            hotel[i].roomType = "Deluxe";
            hotel[i].capacity = 6;
        }
    }
}

void viewAvailableRooms() {
    int choice;
    do {
        cout << "\n===== VIEW AVAILABLE ROOMS =====\n";
        cout << "Choose Room Type to View:\n";
        cout << "1. All\n";
        cout << "2. Single\n";
        cout << "3. Double\n";
        cout << "4. Twin\n";
        cout << "5. Suite\n";
        cout << "6. Deluxe\n";
        cout << "7. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cout << endl;

        switch(choice) {
            case 1:
                cout<< "\t\t**All Rooms**\n";
                cout<< endl;
                cout <<left
                << setw(10) << "Room No." << setw(10) << "Room Type" << setw(10) << "Capacity" << setw(15) << "Availability"
                <<endl;
                for(int i=0; i<TOTAL_ROOMS; i++) {
                    cout << left
                    << setw(10) << hotel[i].roomNo  
                    << setw(10) << hotel[i].roomType
                    << setw(10) << hotel[i].capacity
                    << setw(15) << (hotel[i].isAvailable ? "Available" : "Reserved") << endl;
                }
                break;
            case 2:
                cout<< "\t\t**Single Rooms**\n";
                cout<< endl;
                cout<< left
                << setw(10) << "Room No." << setw(10) << "Room Type" << setw(10) << "Capacity" << setw(15) << "Availability"
                <<endl;
                for(int i=0; i<TOTAL_ROOMS; i++) {
                    if(hotel[i].roomType == "Single") {
                        cout << left
                        << setw(10) << hotel[i].roomNo
                        << setw(10) << hotel[i].roomType 
                        << setw(10) << hotel[i].capacity
                        << setw(15) << (hotel[i].isAvailable ? "Available" : "Reserved") << endl;
                    }
                }
                break;
            case 3:
                cout<< "\t\t**Double Rooms**\n";
                cout<< endl;
                cout<< left
                << setw(10) << "Room No." << setw(10) << "Room Type" << setw(10) << "Capacity" << setw(15) << "Availability"
                <<endl;
                for(int i=0; i<TOTAL_ROOMS; i++) {
                    if(hotel[i].roomType == "Double") {
                        cout << left
                        << setw(10) << hotel[i].roomNo
                        << setw(10) << hotel[i].roomType 
                        << setw(10) << hotel[i].capacity
                        << setw(15) << (hotel[i].isAvailable ? "Available" : "Reserved") << endl;
                    }
                }
                break;
            case 4:
                cout<< "**\t\tTwin Rooms**\n";
                cout<< endl;
                cout<< left
                << setw(10) << "Room No." << setw(10) << "Room Type" << setw(10) << "Capacity" << setw(15) << "Availability"
                <<endl;
                for(int i=0; i<TOTAL_ROOMS; i++) {
                    if(hotel[i].roomType == "Twin") {
                        cout << left
                        << setw(10) << hotel[i].roomNo
                        << setw(10) << hotel[i].roomType 
                        << setw(10) << hotel[i].capacity
                        << setw(15) << (hotel[i].isAvailable ? "Available" : "Reserved") << endl;
                    }
                }
                break;
            case 5:
                cout<< "\t\t**Suite Rooms**\n";
                cout<< endl;
                cout<< left
                << setw(10) << "Room No." << setw(10) << "Room Type" << setw(10) << "Capacity" << setw(15) << "Availability"
                <<endl;
                for(int i=0; i<TOTAL_ROOMS; i++) {
                    if(hotel[i].roomType == "Suite") {
                        cout << left
                        << setw(10) << hotel[i].roomNo
                        << setw(10) << hotel[i].roomType 
                        << setw(10) << hotel[i].capacity
                        << setw(15) << (hotel[i].isAvailable ? "Available" : "Reserved") << endl;
                    }
                }
                break;
            case 6:
                cout<< "\t\t**Deluxe Rooms**\n";
                cout<< endl;
                cout<< left
                << setw(10) << "Room No." << setw(10) << "Room Type" << setw(10) << "Capacity" << setw(15) << "Availability"
                <<endl;
                for(int i=0; i<TOTAL_ROOMS; i++) {
                    if(hotel[i].roomType == "Deluxe") {
                        cout << left
                        << setw(10) << hotel[i].roomNo
                        << setw(10) << hotel[i].roomType
                        << setw(10) << hotel[i].capacity
                        << setw(15) << (hotel[i].isAvailable ? "Available" : "Reserved") << endl;
                    }
                }
                break;
            case 7:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        if(choice >=1 && choice <=7) {
            cout << "\nPress Enter to return to the Room Type Menu...";
            cin.ignore(); 
            cin.get();    
        }

    } while(choice != 7);
}

struct Booking {
    string guestName;
    string contactNumber;
    string guestEmail;
    int numAdults;
    int numKids;
    int roomNo;
    int nights;
    double totalAmount;
    string checkInDate;
    string checkOutDate;
    string roomType;
};

Booking bookings[MAX_BOOKINGS];
int bookingCount = 0; 

string calculateCheckOut(int day, int month, int year, int nights) {
    tm tm_in = {};
    tm_in.tm_mday = day;
    tm_in.tm_mon = month - 1;    
    tm_in.tm_year = year - 1900; 

    time_t t_in = mktime(&tm_in);      
    t_in += nights * 24 * 60 * 60;     

    tm* tm_out = localtime(&t_in);     

    stringstream out;
    out << setw(2) << setfill('0') << tm_out->tm_mday << "/"
        << setw(2) << setfill('0') << tm_out->tm_mon + 1 << "/"
        << tm_out->tm_year + 1900;
    return out.str();
}


void bookRoom() {
    string guestName, contactNumber, guestEmail;
    string checkInDate, checkOutDate;
    int numAdults, numKids;
    int nights;
    double rate = 0.0;
    int roomIndex = -1;
    int roomTypeChoice;

    cout << "\nChoose Room Type:\n";
    cout << "1. Single 1 adult - P1400/night\n";
    cout << "2. Double 2 adults - P2300/night\n";
    cout << "3. Twin   2 adults - P2500/night\n";
    cout << "4. Suite  2 adults + 2 kids - P4500/night\n";
    cout << "5. Deluxe 2-3 adults + 1 kid - P6000/night\n";
    cout << "6. Back to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> roomTypeChoice;
    cin.ignore(); 

    string selectedType;
    if (roomTypeChoice == 1) selectedType = "Single";
    else if (roomTypeChoice == 2) selectedType = "Double";
    else if (roomTypeChoice == 3) selectedType = "Twin";
    else if (roomTypeChoice == 4) selectedType = "Suite";
    else if (roomTypeChoice == 5) selectedType = "Deluxe";
    else if (roomTypeChoice == 6) return;
    else {
        cout << "Invalid choice!\n";
        return;
    }

    for (int i = 0; i < TOTAL_ROOMS; i++) {
        if (hotel[i].roomType == selectedType && hotel[i].isAvailable) {
            roomIndex = i;
            break;
        }
    }

    if (roomIndex == -1) {
        cout << "Sorry, no available " << selectedType << " rooms.\n";
        return;
    }

    int roomNo = hotel[roomIndex].roomNo;

    cout << endl;
    cout << "Enter Number of Adults: ";
    cin >> numAdults;
    cout << "Enter Number of Kids: ";
    cin >> numKids;
    
    if(numAdults + numKids > hotel[roomIndex].capacity) {
        cout << "Number of guests exceeds room capacity. Please choose a different room type.\n";
        return;
    }
    cin.ignore();
    cout << "Enter Guest Name: ";
    getline(cin, guestName);
    cout << "Enter Contact Number: ";
    getline(cin, contactNumber);
    cout << "Enter Guest Email: ";
    getline(cin, guestEmail);
    

 

    cout << "Enter Check-in Date (dd/mm/yyyy): ";
    getline(cin, checkInDate);

    int day, month, year;
    char sep1, sep2;
    stringstream ss(checkInDate);
    ss >> day >> sep1 >> month >> sep2 >> year;

    tm tm_in = {};
    tm_in.tm_mday = day;
    tm_in.tm_mon = month - 1;
    tm_in.tm_year = year - 1900;
    time_t userTime = mktime(&tm_in);

    time_t now = time(0);
    tm* today = localtime(&now);
    today->tm_hour = 0; today->tm_min = 0; today->tm_sec = 0;
    time_t todayTime = mktime(today);

    if (userTime < todayTime) {
        cout << "Invalid check-in date! You can only book today or in the future.\n";
        return;
    }

    cout << "Enter Number of Nights: ";
    cin >> nights;

    if (selectedType == "Single") rate = 1400;
    else if (selectedType == "Double") rate = 2300;
    else if (selectedType == "Twin") rate = 2500;
    else if (selectedType == "Suite") rate = 4500;
    else if (selectedType == "Deluxe") rate = 6000;

    double totalAmount = rate * nights;
    checkOutDate = calculateCheckOut(day, month, year, nights);

    cout<< "Total Amount: P" << totalAmount << endl;

    double cash;
    do {
        cout << "Enter Cash Amount: P";
        cin >> cash;
        if (cash < totalAmount) {
            cout << "Insufficient cash! Please enter again.\n";
        }
    } while(cash < totalAmount);

    double change = cash - totalAmount;

    hotel[roomIndex].isAvailable = false;
    bookings[bookingCount++] = {guestName, contactNumber, guestEmail, numAdults, numKids, roomNo, nights, totalAmount, checkInDate, checkOutDate, selectedType};

    cout << "\nBooking Confirmed!\n";
    cout << "Room " << roomNo << " (" << selectedType << ") is now RESERVED for " << guestName << ".\n";

    time_t nowTime = time(0);
    tm* ltm = localtime(&nowTime);
    stringstream receiptID;
    receiptID << 1900 + ltm->tm_year
          << setw(2) << setfill('0') << ltm->tm_mon + 1
          << setw(2) << setfill('0') << ltm->tm_mday
          << "-R" << roomNo
          << "-" << setw(4) << setfill('0') << bookingCount;

    cout << "=================================================\n";
    cout << "               GRAND PLAZA HOTEL                 \n";
    cout << "         123 Main Street, Cityville, PH          \n";
    cout << "   (+63) 912-345-6789 |   info@grandplaza.com    \n";
    cout << "=================================================\n";
    cout << "                 OFFICIAL RECEIPT                \n";
    cout << "=================================================\n";
    cout << "Receipt ID   : " << receiptID.str() << "\n";
    cout << "Guest Name   : " << guestName << "\n";
    cout << "Contact No.  : " << contactNumber << "\n";
    cout << "Email        : " << guestEmail << "\n";
    cout << "-------------------------------------------------\n";
    cout << "Room Number  : " << roomNo << "\n";
    cout << "Room Type    : " << selectedType << "\n";
    cout << "Guests       : Adults " << numAdults << " | Kids " << numKids << "\n";
    cout << "-------------------------------------------------\n";
    cout << "Check-in     : " << checkInDate << "\n";
    cout << "Check-out    : " << checkOutDate << "\n";
    cout << "Nights       : " << nights << "\n";
    cout << "-------------------------------------------------\n";
    cout << "Rate/Night   : P" << rate << "\n";
    cout << "TOTAL PAID   : P" << totalAmount << "\n";
    cout << "Cash Given   : P" << cash << "\n";
    cout << "CHANGE       : P" << change << "\n";
    cout << "=================================================\n";
    cout << "        Thank you for staying with us!           \n";
    cout << "         We look forward to your return.         \n";
    cout << "=================================================\n";

    ofstream receiptFile("receipts.txt", ios::app);
    if (receiptFile.is_open()) {        
        time_t nowTime = time(0);
        tm* ltm = localtime(&nowTime);
        stringstream receiptID;
        receiptID << 1900 + ltm->tm_year
                  << setw(2) << setfill('0') << ltm->tm_mon + 1
                  << setw(2) << setfill('0') << ltm->tm_mday
                  << "-R" << roomNo
                  << "-" << setw(4) << setfill('0') << bookingCount;

        receiptFile << "----- Booking Receipt -----\n";
        receiptFile << "Receipt ID : " << receiptID.str() << "\n";  // ✅ Add here
        receiptFile << "Guest Name : " << guestName << "\n";
        receiptFile << "Contact No.: " << contactNumber << "\n";
        receiptFile << "Email      : " << guestEmail << "\n";
        receiptFile << "Room Number: " << roomNo << "\n";
        receiptFile << "Room Type  : " << selectedType << "\n";
        receiptFile << "Adults     : " << numAdults << " | Kids: " << numKids << "\n";
        receiptFile << "Check-in   : " << checkInDate << "\n";
        receiptFile << "Check-out  : " << checkOutDate << "\n";
        receiptFile << "Nights     : " << nights << "\n";
        receiptFile << "Rate/Night : P" << rate << "\n";
        receiptFile << "Total Paid : P" << totalAmount << "\n";
        receiptFile << "Cash Given : P" << cash << "\n";
        receiptFile << "Change     : P" << change << "\n";
        receiptFile << "-----------------------------\n\n";
        receiptFile.close();
    } else {
        cout << "Error saving receipt file!\n";
    }


    cout << "\nPress Enter to return to Main Menu...";
    cin.ignore();
    cin.get();

}

void cancelBooking() {
    int roomNo;
    cout << "Enter Room Number to Cancel: ";
    cin >> roomNo;

    int roomIndex = -1;
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        if (hotel[i].roomNo == roomNo) {
            roomIndex = i;
            break;
        }
    }

    if (roomIndex == -1) {
        cout << "Invalid Room Number!\n";
        return;
    }

    int bookingIndex = -1;
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].roomNo == roomNo) {
            bookingIndex = i;
            break;
        }
    }

    if (bookingIndex == -1) {
        cout << "No active booking found for Room " << roomNo << ".\n";
        return;
    }

    cout << "\nBooking Found!\n";
    cout << "Guest Name  : " << bookings[bookingIndex].guestName << endl;
    cout << "Room Number : " << bookings[bookingIndex].roomNo << endl;
    cout << "Room Type   : " << bookings[bookingIndex].roomType << " Room" << endl;
    cout << "Nights      : " << bookings[bookingIndex].nights << endl;
    cout << "Total Paid  : P" << bookings[bookingIndex].totalAmount << endl;

    cin.ignore();
    cout << "\nPress Enter to confirm cancellation...";
    cin.get();

    hotel[roomIndex].isAvailable = true;

    // ✅ store info before removing
    string cancelledGuest = bookings[bookingIndex].guestName;
    string cancelledRoomType = bookings[bookingIndex].roomType;
    int cancelledNights = bookings[bookingIndex].nights;
    double refundAmount = bookings[bookingIndex].totalAmount;

    // shift bookings
    for (int i = bookingIndex; i < bookingCount - 1; i++) {
        bookings[i] = bookings[i + 1];
    }
    bookingCount--;

    cout << "\nBooking for Room " << roomNo << " has been CANCELLED.\n";
    cout << "Refund Amount : P" << refundAmount << endl;
    cout << "Room " << roomNo << " is now AVAILABLE again.\n";

    // ✅ log cancellation after shifting
    ofstream cancelFile("cancellations.txt", ios::app);
    if (cancelFile.is_open()) {
        cancelFile << "----- Booking Cancelled -----\n";
        cancelFile << "Guest Name : " << cancelledGuest << "\n";
        cancelFile << "Room Number: " << roomNo << "\n";
        cancelFile << "Room Type  : " << cancelledRoomType << "\n";
        cancelFile << "Nights     : " << cancelledNights << "\n";
        cancelFile << "Refund     : P" << refundAmount << "\n";
        cancelFile << "-------------------------------\n\n";
        cancelFile.close();
    }

    cout << "\nPress Enter to return to Main Menu...";
    cin.get();
}


void viewBookingDetails() {
    if (bookingCount == 0) {
        cout << "\nNo active bookings.\n";
    } else {
        cout << "\n===== BOOKING DETAILS =====\n";
        cout << left 
             << setw(10) << "Room No." 
             << setw(20) << "Guest Name" 
             << setw(15) << "Contact" 
             << setw(35) << "Email"
             << setw(15) << "Room Type" 
             << setw(8) << "Nights" 
             << endl;

        cout << "-----------------------------------------------------------------------------------------------------\n";

        for (int i = 0; i < bookingCount; i++) {
            cout << left 
                 << setw(10) << bookings[i].roomNo
                 << setw(20) << bookings[i].guestName
                 << setw(15) << bookings[i].contactNumber
                 << setw(35) << bookings[i].guestEmail
                 << setw(15) << bookings[i].roomType
                 << setw(8) << bookings[i].nights
                 << endl;
        }
    }

    cout << "\nPress Enter to return to Main Menu...";
    cin.ignore();
    cin.get();
}


void saveBookingsToFile() {
    ofstream outFile("bookings.txt");
    if (!outFile) {
        cout << "Error opening file for saving!\n";
        return;
    }

    // Header for file
    outFile << "RoomNo|GuestName|Contact|Email|RoomType|Nights\n";

    for (int i = 0; i < bookingCount; i++) {
        outFile << bookings[i].roomNo << '|'
                << bookings[i].guestName << '|'
                << bookings[i].contactNumber << '|'
                << bookings[i].guestEmail << '|'
                << bookings[i].roomType << '|'
                << bookings[i].nights << '\n';
    }

    outFile.close();
}



void loadBookingsFromFile() {
    ifstream inFile("bookings.txt");
    if (!inFile) return;

    bookingCount = 0;
    string line;

    // Skip header
    if (!getline(inFile, line)) return;

    while (getline(inFile, line)) {
        if (line.empty()) continue; // skip blank lines

        stringstream ss(line);
        string roomNoStr, name, contact, email, roomType, nightsStr;

        if (!getline(ss, roomNoStr, '|')) continue;
        if (!getline(ss, name, '|')) continue;
        if (!getline(ss, contact, '|')) continue;
        if (!getline(ss, email, '|')) continue;
        if (!getline(ss, roomType, '|')) continue;
        if (!getline(ss, nightsStr)) continue;

        // Skip invalid or non-numeric roomNo/nights
        try {
            bookings[bookingCount].roomNo = stoi(roomNoStr);
            bookings[bookingCount].guestName = name;
            bookings[bookingCount].contactNumber = contact;
            bookings[bookingCount].guestEmail = email;
            bookings[bookingCount].roomType = roomType;
            bookings[bookingCount].nights = stoi(nightsStr);

             int roomNum = bookings[bookingCount].roomNo;
            for (int i = 0; i < TOTAL_ROOMS; i++) {
                if (hotel[i].roomNo == roomNum) {
                    hotel[i].isAvailable = false;
                    break;
                }
            }

            bookingCount++;
        } catch (const invalid_argument&) {
            // skip this line if conversion fails
            continue;
        }
    }

    inFile.close();
}

void exitProgram() {
    cout << "Exiting the program...\n";
    exit(0);
}
int main() {
    displayWelcome();
    initializeRooms();
    loadBookingsFromFile();

    int choice;

    do{
        displayMenu();
        
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
            switch (choice) {
            case 1:
                viewHotelInfo();
                break;
            case 2:
                viewAvailableRooms();
                break;
            case 3:
                bookRoom();
                saveBookingsToFile();
                break;
            case 4:
                cancelBooking();
                saveBookingsToFile();
                break;
            case 5:
                viewBookingDetails();
                break;
            case 6:
                exitProgram();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 6);
    return 0;
}

