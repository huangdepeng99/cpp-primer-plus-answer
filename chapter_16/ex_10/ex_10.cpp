#include <iostream>
#include <string>
#include <vector>
#include <new>
#include <memory>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Review {
    string title;
    int rating;
	double price;
};

using val_tp = shared_ptr<Review>;
using lref = val_tp &;
using const_lref = const val_tp &;

inline bool
sorted_by_title(const_lref r1, const_lref r2)
{ return r1->title < r2->title; }

inline bool
sorted_by_rating_asc(const_lref r1, const_lref r2)
{ return r1->rating < r2->rating; }

inline bool
sorted_by_rating_desc(const_lref r1, const_lref r2)
{ return sorted_by_rating_asc(r2, r1); }

inline bool
sorted_by_price_asc(const_lref r1, const_lref r2)
{ return r1->price < r2->price; }

inline bool
sorted_by_price_desc(const_lref r1, const_lref r2)
{ return sorted_by_price_asc(r2, r1); }

bool FillReview(lref r) {
	Review * p;
	try {
		p = new Review;
	}
	catch (const bad_alloc & ba) {
		cerr << "Out of memory. Process termination." << endl;
		exit(EXIT_FAILURE);
	}
	val_tp temp(p);
	p = nullptr;
	
    cout << "Enter book title (quit to quit): ";
    getline(cin, temp->title);
    if (temp->title == "quit")
        return false;
    cout << "Enter book rating: ";
    cin >> temp->rating;
    if (!cin)
        return false;
    cout << "Enter book price: ";
    cin >> temp->price;
    if (!cin)
        return false;
    // get rid of rest of input line
    while (cin.get() != '\n')
        continue;
	r = temp;
    return true;
}

void ShowReview(const_lref r) {
    cout << r->rating << "\t" << r->title << "\t" << r->price << endl;
}

void ShowMenu() {
	cout << "Select a sort method to display book information or quit:" << endl
		 << "a) original" << endl
		 << "b) title" << endl
		 << "c) rating (ascending order)" << endl
		 << "d) rating (descending order)" << endl
		 << "e) price (ascending order)" << endl
		 << "f) price (descending order)" << endl
		 << "g) quit" << endl;
}

const char * prompt = ">> ";

int main(void) {
    vector<val_tp> books;
    val_tp temp;
	
    while (FillReview(temp))
        books.push_back(temp);
	temp.reset();
	cout << endl;
	
    if (books.size() > 0) {
		auto origin_books = books;
		ShowMenu();
		cout << prompt;
		char choice;
		while (cin >> choice && choice != 'g') {
			switch (choice) {
				case 'a': cout << "Original order:" << endl;
						  break;
				case 'b': sort(books.begin(), books.end(), sorted_by_title);
						  cout << "Sorted by title:" << endl;
						  break;
				case 'c': sort(books.begin(), books.end(), sorted_by_rating_asc);
                          cout << "Sorted by rating (ascending order):" << endl;
                          break;
				case 'd': sort(books.begin(), books.end(), sorted_by_rating_desc);
                          cout << "Sorted by rating (descending order):" << endl;
                          break;
				case 'e': sort(books.begin(), books.end(), sorted_by_price_asc);
                          cout << "Sorted by price (ascending order):" << endl;
                          break;
				case 'f': sort(books.begin(), books.end(), sorted_by_price_desc);
                          cout << "Sorted by price (descending order):" << endl;
                          break;
				default:  cout << "Bad choice. Try again." << endl
							   << prompt;
						  continue;
			}
			cout << "Rating\tBook\tPrice" << endl;
			for_each(books.begin(), books.end(), ShowReview);
			cout << endl;
			ShowMenu();
			cout << prompt;
		}
    }
    else
        cout << "No entries." << endl;
    cout << "Bye." << endl;
    
    return 0;
}
