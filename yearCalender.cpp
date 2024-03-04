#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cctype>

using namespace std;


int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		if (Number < 0) {
			cout << "Please entre a positive number\n";
		}
		cout << Message << endl;
		cin >> Number;


		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number\n";
			cout << Message;
			cout << "\n";
			cin >> Number;

		}

	} while (Number <= 0);

	return Number;
}

//_____________________________________________________________

bool isLeapYear(int year) {

	return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
}

int numOfDaysInYear(int year) {

	return isLeapYear(year) ? 366 : 365;
}

int numOfDaysInMonth(int year, int month) {

	short myArray[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : myArray[month - 1];

}

//______________________________________________________________

// 0 sunday 1 monday ..etc

int getDayOfWeekOrder(int year, int month, int day) {

	int a = (14 - month) / 12;

	int y = year - a;

	int m = month + 12 * a - 2;

	int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

	return d; // 0 sunday 1 monday ..etc
}

string dayOfWeekName(int dayOfWeekOrder) {

	string daysOFWeekArr[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return daysOFWeekArr[dayOfWeekOrder];
}

string nameOfMonth(int month) {

	string monthsNamesArr[] = { "", "Jan", "Feb", "Mar", "Apr", "May" ,"Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return monthsNamesArr[month];
}

//________________________________________________________________

void printMonthCalender(int year, int month) {

	int current = getDayOfWeekOrder(year, month, 1);
	int numofdays = numOfDaysInMonth(year, month);

	cout << "\n ----------------" << nameOfMonth(month) << "---------------\n\n";
	cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n\n";

	int i;

	for (i = 0; i < current; i++) {
		printf("     ");
	}

	for (int j = 1; j <= numofdays; j++) {

		printf("%5d", j);

		if (++i == 7) {
			i = 0;
			cout << endl;
		}
	}

	cout << "\n ----------------------------------\n";


}

void printYearCalender(int year) {

	for (int month = 1; month <= 12; month++) {

		printMonthCalender(year, month);
	}
}

//_______________________________________________________________

int main() {

	srand((unsigned)time(NULL));

	int year = ReadPositiveNumber("Entre year: ");

	printYearCalender(year);



}
