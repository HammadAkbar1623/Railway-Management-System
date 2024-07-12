#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>

using namespace std;

class Train {
public:
    string si;
    string train_number;
    string train_name;
    string start;
    string destination;
    string price;
    int seat;
    string time;
};

class Booking {
public:
    string train_number;
    string name;
    string phone;
    string date;
    int seat;
};

class RailwayReservationSystem {
private:
    
    Booking bookings[40];
    
    int numBookings = 0;
    
    void viewInfo();
    void bookTicket();
    void cancelTicket();
    void admin();
    void viewPassengers();
    void addTrain();
    void deleteTrain();
    bool validatePassword();

public:
	int numTrains = 0;
	Train trains[20];
    void mainMenu();
};

void RailwayReservationSystem::mainMenu() {
    int choice;
    cout << "\n\t\t\t*********************************\n";
    cout << "\t\t\t*******RAILWAY RESERVATION SYSTEM*******\n";
    cout << "\t\t\t*********************************\n";
    cout << "\n\t\t\t<<<<<<<<<<WELCOME USERS>>>>>>>>>>\n";
    cout << "\n\n\t\t\t\t      MENU\n";
    cout << "\t\t\t             ******";
    cout << "\n\t\t\t[1] VIEW INFORMATION\n";
    cout << "\n\t\t\t[2] BOOK TICKET\n";
    cout << "\n\t\t\t[3] CANCEL TICKET\n";
    cout << "\n\t\t\t[4] ADMIN";
    cout << "\n\n\t\t\t[5] EXIT\n";
    cout << "\n\t\t\t********************************";
    cout << "\n\t\t\t********************************";
    cout << "\n\t\t\tENTER YOUR CHOICE: ";

    cin >> choice;
    switch (choice) {
    case 1:
        viewInfo();
        break;
    case 2:
        bookTicket();
        break;
    case 3:
        cancelTicket();
        break;
    case 4:
        if (validatePassword()) {
            admin();
        }
        break;
    case 5:
        cout << "\n\t\t\t =========================================\n";
        cout << "\t\t\t *******RAILWAY RESERVATION SYSTEM*******\n";
        cout << "\t\t\t ===============================================\n";
        cout << "\n\n\t\t\tDeveloped by Hammad\n\n";
        getch();
        exit(0);
        break;
    default:
        cout << "\n\t\t\t==============================================\n";
        cout << "\t\t\t   *******RAILWAY RESERVATION SYSTEM*******\n";
        cout << "\t\t\t   ==============================================\n";
        cout << "\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n";
        cout << "\t\t\t<<<<<<<<PLEASE ENTER RIGHT CHOICE>>>>>>>>\n";
        getch();
        mainMenu();
    }
}

void RailwayReservationSystem::viewInfo() {
    int ch;
    cout << "\n\t\t     **********************************************************";
    cout << "\n\t\t     ********************RAILWAY RESERVATION SYSTEM********************";
    cout << "\n\t\t     **********************************************************";
    cout << "\n\n\n    SI\ttrain number\ttrain name\tstart place\tdestination place\tprice\tseat\ttime\n\n";
    for (int i = 0; i < numTrains; i++) {
        cout << "    " << trains[i].si << "\t" << trains[i].train_number << "\t\t" << trains[i].train_name << "\t\t" << trains[i].start << "\t\t" << trains[i].destination << "\t\t\t" << trains[i].price << "\t" << trains[i].seat << "\t" << trains[i].time << "\n";
    }
    cout << "    ***********************************************************************************************\n";
    cout << "\n\t\t\tpress '1' for main menu & press any key for exit:  ";
    cin >> ch;
    if (ch == 1) {
        mainMenu();
    } else {
        exit(0);
    }
}

void RailwayReservationSystem::bookTicket() {
    int n;
    cout << "\n\n\t\t\t============================================";
    cout << "\n\t\t\t**********RAILWAY RESERVATION SYSTEM**********\n";
    cout << "\t\t\t==================================================";
    cout << "\n\n\t\t\tHow many tickets do you want to buy: ";
    cin >> n;
    for (int j = 0; j < n; ++j) {
        Booking newBooking;
        cout << "\n\n\t\t\tEnter train number: ";
        cin >> newBooking.train_number;

        bool trainFound = false;
        for (int i = 0; i < numTrains; i++) {
            if (trains[i].train_number == newBooking.train_number) {
                trainFound = true;
                if (trains[i].seat == 0) {
                    cout << "\n\n\t\t\tNot available seat";
                    getch();
                    mainMenu();
                    return;
                } else {
                    cout << "\n\t\t\tEnter booking details: ";
                    cout << "\n\t\t\tEnter date: ";
                    cin >> newBooking.date;
                    cout << "\n\t\t\tEnter your name: ";
                    cin >> newBooking.name;
                    cout << "\n\t\t\tEnter your phone number: ";
                    cin >> newBooking.phone;
                    cout << "\n\t\t\tSeat number: " << trains[i].seat;
                    newBooking.seat = trains[i].seat;
                    bookings[numBookings++] = newBooking;
                    trains[i].seat--;
                    break;
                }
            }
        }
        if (!trainFound) {
            cout << "\n\n\t\t\tTrain not found!!!";
            getch();
            mainMenu();
            return;
        }
    }
    int c;
    cout << "\n\n\t\t\tEnter '1' for main menu & press any key to exit: ";
    cin >> c;
    if (c == 1) {
        mainMenu();
    } else {
        exit(0);
    }
}

