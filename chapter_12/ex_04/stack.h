#ifndef _STACK_H_
#define _STACK_H_

typedef unsigned long Item;

class Stack {
private:
    enum {MAX = 10};    // constant specific to class
    Item * pitems;		// holds stack items
	int size;			// number of elements in stack
    int top;            // index for top stack item
public:
    explicit Stack(int n = MAX);		// create stack with n elements
	Stack(const Stack & st);
	~Stack();
    bool isempty() const { return top == 0; };
    bool isfull() const { return top == size; };
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item);          // pop top into item
	Stack & operator=(const Stack & st);
};
#endif
