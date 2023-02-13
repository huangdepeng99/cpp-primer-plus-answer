#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void) {
	set<string> mat_friends;
	set<string> pat_friends;
	set<string> all_friends;
	string name;
	ostream_iterator<string> out_it(cout, "\n");
	insert_iterator<set<string> > ins_it(all_friends, all_friends.begin());
	
	cout << "Please enter the names of Mat\'s friends (one for each line, enter quit to exit):" << endl;
	while (getline(cin, name) && name != "quit")
		mat_friends.insert(name);
	cout << endl;
	cout << "Mat\'s friends:" << endl;
	copy(mat_friends.begin(), mat_friends.end(), out_it);
	cout << endl;
	
	cout << "Please enter the names of Pat\'s friends (one for each line, enter quit to exit):" << endl;
	while (getline(cin, name) && name != "quit")
		pat_friends.insert(name);
	cout << endl;
	cout << "Pat\'s friends:" << endl;
	copy(pat_friends.begin(), pat_friends.end(), out_it);
	cout << endl;
	
	copy(mat_friends.begin(), mat_friends.end(), ins_it);
	copy(pat_friends.begin(), pat_friends.end(), ins_it);
	cout << "Friends of mat and pat:" << endl;
	copy(all_friends.begin(), all_friends.end(), out_it);
	
	return 0;
}
