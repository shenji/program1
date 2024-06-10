#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
class Timer {
private:
    int seconds;
    bool countUp;
    string message;

public:
    Timer(int seconds, bool countUp, string message)
        : seconds(seconds), countUp(countUp), message(message) {}

    void reset(int newSeconds) {
        seconds = newSeconds;
    }

    void start() {
        if (countUp) {
            for (int i = 1; i <= seconds; ++i) {
                cout << i << endl;
                usleep(1000000);  // Sleep for one second
            }
        } else {
            for (int i = seconds; i >= 1; --i) {
                cout << i << endl;
                usleep(1000000);  // Sleep for one second
            }
        }
        cout << message << endl;
    }
};

int main() {
    cout << "Count Up Test" << endl;
    cout << "-------------" << endl;

    Timer timerUp(3, true, "Time's up!");
    cout << "Starting 3 second timer..." << endl;
    timerUp.start();

    cout << "Resetting to 5 seconds" << endl;
    timerUp.reset(5);
    cout << "Starting 5 second timer..." << endl;
    timerUp.start();

    cout << endl;
    cout << "Count Down Test" << endl;
    cout << "---------------" << endl;

    Timer timerDown(3, false, "Time's up!");
    cout << "Starting 3 second timer..." << endl;
    timerDown.start();

    cout << "Resetting to 5 seconds" << endl;
    timerDown.reset(5);
    cout << "Starting 5 second timer..." << endl;
    timerDown.start();

    return 0;
}