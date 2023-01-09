#include <iostream>
#include <cstdlib>
#include <ctime>
#include "personmi.h"

// Person methods
void Person::Get() {
	using std::cin;
	using std::cout;
	using std::getline;
	
	cout << "Enter person\'s first name: ";
	getline(cin, fname);
	cout << "Enter person\'s last name: ";
	getline(cin, lname);
}

void Person::Data() const {
	std::cout << "Name: " << fname << ' ' << lname << std::endl;
}

Person::~Person()
{ }

void Person::Set() {
	// 注意，这里必须使用有限定的名字 Person::Get()，
	// 而不能使用无限定的名字 Get()
	// 因为可能会出现下面这种情况：
	//     Person * p = new PockerPlayer;
	//     p->Set();
	// 在这里，使用指针 p 来调用 Set() 会导致虚函数调用，
	// 因此会使用指针 p 所指向的对象，也就是 PockerPlayer
	// 对象，来调用函数 Set() 在派生类 PockerPlayer 中的
	// 最终覆盖函数，也就是 Person::Set()，这正是我们希望
	// 调用的函数，然而，在该函数内部，我们又调用了另一个
	// 虚函数，也就是 Get()，如果不使用有限定名的名字来抑制
	// 对函数 Get() 的虚函数调用的话，那么这里会再一次发生
	// 虚函数调用，这一次，会调用函数 Get() 在类 PockerPlayer
	// 中的最终覆盖函数，也就是 PockerPlayer::Get()，而这并
	// 不是我们想要调用的函数，因为我们想要调用的函数是
	// Person::Get()，所以，程序就出错了。
	// 要解决这个问题，当然还有其它的一些方法，一种方法就是在
	// PockerPlayer 类中覆盖基类的 Set() 方法，就像下面这样：
	//     void PockerPlayer::Set() {
	//         Person::Get();
	//         Get();
	//     }
	// Gunslinger 类采用的就是这种方法，事实上，Gunslinger 类
	// 是必须采用这种方法，而对于 PockerPlayer 和 BadDude 则
	// 不是非得要覆盖 Set() 方法才行，因此，在这里，对于这两个
	// 类，我采用的解决方法是使用有限定的名字来抑制虚函数调用，
	// 同时，为了减少出错的可能，我将程序中的其它类似的地方都
	// 使用了有限定的名字，虽然有些地方并不需要。
	// 此外，对于其它成员，则没有使用有限定的名字的必要，即使
	// 派生类中定义了和基类名字相同的成员，因为它们不是虚函数，
	// 不会发生虚函数调用，事实上，此时只会进行常规的名字查找。
	// 总之，对于方法中调用的虚函数，应尽可能的使用有限定的名字，
	// 因为，此时如果发生虚函数调用，它会无视常规的名字查找规则，
	// 调用一个你意料之外的错误函数（最终覆盖函数）；至于其它成
	// 员，通常来说就没有这个必要了，因为其它成员不会发生虚函数
	// 调用，因此它们会按照常规的名字查找规则来进行名字的匹配。
	Person::Get();
}

void Person::Show() const {
	Person::Data();
}

// Gunslinger methods
void Gunslinger::Get() {
	using std::cin;
	using std::cout;
	
	cout << "Enter gunslinger\'s drawing time: ";
	cin >> dtime;
	cout << "Enter gunslinger\'s number of nicks: ";
	cin >> nicks;
	while (cin.get() != '\n')
		continue;
}

void Gunslinger::Data() const {
	using std::cout;
	using std::endl;
	
	cout << "Drawing time: " << dtime << endl;
	cout << "Number of nicks: " << nicks << endl;
}

void Gunslinger::Set() {
	Person::Get();
	Gunslinger::Get();
}

void Gunslinger::Show() const {
	std::cout << "Category: gunslinger" << std::endl;
	Person::Data();
	Gunslinger::Data();
}

// PockerPlayer methods
int PockerPlayer::Draw() const {
	std::srand(std::time(nullptr));
	return std::rand() % 52 + 1;
}

void PockerPlayer::Show() const {
	std::cout << "Category: pockerplayer" << std::endl;
	Person::Data();
	PockerPlayer::Data();
}

// BadDude methods
void BadDude::Show() const {
	std::cout << "Category: baddude" << std::endl;
	Person::Data();
	Gunslinger::Data();
	PockerPlayer::Data();
	BadDude::Data();
}
