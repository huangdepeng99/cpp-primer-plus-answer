#include <iostream>
#include <cstring>

const int BUF = 512;
const int N = 2;

struct chaff {
	char dross[20];
	int slag;
};

char buffer1[BUF];

int main(void) {
	using std::cout;
	using std::endl;
	using std::strcpy;
	char *buffer2 = new char[BUF];
	
	chaff *acf1 = new (buffer1) chaff[N];
	chaff *acf2 = new (buffer2) chaff[N];
	
	strcpy(acf1[0].dross, "Hello World!");
	acf1[0].slag = 1;
	strcpy(acf1[1].dross, "Tree");
	acf1[1].slag = 2;
	for (int i = 0; i < N; ++ i) {
		cout << "#" << i + 1  << ":" << endl;
		cout << "dross: " << acf1[i].dross << endl;
		cout << "slag: " << acf1[i].slag << endl;
	}
	
	cout << endl;
	strcpy(acf2[0].dross, "Wow!");
	acf2[0].slag = 4;
	strcpy(acf2[1].dross, "Apple Tree");
	acf2[1].slag = 12;
	for (int i = 0; i < N; ++ i) {
		cout << "#" << i + 1  << ":" << endl;
		cout << "dross: " << acf2[i].dross << endl;
		cout << "slag: " << acf2[i].slag << endl;
	}
	
	delete [] buffer2;
	
	return 0;
}
