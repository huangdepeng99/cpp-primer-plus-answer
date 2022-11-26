#include <iostream>
#include <cstring>

using namespace std;

const int SLEN = 50;

struct CandyBar {
	char brand[SLEN];
	double weight;
	int quantity_of_heat;
};

void set_member(CandyBar &cb, const char *brand = "Millennium Munch",
				double weight = 2.85, int heat = 350)
{
	size_t size = strlen(brand);
	if (size + 1 <= SLEN) {
		strcpy(cb.brand, brand);
	} else {
		strncpy(cb.brand, brand, SLEN - 1);
		cb.brand[SLEN] = '\0';
	}
	cb.weight = weight;
	cb.quantity_of_heat = heat;
}

void show(const CandyBar &cb) {
	cout << "brand: " << cb.brand << endl;
	cout << "weight: " << cb.weight << endl;
	cout << "quantity of heat: " << cb.quantity_of_heat << endl;
}

int main(void) {
	CandyBar cb;
	set_member(cb);
	show(cb);
	cout << endl;
	set_member(cb, "Wahaha");
	show(cb);
	cout<< endl;
	set_member(cb, "Adiddas", 4.7);
	show(cb);
	cout << endl;
	set_member(cb, "LOVE", 1.9, 200);
	show(cb);
	
	return 0;
}
