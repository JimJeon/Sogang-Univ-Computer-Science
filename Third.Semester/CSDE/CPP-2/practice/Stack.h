#include "LinkedList.h"
#ifndef __STACK__
#define __STACK__

template <class T>
class Stack : public LinkedList<T> {
public:
	virtual bool Delete(T& element) {
		if(first == NULL) return false; // null list
        Node <T> *current = first;

		first = current -> link; // move first to next node

		element = current -> data;
		delete current;
		current_size -= 1;
		return true;
	}
};
#endif