#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void print_error(const char * fn) {
	cerr << "Could not open " << fn << '\n';
	exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]) {
	if (argc != 4) {
		cerr << "Usage: " << argv[0] << " SOURCE1 SOURCE2 DEST\n";
		exit(EXIT_FAILURE);
	}
	
	ifstream fin1(argv[1]);
	if (!fin1.is_open())
		print_error(argv[1]);
	
	ifstream fin2(argv[2]);
	if (!fin2.is_open())
		print_error(argv[2]);
	
	ofstream fout(argv[3]);
	if (!fout.is_open())
		print_error(argv[3]);
	
	// 注意：文本文件的最后一行不一定以 '\n' 终止，最
	//       后一行是否要求终止的 '\n' 是实现定义的。
	int c;
	while (!fin1.eof() && !fin2.eof()) {
		while ((c = fin1.get()) != EOF && c != '\n')
			fout.put(c);
		fout.put(' ');
		while ((c = fin2.get()) != EOF && c != '\n')
			fout.put(c);
		fout.put('\n');
		// 在最后一行以 '\n' 终止时，取走所有的字符并不会
		// 设置eofbit，下面的两行代码确保了在取走所有字符
		// 时一定会设置eofbit，而在其它情况下，则不会有任
		// 何影响
		fin1.peek();
		fin2.peek();
	}
	
	if (!fin1.eof()) {
		while ((c = fin1.get()) != EOF)
			fout.put(c);
	}
	
	if (!fin2.eof()) {
		while ((c = fin2.get()) != EOF)
			fout.put(c);
	}
	
	fout.close();
	fin2.close();
	fin1.close();
	
	return 0;
}
