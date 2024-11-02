#include <iostream>
#include <ctime>

using namespace std;

// Function to calculate age
int calculateAge(int birthYear, int birthMonth, int birthDay) {
    // Get current date
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;

    // Calculate age
    int age = currentYear - birthYear;
    // Adjust for birth month and day
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

int main() {
    int year, month, day;

    cout << "Enter your birth year (YYYY): ";
    cin >> year;
    cout << "Enter your birth month (MM): ";
    cin >> month;
    cout << "Enter your birth day (DD): ";
    cin >> day;

    // Calculate and display age
    int age = calculateAge(year, month, day);
    cout << "You are " << age << " years old." << endl;

    return 0;
}
