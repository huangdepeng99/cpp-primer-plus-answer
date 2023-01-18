#include <iostream>
#include "tv.h"

bool Tv::volup() {
    if (volume < MaxVal) {
        ++ volume;
        return true;
    }
    else
        return false;
}
bool Tv::voldown() {
    if (volume > MinVal) {
        -- volume;
        return true;
    }
    else
        return false;
}

void Tv::chanup() {
    if (channel < maxchannel)
        ++ channel;
    else
        channel = 1;
}

void Tv::chandown() {
    if (channel > 1)
        -- channel;
    else
        channel = maxchannel;
}

void Tv::settings() const {
    using std::cout;
    using std::endl;
	
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if (ison()) {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
			 << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = "
             << (input == TV ? "TV" : "DVD") << endl;
    }
}

void Tv::set_method(Remote & r) {
	if (ison())
		r.set_method();
}

void Remote::show_method() const {
	std::cout << "Method is " << (method == Normal ? "Normal" : "Interactive") << std::endl;
}
