#ifndef QUEUE_MS_H_
#define QUEUE_MS_H_

#include <queue>

class Customer {
private:
    long arrive;        // arrival time for customer
    int processtime;    // processing time for customer
public:
    Customer() : arrive(0), processtime(0) { }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

template<typename T>
class queue_ms {
public:
	using value_type = T;
	using container_type = std::queue<value_type>;
	using reference = typename container_type::reference;
	using const_reference = typename container_type::const_reference;
	using size_type = typename container_type::size_type;
private:
	static const size_type MAX_SIZE = 10;
	container_type q;
	size_type maxsize;
public:
	explicit queue_ms(size_type ms = MAX_SIZE)
		: maxsize(ms) { }
	bool isempty() const { return q.empty(); }
	bool isfull() const { return q.size() == maxsize; }
	size_type max_size() const { return maxsize; }
	size_type queuecount() const { return q.size(); }
	bool enqueue(const_reference item);
	bool dequeue(reference item);
};

template<typename T>
bool queue_ms<T>::enqueue(const_reference item) {
	if (isfull())
		return false;
	q.push(item);
	return true;
}

template<typename T>
bool queue_ms<T>::dequeue(reference item) {
	if (isempty())
		return false;
	item = q.front();
	q.pop();
	return true;
}

#endif
