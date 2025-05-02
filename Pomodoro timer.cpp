#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void doCountdown(int howLong, const string& whatDoing) {
    for (int minuteLeft = howLong; minuteLeft > 0; --minuteLeft) {
        for (int secondLeft = 59; secondLeft >= 0; --secondLeft) {
            cout << "\r" << whatDoing << " - Time left: " << minuteLeft - 1 << ":" << (secondLeft < 10 ? "0" : "") << secondLeft << flush;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    cout << endl;
}

int main() {
    vector<string> stuffToRevise;
    string oneThing;
    int howMuchTimeWeDid = 0;

    cout << "Enter your revision topics (type 'done' when finished):\n";
    while (true) {
        cout << "Topic: ";
        getline(cin, oneThing);
        if (oneThing == "done") break;
        stuffToRevise.push_back(oneThing);
    }

    cout << "\nStarting Pomodoro Revision Timer...\n";

    while (howMuchTimeWeDid < 100) {
        cout << "\n--- Revision Phase (20 minutes) ---\n";
        doCountdown(20, "Study");
        howMuchTimeWeDid += 20;

        if (howMuchTimeWeDid >= 100) break;

        cout << "\n--- Break Time! (5 minutes) ---\n";
        cout << "Go make a cup of tea!\n";
        doCountdown(5, "Break");
    }

    cout << "\n--- Session Complete! ---\n";
    cout << "\nTick off the topics you've completed:\n";
    vector<bool> tickedOff(stuffToRevise.size(), false);

    for (size_t number = 0; number < stuffToRevise.size(); ++number) {
        cout << "Did you complete: " << stuffToRevise[number] << "? (y/n): ";
        char yesOrNo;
        cin >> yesOrNo;
        tickedOff[number] = (yesOrNo == 'y' || yesOrNo == 'Y');
    }

    cout << "\nSummary:\n";
    for (size_t number = 0; number < stuffToRevise.size(); ++number) {
        cout << "[" << (tickedOff[number] ? 'X' : ' ') << "] " << stuffToRevise[number] << endl;
    }

    cout << "\nRevision Completed!\n";
    return 0;
}