#ifndef __ARRAY__
#define __ARRAY__

template <class T>
class Array {
    protected:
        T *data;
        int len;
    public:
        Array(int size);
        ~Array();
        int length();
        T& operator[](int idx);
        T operator[](int idx) const;
        void print();
};
#endif