void RailwayReservationSystem::cancelTicket() {
    string phone;
    cout << "\n\n\t\t\tEnter phone number: ";
    cin >> phone;

    bool bookingFound = false;
    for (int i = 0; i < numBookings; ++i) {
        if (bookings[i].phone == phone) {
            for (int j = i; j < numBookings - 1; ++j) {
                bookings[j] = bookings[j + 1];
            }
            numBookings--;
            cout << "\n\n\t\t\t<<<<<<<<<<<<<<<Ticket cancelled successfully>>>>>>>>>>>>";
            bookingFound = true;
            break;
        }
    }

    if (!bookingFound) {
        cout << "\n\n\t\t\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n";
    }
    getch();
    mainMenu();
}

void RailwayReservationSystem::admin() {
    int choice;
    cout << "\n     ==================================================================";
    cout << "\n     ********************RAILWAY RESERVATION SYSTEM*******************";
    cout << "\n     ====================================================================";
    cout << "\n\n";
    cout << "           <<<<<<<<<<<<<<<WELCOME_ADMIN>>>>>>>>>>>>>>>\n";
    cout << "\n\n";
    cout << "              ************************************\n";
    cout << "              ||      CHOOSE YOUR OPERATION     ||\n";
    cout << "              ||--------------------------------||\n";
    cout << "              ||      [1] VIEW PASSENGERS       ||\n";
    cout << "              ||      [2] ADD TRAIN             ||\n";
    cout << "              ||      [3] DELETE TRAIN          ||\n";
    cout << "              ||      [4] BACK                  ||\n";
    cout << "              ||                                ||\n";
    cout << "              ************************************\n\n";
    cout << "     **********************************************************\n";
    cout << "\n\t\tENTER YOUR CHOICE: ";
    cin >> choice;

    switch (choice) {
    case 1:
        viewPassengers();
        break;
    case 2:
        addTrain();
        break;
    case 3:
        deleteTrain();
        break;
    case 4:
        mainMenu();
        break;
    default:
        cout << "\n\t\t\tYou entered wrong KEY!!!!";
        getch();
        admin();
    }
}

bool RailwayReservationSystem::validatePassword() {
    const int correctPassword = 1234567;
    int inputPassword;
    cout << "\n\t\t\tEnter password: ";
    cin >> inputPassword;
    if (inputPassword == correctPassword) {
        cout << "\n\n\t\t\t<<<<<Login successfully>>>>>";
        getch();
        return true;
    } else {
        cout << "\n\n\t\t\t\t   ERROR!!!!!";
        cout << "\n\n\t\t\t<<<<<<<<Wrong password>>>>>>>>";
        getch();
        return false;
    }
}

void RailwayReservationSystem::viewPassengers() {
    cout << "\n\t\t\t       **********************************************************";
    cout << "\n\t\t\t       ********************RAILWAY RESERVATION SYSTEM********************";
    cout << "\n\t\t\t       **********************************************************";
    cout << "\n\n\t\t\tTrain number\t\tName\t\tPhone number\t\tDate";
    for (int i = 0; i < numBookings; ++i) {
        cout << "\n\t\t\t" << bookings[i].train_number << "\t\t" << bookings[i].name << "\t\t" << bookings[i].phone << "\t\t" << bookings[i].date;
    }
    cout << "\n\t\t\t**********************************************************\n";
    getch();
    admin();
}

void RailwayReservationSystem::addTrain() {
    Train newTrain;
    cout << "\n\n\t\t\tEnter train details:";
    cout << "\n\t\t\tSI: ";
    cin >> newTrain.si;
    cout << "\n\t\t\tTrain number: ";
    cin >> newTrain.train_number;
    cout << "\n\t\t\tTrain name: ";
    cin >> newTrain.train_name;
    cout << "\n\t\t\tStart place: ";
    cin >> newTrain.start;
    cout << "\n\t\t\tDestination place: ";
    cin >> newTrain.destination;
    cout << "\n\t\t\tPrice: ";
    cin >> newTrain.price;
    cout << "\n\t\t\tSeat: ";
    cin >> newTrain.seat;
    cout << "\n\t\t\tTime: ";
    cin >> newTrain.time;
    trains[numTrains++] = newTrain;
    cout << "\n\n\t\t\t<<<<<<<<<<<<<<<Train added successfully>>>>>>>>>>>>";
    getch();
    admin();
}

void RailwayReservationSystem::deleteTrain() {
    string train_number;
    cout << "\n\n\t\t\tEnter train number: ";
    cin >> train_number;

    bool trainFound = false;
    for (int i = 0; i < numTrains; ++i) {
        if (trains[i].train_number == train_number) {
            for (int j = i; j < numTrains - 1; ++j) {
                trains[j] = trains[j + 1];
            }
            numTrains--;
            cout << "\n\n\t\t\t<<<<<<<<<<<<<<<Train deleted successfully>>>>>>>>>>>>";
            trainFound = true;
            break;
        }
    }

    if (!trainFound) {
        cout << "\n\n\t\t\t<<<<<<<<<<<<<<Train not found>>>>>>>>>>>>>>>>> \n";
    }
    getch();
    admin();
}

int main() {
    RailwayReservationSystem system;

    // Sample data for trains
    Train t1 = { "1", "123", "Jaffar Express", "Faisalabad", "Lahore", "50", 50, "10:00" };
    Train t2 = { "2", "1234", "Khyber Express", "Quetta", "Peshawar", "75", 40, "12:00" };
    Train t3 = { "3", "12345", "Mari Indus", "Mianwali", "Banuu", "100", 30, "01:00" };

    system.trains[system.numTrains++] = t1;
    system.trains[system.numTrains++] = t2;
    system.trains[system.numTrains++] = t3;

    system.mainMenu();
    return 0;
}

