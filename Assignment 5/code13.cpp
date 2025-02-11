#include <iostream>

class Time {
private:
    int hours;
    int mins;
    int secs;

public:
    Time() : hours(0), mins(0), secs(0) {}

    // Overload >> operator to accept time from user
    friend std::istream& operator>>(std::istream& input, Time& t) {
        std::cout << "Enter time in hours:mins:secs format: ";
        input >> t.hours >> t.mins >> t.secs;
        return input;
    }

    // Overload + operator to add two Time objects
    Time operator+(const Time& other) const {
        Time sum;
        sum.secs = (secs + other.secs) % 60;
        int carryMins = (secs + other.secs) / 60;
        sum.mins = (mins + other.mins + carryMins) % 60;
        int carryHours = (mins + other.mins + carryMins) / 60;
        sum.hours = (hours + other.hours + carryHours) % 24; // Assuming 24-hour format
        return sum;
    }

    // Overload << operator to display time
    friend std::ostream& operator<<(std::ostream& output, const Time& t) {
        output << t.hours << ":" << t.mins << ":" << t.secs;
        return output;
    }

    // Overload == operator to check if two Time objects are equal
    bool operator==(const Time& other) const {
        return (hours == other.hours && mins == other.mins && secs == other.secs);
    }
};

int main() {
    Time time1, time2, sum;

    std::cin >> time1;
    std::cin >> time2;

    sum = time1 + time2;

    std::cout << "Time 1: " << time1 << std::endl;
    std::cout << "Time 2: " << time2 << std::endl;
    std::cout << "Sum: " << sum << std::endl;

    if (time1 == time2) {
        std::cout << "Time 1 and Time 2 are equal." << std::endl;
    } else {
        std::cout << "Time 1 and Time 2 are not equal." << std::endl;
    }

    return 0;
}
