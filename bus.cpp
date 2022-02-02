#include <iostream>
#include <cstring>
#include "bus.h"

using namespace std;

static int p = 0;
Bus bus[10];

void vline(char ch) {
    for (int i = 80; i > 0; i--) {
        cout << ch;
    }
}

void Bus::install() {
    cout << "Enter bus no: ";
    cin >> bus[p].busn;
    cout << "\nEnter Driver's name: ";
    cin >> bus[p].driver;
    cout << "\nArrival time: ";
    cin >> bus[p].arrival;
    cout << "\nDeparture: ";
    cin >> bus[p].depart;
    cout << "\nFrom: \t\t\t";
    cin >> bus[p].from;
    cout << "\nTo: \t\t\t";
    cin >> bus[p].to;
    bus[p].empty();
    p++;
}

void Bus::allotment() {
    int seat;
    char number[5];

    top:
    cout << "Bus no: ";
    cin >> number;
    int n;
    for (n = 0; n < p; n++) {
        if (strcmp(bus[n].busn, number) == 0)
            break;
    }

    if (n >= p) {
        cout << "Enter correct bus no.\n";
        goto top;
    }

    while (true) {
        cout << "\nSeat Number: ";
        cin >> seat;
        if (seat > 32) {
            cout << "\nThere are only 32 seats available in this bus.";
        } else {
            if (strcmp(bus[n].seat[seat / 4][(seat % 4) - 1], "Empty") == 0) {
                cout << "Enter passenger's name: ";
                cin >> bus[n].seat[seat / 4][(seat % 4) - 1];
                break;
            } else {
                cout << "The seat no. is already reserved.\n";
            }
        }
    }
}

void Bus::empty() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}

void Bus::show() {
    int n;
    char number[5];
    cout << "Enter bus no: ";
    cin >> number;

    for (n = 0; n < p; n++) {
        if (strcmp(bus[n].busn, number) == 0)
            break;
    }

    if (n >= p) {
        cout << "Enter correct bus no: ";
        return;
    }

    vline('*');
    cout << "Bus no: \t" << bus[n].busn
         << "\nDriver: \t" << bus[n].driver << "\t\tArrival time: \t"
         << bus[n].arrival << "\tDeparture time:" << bus[n].depart
         << "\nFrom: \t\t" << bus[n].from << "\t\tTo: \t\t"
         << bus[n].to << "\n";
    vline('*');
    bus[n].position(n);
    int a = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            a++;
            if (strcmp(bus[n].seat[i][j], "Empty") != 0)
                cout << "\nThe seat no " << (a - 1) << " is reserved for " << bus[n].seat[i][j] << ".";
        }
    }
}

void Bus::position(int l) {
    int s = 0, p = 0;
    for (int i = 0; i < 8; i++) {
        cout << "\n";
        for (int j = 0; j < 4; j++) {
            s++;
            if (strcmp(bus[l].seat[i][j], "Empty") == 0) {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
                p++;
            } else {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
            }
        }
    }
    cout << "\n\nThere are " << p << " seats empty in Bus No: " << bus[l].busn;
}

void Bus::avail() {
    for (int n = 0; n < p; n++) {
        vline('*');
        cout << "Bus no: \t" << bus[n].busn << "\nDriver: \t" << bus[n].driver
             << "\t\tArrival time: \t" << bus[n].arrival << "\tDeparture Time: \t"
             << bus[n].depart << "\nFrom: \t\t" << bus[n].from << "\t\tTo: \t\t"
             << bus[n].to << "\n";
        vline('*');
        vline('_');
    }
}