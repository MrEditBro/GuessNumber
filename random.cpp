#include <ctime>
#include "random.h"

using namespace std;

unsigned randomNumber () {

	unsigned randomNumber = 228;
	time_t now = time(nullptr);
	tm* localTime = localtime(&now);

	int seconds = localTime->tm_sec;
	int minutes = localTime->tm_min;
	int hours = localTime->tm_hour;
	int day = localTime->tm_mday;
	int month = localTime->tm_mon + 1;
	int year = localTime->tm_year + 1900;

	unsigned long a = year * month * day;
	unsigned long c = (hours + 1) * (minutes + 1) * (seconds + 1);
	
	randomNumber = (a * randomNumber + c) % 65535;

	return randomNumber;
}
