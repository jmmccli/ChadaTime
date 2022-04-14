/*
 * Chada Clock App
 *
 *  Date: 2022-03-17
 *  Author: Lord Jeremy M. McClintock, CISSP
 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <locale>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

class chadaClock {
private:
    time_point<system_clock> currentClock;


public:
    chadaClock() {
        currentClock = system_clock::now();
    }
    void print_clock(int twhr) {
        time_t currentTime = system_clock::to_time_t(currentClock);
        struct tm* timeinfo;
        timeinfo = localtime(&currentTime);
        char buffer[80];

        if (twhr == 12) {
            strftime(buffer, sizeof(buffer), "%I:%M:%S %p", timeinfo);

            cout << "**************************" << endl;
            cout << "*      12-Hour Clock     *" << endl;
            cout << "*      " << buffer << "       *" << endl;
            cout << "**************************" << endl;
        }
        else if (twhr == 24) {
            strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);

            cout << "**************************" << endl;
            cout << "*      24-Hour Clock     *" << endl;
            cout << "*      " << buffer << "          *" << endl;
            cout << "**************************" << endl;
        }
        else {
            cout << "Invalid Clock" << endl;
        }
    }

    void adjust_time(char type, int time) {
        if ((type == 'h') || (type == 'H')) {
            currentClock += hours(time);
        }
        else if ((type == 'm') || (type == 'M')) {
            currentClock += minutes(time);
        }
        else if ((type == 's') || (type == 'S')) {
            currentClock += seconds(time);
        }
        else {
            cout << "Invalid Input.";
        }
    }

};

int main() {

    chadaClock currChada;
    string clocktype;
    cout << "Would you like the clock in 12h or 24h format? Or type 'adj' to adjust the clock, or Quit or Exit to quit." << endl;
    cin >> clocktype;

    while ((clocktype != "Quit") && (clocktype != "quit") && (clocktype != "QUIT") &&
        (clocktype != "Exit") && (clocktype != "exit") && (clocktype != "EXIT")) {
        if ((clocktype == "12h") || (clocktype == "12hr") || (clocktype == "12")) {
            currChada.print_clock(12);
        }
        else if ((clocktype == "24h") || (clocktype == "24hr") || (clocktype == "24")) {
            currChada.print_clock(24);
        }
        else if ((clocktype == "adj") || (clocktype == "Adj") || (clocktype == "ADJ")) {
            char adjtype = 'a';
            cout << "Type 'H' to adjust hours, 'M' to adjust minutes, & 'S' to adjust seconds..." << endl;
            cin >> adjtype;
            if (adjtype == 'H' || adjtype == 'h') {
                int cHours = 0;
                cout << "How many hours do you want to adjust the clock by?" << endl;
                cin >> cHours;
                currChada.adjust_time('h', cHours);
            }
            else if (adjtype == 'M' || adjtype == 'm') {
                int cMins = 0;
                cout << "How many minutes do you want to adjust the clock by?" << endl;
                cin >> cMins;
                currChada.adjust_time('m', cMins);
            }
            else if (adjtype == 'S' || adjtype == 's') {
                int cSecs = 0;
                cout << "How many seconds do you want to adjust the clock by?" << endl;
                cin >> cSecs;
                currChada.adjust_time('s', cSecs);
            }
        }
        else {
            cout << "Invalid Clock Type." << endl;
            break;
        }

        cout << "Would you like the clock in 12h or 24h format? Or type 'adj' to adjust the clock, or Quit or Exit to quit." << endl;
        cin >> clocktype;
    }

    return 0;
}
