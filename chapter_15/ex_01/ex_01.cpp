#include <iostream>
#include "tv.h"

int main(void) {
    using std::cout;
	using std::endl;
	
    Remote grey;
	
    Tv s42;
    s42.onoff();
	grey.show_method();
	s42.set_method(grey);
	grey.show_method();
	
    Tv s58;
    s58.set_method(grey);
	grey.show_method();
	
    return 0; 
}
