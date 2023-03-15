#include <iostream>

using namespace std;

const int DEGREES_TO_MINUTES = 60;
const int MINUTES_TO_SECONDS = 60;

int main(void) {
	double d, m, s;
	cout << "Enter a latitude in degrees, minutes, and seconds:\n"
			"First, enter the degrees: ";
	cin >> d;
	cout << "Next, enter the minutes of arc: ";
	cin >> m;
	cout << "Finally, enter the seconds of arc: ";
	cin >> s;
	double degrees = d + (m + s / MINUTES_TO_SECONDS) / DEGREES_TO_MINUTES;
	cout << d << " degrees, " << m << " minutes, " << s << " seconds = "
		 << degrees << " degrees" << endl;
	
	return 0;
}
