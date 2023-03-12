#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstdint>

using namespace std;

void ShowStr(const string & s) {
	cout << s << endl;
}

void GetStrs(ifstream & ifs, vector<string> & vs) {
	uint64_t sz;
	const size_t BUFSZ = 512;
	char buffer[BUFSZ];
	string temp;
	while (ifs.read( reinterpret_cast<char *> (&sz), sizeof(sz) )) {
		size_t times = sz / BUFSZ;
		size_t rest = sz - BUFSZ * times;
		for (size_t i = 0; i < times; ++ i) {
			ifs.read(buffer, BUFSZ);
			temp.append(buffer, BUFSZ);
		}
		ifs.read(buffer, rest);
		temp.append(buffer, rest);
		vs.push_back(move(temp));
		temp.clear();
	}
}

class Store {
private:
	ofstream & ofs_;
public:
	explicit Store(ofstream & ofs) : ofs_(ofs) { }
	void operator()(const string & s) {
		uint64_t sz = s.size();
		ofs_.write( reinterpret_cast<char *> (&sz), sizeof(sz) );
		ofs_.write(s.data(), sz);
	}
};

int main(void) {
	vector<string> vostr;
	const char * filename = "strings.dat";
	string temp;
	
	// 请求字符串
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp).good() && !temp.empty())
		vostr.push_back(move(temp));
	cout << "Here is your input:\n";
	for_each(vostr.cbegin(), vostr.cend(), ShowStr);
	
	// 将字符串存储到文件中
	ofstream fout(filename, ios_base::out | ios_base::binary);
	for_each(vostr.cbegin(), vostr.cend(), Store(fout));
	fout.close();
	
	// 恢复文件内容
	vector<string> vistr;
	ifstream fin(filename, ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		cerr << "Could not open file " << filename << " for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	fin.close();
	cout << "\nHere are the strings read from the file " << filename << ":\n";
	for_each(vistr.cbegin(), vistr.cend(), ShowStr);
	
	return 0;
}
