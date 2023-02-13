#ifndef QUEUE_MS_H_
#define QUEUE_MS_H_

#include <queue>
#include <utility>

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

template<typename T, typename Container = std::queue<T> >
class queue_ms {
public:
	using container_type = Container;
	using value_type = typename container_type::value_type;
	using reference = typename container_type::reference;
	using const_reference = typename container_type::const_reference;
	using size_type = typename container_type::size_type;
private:
	static const size_type MAX_SIZE = 10;
	container_type c;
	size_type maxsize;
public:
	explicit queue_ms(size_type ms = MAX_SIZE)
		: maxsize(ms) { }
	bool isempty() const { return c.empty(); }
	bool isfull() const { return c.size() == maxsize; }
	size_type max_size() const { return maxsize; }
	size_type queuecount() const { return c.size(); }
	bool enqueue(const_reference item);
	bool enqueue(value_type && item);
	bool dequeue(reference item);
};

template<typename T, typename Container>
bool queue_ms<T, Container>::enqueue(const_reference item) {
	if (isfull())
		return false;
	c.push(item);
	return true;
}

template<typename T, typename Container>
bool queue_ms<T, Container>::enqueue(value_type && item) {
	if (isfull())
		return false;
	c.push(std::move(item));
	return true;
}

template<typename T, typename Container>
bool queue_ms<T, Container>::dequeue(reference item) {
	if (isempty())
		return false;
	item = c.front();
	c.pop();
	return true;
}

#endif
