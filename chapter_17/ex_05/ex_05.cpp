#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>
#include <limits>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

void print_error(const string & fn) {
	cerr << "Could not open " << fn << '\n';
	exit(EXIT_FAILURE);
}

int main(void) {
	const char * fn_mat = "mat.dat";
	const char * fn_pat = "pat.dat";
	const char * fn_matnpat = "matnpat.dat";
	
	// 打开文件
	ifstream fin_mat(fn_mat);
	if (!fin_mat.is_open())
		print_error(fn_mat);
	ifstream fin_pat(fn_pat);
	if (!fin_pat.is_open())
		print_error(fn_pat);
	ofstream fout_matnpat(fn_matnpat);
	if (!fout_matnpat.is_open())
		print_error(fn_matnpat);
	
	// 处理 Mat 的朋友
	set<string> mat_friends;
	string name;
	while (!getline(fin_mat, name).eof()) {
		if (fin_mat.fail()) {
			if (!name.empty()) {
				fin_mat.ignore(numeric_limits<streamsize>::max(), '\n');
				fin_mat.clear(ios_base::eofbit);
			} else {
				cerr << "An error occurred while reading file " << fn_mat << '\n';
				exit(EXIT_FAILURE);
			}
		}
		if (!name.empty())
			mat_friends.insert(move(name));
	}
	if (!name.empty())
		mat_friends.insert(move(name));
	fin_mat.close();
	
	ostream_iterator<string> out_it(cout, "\n");
	cout << "Mat\'s friends:\n";
	copy(mat_friends.cbegin(), mat_friends.cend(), out_it);
	cout << endl;
	
	// 处理 Pat 的朋友
	set<string> pat_friends;
	while (!getline(fin_pat, name).eof()) {
		if (fin_pat.fail()) {
			if (!name.empty()) {
				fin_pat.ignore(numeric_limits<streamsize>::max(), '\n');
				fin_pat.clear(ios_base::eofbit);
			} else {
				cerr << "An error occurred while reading file " << fn_pat << '\n';
				exit(EXIT_FAILURE);
			}
		}
		if (!name.empty())
			pat_friends.insert(move(name));
	}
	if (!name.empty())
		pat_friends.insert(move(name));
	fin_pat.close();
	
	cout << "Pat\'s friends:\n";
	copy(pat_friends.cbegin(), pat_friends.cend(), out_it);
	
	// 处理 Mat 和 Pat 的朋友
	set<string> matnpat_friends;
	insert_iterator< set<string> > insert_it(matnpat_friends, matnpat_friends.begin());
	copy(mat_friends.cbegin(), mat_friends.cend(), insert_it);
	copy(pat_friends.cbegin(), pat_friends.cend(), insert_it);
	copy(matnpat_friends.cbegin(), matnpat_friends.cend(),
		 ostream_iterator<string>(fout_matnpat, "\n"));
	fout_matnpat.close();
	
	return 0;
}
