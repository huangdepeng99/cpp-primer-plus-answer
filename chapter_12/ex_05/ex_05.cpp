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
    Queue line(qs);         // line queue holds up to qs people
	
    const int hours = 100;              //  hours of simulation
    // simulation will run 1 cycle per minute
    const long cyclelimit = MIN_PER_HR * hours; // # of cycles
	
    double perhour;         //  average # of arrival per hour
    double min_per_cust;    //  average time between arrivals
	
    Item temp;              //	new customer data
	long customers = 0;		//	joined the queue
    int wait_time = 0;      //  time until autoteller is free
    long line_wait = 0;     //  cumulative time in line
    long served = 0;        //  served during the simulation
	double average_wait_time = 0.0;
	
// running the simulation
	for (perhour = 1.0; average_wait_time < 1.0; perhour += 1.0) {
		min_per_cust = MIN_PER_HR / perhour;
		for (int cycle = 0; cycle < cyclelimit; ++ cycle) {
			if (newcustomer(min_per_cust)) {	// have newcomer
				if (!line.isfull()) {
					++ customers;
					temp.set(cycle);    // cycle = time of arrival
					line.enqueue(temp); // add newcomer to line
				}
			}
			if (wait_time <= 0 && !line.isempty()) {
				line.dequeue(temp);      // attend next customer
				wait_time = temp.ptime(); // for wait_time minutes
				line_wait += cycle - temp.when();
				++ served;
			}
			if (wait_time > 0)
				wait_time--;
		}
		
		if (customers > 0) {
			average_wait_time = (double) line_wait / served;
		}
		while (!line.isempty())
			line.dequeue(temp);
		customers = wait_time = line_wait = served = 0;
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
