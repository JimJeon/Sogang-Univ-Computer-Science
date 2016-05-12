#ifndef __GROWABLE_ARRAY__
#define __GROWABLE_ARRAY__

#include"Array.h"

template <class T>
class GrowableArray : public Array<T> {
    public:
        GrowableArray(int size);
        ~GrowableArray();
        T& operator[] (int idx);
};
#endif
