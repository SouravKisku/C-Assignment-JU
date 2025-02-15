#include <iostream>
using namespace std;

class Time {
private:
	int hours;
	int minutes;
	int seconds;

public:
	Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}


	friend istream& operator>>(istream& is, Time& time) {
    	char delimiter;
    	is >> time.hours >> delimiter >> time.minutes >> delimiter >> time.seconds;
    	return is;
	}

	Time operator+(const Time& other) const {
    	int totalSeconds = (hours * 3600 + minutes * 60 + seconds) + (other.hours * 3600 + other.minutes * 60 + other.seconds);
    	int newHours = totalSeconds / 3600;
    	int newMinutes = (totalSeconds % 3600) / 60;
    	int newSeconds = totalSeconds % 60;
    	return Time(newHours, newMinutes, newSeconds);
	}

	friend ostream& operator<<(ostream& os, const Time& time) {
    	os << time.hours << ":" << time.minutes << ":" << time.seconds;
    	return os;
	}

	bool operator==(const Time& other) const {
    	return (hours == other.hours) && (minutes == other.minutes) && (seconds == other.seconds);
	}
};
int main() {
	Time time1, time2;

	cout << "Enter time 1 (hours:minutes:seconds): ";
	cin >> time1;

	cout << "Enter time 2 (hours:minutes:seconds): ";
	cin >> time2;

	cout << "Time 1: " << time1 << endl;
	cout << "Time 2: " << time2 << endl;

	Time sum = time1 + time2;
	cout << "Sum of Time 1 and Time 2: " << sum << endl;

	if (time1 == time2) {
    	cout << "Time 1 and Time 2 are equal." << endl;
	} else {
    	cout << "Time 1 and Time 2 are not equal." << endl;
	}


	return 0;
}
