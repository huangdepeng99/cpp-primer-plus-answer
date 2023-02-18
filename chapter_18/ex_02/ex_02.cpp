#include <iostream>
#include <string>
#include "cpmv.h"

using namespace std;

void show(const Cpmv & cm, const string & s) {
	cout << s << endl;
	cm.display();
	cout << endl;
}

int main(void) {
	Cpmv cm1;
	show(cm1, "cm1:");
	
	cm1 = Cpmv("Hello", "Happy");
	show(cm1, "cm1:");
	
	string s1 = "Apple";
	string s2 = "blue";
	Cpmv cm2(s1, s2);
	show(cm2, "cm2:");
	cm1 = cm2;
	show(cm1, "cm1:");
	
	Cpmv cm3 = cm1;
	show(cm3, "cm3:");
	
	Cpmv cm4 = Cpmv("yellow", "good") + Cpmv(" shirt", " idea");	// 编译器优化，没有调用移动构造函数，直接
																	// 让 cm4 引用返回的临时对象，并延长其生命
																	// 周期，直到离开 cm4 所在的声明区域。
	show(cm4, "cm4:");
	cm4 = cm1 + Cpmv(" tree", " sky");	// 编译器优化，没有调用移动构造函数。
	show(cm4, "cm4:");
	
	swap(cm3, cm4);
	show(cm3, "cm3:");
	show(cm4, "cm4:");
	
	cm3.swap(cm4);
	show(cm3, "cm3:");
	show(cm4, "cm4:");
	
	return 0;
}
