#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[]) {
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " SOURCE DEST\n";
		exit(EXIT_FAILURE);
	}
	
	ifstream fin(argv[1]);
	if (!fin.is_open()) {
		cerr << "Could not open " << argv[1] << '\n';
		exit(EXIT_FAILURE);
	}
	
	ofstream fout(argv[2]);
	if (!fin.is_open()) {
		cerr << "Could not open " << argv[2] << '\n';
		exit(EXIT_FAILURE);
	}
	
	int c;
	while ((c = fin.get()) != EOF)
		fout.put(c);
	
	fout.close();
	fin.close();
	
	return 0;
}
