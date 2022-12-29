#include <iostream>
#include <string>
#include "dma.h"

const int CLIENTS = 6;

int main(void) {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	using std::getline;
	
	topDMA *p_clients[CLIENTS];
	string templabel;
	int temprating;
	char kind;
	
	for (int i = 0; i < CLIENTS; ++ i) {
		cout << "Enter label: ";
		getline(cin, templabel);
		cout << "Enter rating: ";
		cin >> temprating;
		cout << "Enter 1 for baseDMA or "
				"2 for lacksDMA or "
				"3 for hasDMA: ";
		while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
			cout <<"Enter 1 or 2 or 3: ";
		while (cin.get() != '\n')
			;
		if (kind == '1') {
			p_clients[i] = new baseDMA(templabel.c_str(), temprating);
		} else if (kind == '2') {
			string tempcolor;
			cout << "Enter color: ";
			getline(cin, tempcolor);
			p_clients[i] = new lacksDMA(tempcolor.c_str(), templabel.c_str(), temprating);
		} else {	// kind == '3'
			string tempstyle;
			cout << "Enter style: ";
			getline(cin, tempstyle);
			p_clients[i] = new hasDMA(tempstyle.c_str(), templabel.c_str(), temprating);
		}
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; ++ i) {
	   p_clients[i]->View();
	   cout << endl;
	}
	
	for (int i = 0; i < CLIENTS; ++ i) {
	   delete p_clients[i];  // free memory
	}
	cout << "Done." << endl;
	
	return 0;
}
