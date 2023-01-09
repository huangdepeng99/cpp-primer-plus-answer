#ifndef _QUEUETP_H_
#define _QUEUETP_H_

template <typename T>
class QueueTP {
private:
    struct Node { T item; Node * next; };
    enum { Q_SIZE = 10 };
	
    Node * front;       // pointer to front of QueueTP
    Node * rear;        // pointer to rear of QueueTP
    int items;          // current number of items in QueueTP
    const int qsize;    // maximum number of items in QueueTP
public:
    explicit QueueTP(int qs = Q_SIZE);	// create queue with a qs limit
    QueueTP(const QueueTP & q) = delete;
    ~QueueTP();
    bool isempty() const { return items == 0; }
    bool isfull() const { return items == qsize; }
    int queuecount() const { return items; }
    bool enqueue(const T & item);	// add item to end
    bool dequeue(T & item);			// remove item from front
    QueueTP & operator=(const QueueTP & q) = delete;
};

// QueueTP<T> methods
template <typename T>
QueueTP<T>::QueueTP(int qs) : qsize(qs) {
    front = rear = nullptr;
    items = 0;
}

template <typename T>
QueueTP<T>::~QueueTP() {
    Node * temp;
    while (front != nullptr) {	// while queue is not yet empty
        temp = front;			// save address of front item
        front = front->next;	// reset pointer to next item
        delete temp;			// delete former front
    }
}

// Add item to queue
template <typename T>
bool QueueTP<T>::enqueue(const T & item) {
    if (isfull())
        return false;
    Node * add = new Node;	// create node
// on failure, new throws std::bad_alloc exception
    add->item = item;		// set node pointers
    add->next = nullptr;
    ++ items;
    if (front == nullptr)	// if queue is empty,
        front = add;		// place item at front
    else
        rear->next = add;	// else place at rear
    rear = add;				// have rear point to new node
    return true;
}

// Place front item into item variable and remove from queue
template <typename T>
bool QueueTP<T>::dequeue(T & item) {
    if (isempty())
        return false;
    item = front->item;     // set item to first item in queue
    -- items;
    Node * temp = front;    // save location of first item
    front = front->next;    // reset front to next item
    delete temp;            // delete former first item
    if (isempty())
        rear = nullptr;
    return true;
}

#endif
