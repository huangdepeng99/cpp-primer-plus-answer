#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[]) {
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " FILENAME\n";
		exit(EXIT_FAILURE);
	}
	
	ofstream fout(argv[1]);
	if (!fout.is_open()) {
		cerr << "Could not open " << argv[1] << '\n';
		exit(EXIT_FAILURE);
	}
	
	int c;
	while ((c = cin.get()) != EOF)
		fout.put(c);
	
	fout.close();
	
	return 0;
}
