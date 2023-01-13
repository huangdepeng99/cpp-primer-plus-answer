#include <iostream>
#include <cstdlib>
#include <ctime>
#include "personmi.h"

// Person methods
void Person::Get() {
	using std::cin;
	using std::cout;
	using std::getline;
	
	// 虚函数调用 Self()，不要使用有限定的名字
	cout << "Enter " << Self() << "\'s first name: ";
	getline(cin, fname);
	// 虚函数调用 Self()，不要使用有限定的名字
	cout << "Enter " << Self() << "\'s last name: ";
	getline(cin, lname);
}

void Person::Data() const {
	std::cout << "Name: " << fname << ' ' << lname << std::endl;
}

const char * Person::Self() const {
	return "person";
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
	// 使用了有限定的名字，虽然有些地方这样做可能不是必需的。
	// 此外，对于其它成员，则没有使用有限定的名字的必要，因为
	// 它们不是虚函数，不会发生虚函数调用，事实上，此时只会进行
	// 常规的名字查找。
	// 总之，对于方法中调用的虚函数，如果你不希望发生虚函数调用，
	// 则应使用有限定的名字来对虚函数调用进行抑制（比如，该程序
	// 中的 Get() 和 Data() ），然而，在有的时候，这种虚函数调
	// 用是有益的（比如，该程序中的 Self() ）；对于其它成员，通
	// 常来说，没有使用有限定的名字的必要，因为其它成员不会发生
	// 虚函数调用，因此它们会按照常规的名字查找规则来进行名字的
	// 匹配，但是在有的时候，对其它成员使用有限定的名字也是有用
	// 的，甚至是必须的，比如，派生类中的成员隐藏了基类中的同名
	// 成员的时候。
	// 顺便说一句，虚函数调用需要满足3个条件：
	//   1. 调用的是虚函数；
	//   2. 使用无限定的名字。
	//   3. 虚函数没有被隐藏；
	// 关于第1点和第2点都很好理解，问题在于第3点如何理解，假设有
	// 如下继承层次结构：
	//     struct A {
	//         virtual void f() { }
	//     }
	//     struct B : A {
	//         int f(int n) { return n; }	// 隐藏 A::f()
	//     }
	//     struct C : B {
	//         void f() override { }	// 覆盖 A::f()
	//     }
	//     B * p = new C;
	//     p->f();	// 错误
	// 因为 B::f() 隐藏了 A::f()，因此，此时编译器会认为被调用的
	// 函数是 B::f()，而 B::f() 并不是虚函数，所以并不会发生虚函
	// 数调用，更何况，就算 B::f() 是虚函数，发生的也会是针对
	// B::f() 的虚函数调用，而不是针对 A::f() 的虚函数调用，所以，
	// 此时 p->f() 调用的实际上是 B::f()，而 B::f() 需要一个参数，
	// 参数不匹配，编译器将会报告 mismatch 的错误。然而，如果我们
	// 使用的是 A* 或者 C*，则会如我们所愿的发生虚函数调用。
	// 注意，虚函数调用不是必须使用引用或指针来调用才会发生，即
	// 使直接使用对象调用也有可能发生虚函数调用，只不过直接使用
	// 对象调用将会调用该对象的最终覆盖函数，而使用引用或指针时，
	// 则会调用该引用或指针所指向的对象的最终覆盖函数。
	// 接下来的问题是，如何区分覆盖和隐藏呢？覆盖需要满足几个条件：
	//   1. 特征标相同；
	//   2. 返回类型满足协变；
	//   3. 允许被覆盖。
	// 如果一个函数不满足覆盖的要求，但名字相同，则会隐藏基类的函
	// 数，也就是说，在进行名字查找时，会因为先找到派生类的函数，
	// 而导致基类函数无法被找到，也就是被隐藏了。事实上，在实际的
	// 编程过程中，如果你想要确保某个函数是覆盖，而不是隐藏的话，
	// 可以使用 C++11 新增的关键字 override，使用关键字 override
	// 的主要目的有两个，第一，可以告诉用户这是对基类中某个虚函数
	// 的覆盖，第二，可以让编译器来进行覆盖检查，如果使用了该关键
	// 字，却不满足覆盖的条件，编译器将会报错。
	// 还有一个问题是，什么是最终覆盖函数呢？每一个虚函数都有一个
	// 最终覆盖函数，最终覆盖函数是发生虚函数调用时，实际被调用的
	// 函数，派生类的最终覆盖函数就是离它最近的覆盖函数，如果有多
	// 个最终覆盖函数，程序非良构。
	Person::Get();
}

void Person::Show() const {
	// 有限定的名字，抑制虚函数调用
	Person::Data();
}

// Gunslinger methods
void Gunslinger::Get() {
	using std::cin;
	using std::cout;
	
	// 虚函数调用 Self()，不要使用有限定的名字
	cout << "Enter " << Self() << "\'s drawing time: ";
	cin >> dtime;
	// 虚函数调用 Self()，不要使用有限定的名字
	cout << "Enter " << Self() << "\'s number of nicks: ";
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
	// 有限定的名字，抑制虚函数调用
	Gunslinger::Get();
}

void Gunslinger::Show() const {
	// 虚函数调用 Self()，不要使用有限定的名字
	std::cout << "Category: " << Self() << std::endl;
	Person::Data();
	// 有限定的名字，抑制虚函数调用
	Gunslinger::Data();
}

// PockerPlayer methods
int PockerPlayer::Draw() const {
	std::srand(std::time(nullptr));
	return std::rand() % 52 + 1;
}

void PockerPlayer::Show() const {
	// 虚函数调用 Self()，不要使用有限定的名字
	std::cout << "Category: " << Self() << std::endl;
	Person::Data();
	// 有限定的名字，抑制虚函数调用
	PockerPlayer::Data();
}

// BadDude methods
void BadDude::Show() const {
	// 虚函数调用 Self()，不要使用有限定的名字
	std::cout << "Category: " << Self() << std::endl;
	Person::Data();
	Gunslinger::Data();
	PockerPlayer::Data();
	// 有限定的名字，抑制虚函数调用
	BadDude::Data();
}
