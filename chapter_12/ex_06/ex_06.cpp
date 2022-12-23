#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main(void) {
    using std::cout;
    using std::endl;
// setting things up
    std::srand(std::time(0));    //  random initializing of rand()
	
    const int qs = 10;
    Queue line1(qs);         // line1 queue holds up to qs people
	Queue line2(qs);         // line2 queue holds up to qs people
	
    const int hours = 100;              //  hours of simulation
    // simulation will run 1 cycle per minute
    const long cyclelimit = MIN_PER_HR * hours; // # of cycles
	
    double perhour;         //  average # of arrival per hour
    double min_per_cust;    //  average time between arrivals
	
    Item temp;              //	new customer data
	long customers = 0;		//	joined the queues
    int wait_time1 = 0;      //  time until autoteller1 is free
	int wait_time2 = 0;      //  time until autoteller2 is free
    long line_wait = 0;     //  cumulative time in line
    long served = 0;        //  served during the simulation
	double average_wait_time = 0.0;
	
// running the simulation
	for (perhour = 1.0; average_wait_time < 1.0; perhour += 1.0) {
		min_per_cust = MIN_PER_HR / perhour;
		for (int cycle = 0; cycle < cyclelimit; ++ cycle) {
			if (newcustomer(min_per_cust)) {	// have newcomer
				if (!line1.isfull() || !line2.isfull()) {
					++ customers;
					temp.set(cycle);    // cycle = time of arrival
					if ((!line1.isfull() && !line2.isfull() && line1.queuecount() < line2.queuecount()) ||
						(!line1.isfull() && line2.isfull()))
						line1.enqueue(temp); // add newcomer to line1
					else
						line2.enqueue(temp); // add newcomer to line2
				}
			}
			if (wait_time1 <= 0 && !line1.isempty()) {
				line1.dequeue(temp);      // attend next customer
				wait_time1 = temp.ptime(); // for wait_time1 minutes
				line_wait += cycle - temp.when();
				++ served;
			}
			if (wait_time2 <= 0 && !line2.isempty()) {
				line2.dequeue(temp);      // attend next customer
				wait_time2 = temp.ptime(); // for wait_time2 minutes
				line_wait += cycle - temp.when();
				++ served;
			}
			if (wait_time1 > 0)
				-- wait_time1;
			if (wait_time2 > 0)
				-- wait_time2;
		}
		
		if (customers > 0) {
			average_wait_time = (double) line_wait / served;
		}
		while (!line1.isempty())
			line1.dequeue(temp);
		while (!line2.isempty())
			line2.dequeue(temp);
		customers = wait_time1 = wait_time2 = line_wait = served = 0;
	}
// reporting results
	cout << "Maximum size of queue: " << qs << endl;
	cout << "The number of simulation hours: " << hours << endl;
	cout << "Average number of customer per hour: " << perhour << endl;
	
    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x) {
    return (std::rand() * x / RAND_MAX < 1);
}
