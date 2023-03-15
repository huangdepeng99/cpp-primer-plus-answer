#include <iostream>

using namespace std;

const int DAYS_TO_HOURS = 24;
const int HOURS_TO_MINUTES = 60;
const int MINUTES_TO_SECONDS = 60;

using ll_t_ = long long;

int main(void) {
	ll_t_ sec;
	cout << "Enter the number of seconds: ";
	cin >> sec;
	
	auto temp = sec;
	ll_t_ d = temp / (DAYS_TO_HOURS * HOURS_TO_MINUTES * MINUTES_TO_SECONDS);
	temp %= (DAYS_TO_HOURS * HOURS_TO_MINUTES * MINUTES_TO_SECONDS);
	ll_t_ h = temp / (HOURS_TO_MINUTES * MINUTES_TO_SECONDS);
	temp %= (HOURS_TO_MINUTES * MINUTES_TO_SECONDS);
	ll_t_ m = temp / MINUTES_TO_SECONDS;
	temp %= MINUTES_TO_SECONDS;
	ll_t_ s = temp;
	
	cout << sec << " seconds = "
		 << d << " days, "
		 << h << " hours, "
		 << m << " minutes, "
		 << s << " seconds" << endl;
	
	return 0;
}
