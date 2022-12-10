#include "stack.h"

bool Stack::push(const Item & item) {
    if (!isfull()) {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item) {
    if (!isempty()) {
        item = items[--top];
        return true;
    }
    else
        return false; 
}
