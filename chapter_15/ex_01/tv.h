#ifndef TV_H_
#define TV_H_

class Remote;

class Tv {
private:
    int state;             // on or off
    int volume;            // assumed to be digitized
    int maxchannel;        // maximum number of channels
    int channel;           // current channel setting
    int mode;              // broadcast or cable
    int input;             // TV or DVD
public:
    enum { Off, On };
    enum { MinVal, MaxVal = 20 };
    enum { Antenna, Cable };
    enum { TV, DVD };
	
    explicit Tv(int s = Off, int mc = 125) : state(s), volume(5),
        maxchannel(mc), channel(2), mode(Cable), input(TV) { }
    void onoff() { state = (state == On) ? Off : On; }
    bool ison() const { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
    void set_input() { input = (input == TV) ? DVD : TV; }
    void settings() const; // display all settings
	void set_method(Remote & r);
    friend class Remote;   // Remote can access Tv private parts
};

class Remote {
private:
    int mode;			// controls TV or DVD
	int method;			// Normal or Interactive
public:
	enum { Normal, Interactive };
	
    explicit Remote(int m = Tv::TV, int mt = Normal) : mode(m), method(mt) { }
    bool volup(Tv & t) { return t.volup(); }
    bool voldown(Tv & t) { return t.voldown(); }
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) { t.chanup(); }
    void chandown(Tv & t) { t.chandown(); }
    void set_chan(Tv & t, int c) { t.channel = c; }
    void set_mode(Tv & t) { t.set_mode(); }
    void set_input(Tv & t) { t.set_input(); }
	void set_method() { method = (method == Normal) ? Interactive : Normal; }
	void show_method() const;
	friend class Tv;	// Tv can access Remote private parts
};

#endif
