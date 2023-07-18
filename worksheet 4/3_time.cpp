#include <iostream>

using namespace std;

class Time {
private:
    int hour;
    int min;
    int sec;

public:
    Time() : hour(0), min(0), sec(0) {}

    Time(int h, int m, int s) : hour(h), min(m), sec(s) {}

    void readTime() {
        cout << "Enter hours: ";
        cin >> hour;
        cout << "Enter minutes: ";
        cin >> min;
        cout << "Enter seconds: ";
        cin >> sec;
    }

    void displayTime() const {
        cout << hour << "h " << min << "m " << sec << "s";
    }

    Time addTime(const Time& t) const {
        Time result;
        int totalSec = sec + t.sec;
        result.sec = totalSec % 60;
        int carryMin = totalSec / 60;

        int totalMin = min + t.min + carryMin;
        result.min = totalMin % 60;
        int carryHour = totalMin / 60;

        result.hour = hour + t.hour + carryHour;

        return result;
    }

    Time diffTime(const Time& t) const {
        Time result;
        int totalSec = (hour - t.hour) * 3600 + (min - t.min) * 60 + (sec - t.sec);

        if (totalSec < 0) {
            totalSec += 24 * 3600;
        }
        if(totalSec > 24*3600){
            totalSec -= 24*3600;
        }

        result.hour = totalSec / 3600;
        totalSec %= 3600;
        result.min = totalSec / 60;
        result.sec = totalSec % 60;

        return result;
    }
};

int main() {
    Time t1, t2;

    cout << "Enter the first time:\n";
    t1.readTime();

    cout << "Enter the second time:\n";
    t2.readTime();

    Time sum = t1.addTime(t2);
    Time diff = t1.diffTime(t2);

    cout << "\nFirst Time: ";
    t1.displayTime();

    cout << "\nSecond Time: ";
    t2.displayTime();

    cout << "\nSum of Times: ";
    sum.displayTime();

    cout << "\nDifference between Times: ";
    diff.displayTime();
    return 0;
}
