#include "queue_ms.h"
#include <cstdlib>		// (or stdlib.h) for rand()

// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
