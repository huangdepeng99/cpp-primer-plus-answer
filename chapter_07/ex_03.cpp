#include <iostream>

using namespace std;

struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show_box(box b) {
	cout << "maker: " << b.maker << endl
		 << "heigth: " << b.height << endl
		 << "width: " << b.width << endl
		 << "length: " << b.length << endl
		 << "volume: " << b.volume << endl;
}

void set_volume(box *pb) {
	pb->volume = pb->height * pb->width * pb->length;
}

int main(void) {
	box b;
	cout << "Please enter your name: ";
	cin.getline(b.maker, 40);
	cout << "Please enter the length of the box: ";
	cin >> b.length;
	cout << "Please enter the width of the box: ";
	cin >> b.width;
	cout << "Please enter the height of the box: ";
	cin >> b.height;
	set_volume(&b);
	show_box(b);
	
	return 0;
}
