#include <iostream>
#include <cstdlib>
#include "bus.h"

using namespace std;

int main() {
    system("cls");
    int w;
    while (1) {
        cout << R"(
  _                _ _               _    _       _                    _ _
 | |              | (_)             | |  | |     (_)                  (_) |             
 | | ___  __ _  __| |_ _ __   __ _  | |  | |_ __  ___   _____ _ __ ___ _| |_ _   _      
 | |/ _ \/ _` |/ _` | | '_ \ / _` | | |  | | '_ \| \ \ / / _ \ '__/ __| | __| | | |     
 | |  __/ (_| | (_| | | | | | (_| | | |__| | | | | |\ V /  __/ |  \__ \ | |_| |_| |     
 |_|\___|\__,_|\__,_|_|_| |_|\__, |  \____/|_| |_|_| \_/ \___|_|  |___/_|\__|\__, |     
                              __/ |                                           __/ |     
                             |___/                                           |___/      
        )";

        cout << "\n\n\n\n\n";
        cout << "\t\t\t1. Install\n\t\t\t"
             << "2. Reservation\n\t\t\t"
             << "3. Show\n\t\t\t"
             << "4. Buses Available\n\t\t\t"
             << "5. Exit";
        cout << "\n\t\t\tEnter your choice:-> ";
        cin >> w;

        switch (w) {
            case 1:
                bus[p].install();
                break;
            case 2:
                bus[p].allotment();
                break;
            case 3:
                bus[0].show();
                break;
            case 4:
                bus[0].avail();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}