# Quicksort

---
### data_structure.h
__ELEMENT__  
&emsp;&emsp;unsigned int _score_  
&emsp;&emsp;float _data[3]_  
&emsp;&emsp;char _comments[16]_

---
### main.c

__function__ MAIN  
&emsp;&emsp;read command file  
&emsp;&emsp;get data from file  
&emsp;&emsp;run selected algorithm  
&emsp;&emsp;write data to file  

---
### io.h

__function__ READ-DATA(const char* _filename_, int _data cnt_) __returns__ ELEMENT* _data_  
&emsp;&emsp;make ELEMENT* _data_  
&emsp;&emsp;open _filename_ as "rb" mode  
&emsp;&emsp;read _score_, _data[3]_, _comments[16]_ from _filename_  
&emsp;&emsp;__return__ _data_

__function__ WRITE-DATA(const char* _filename_, ELEMENT* _data_) __returns__ written bytes  
&emsp;&emsp;open _filename_ as "wb" mode  
&emsp;&emsp;write _data_ to _filename_  
&emsp;&emsp;__return__ total bytes of written file  

---
### my_quick_sorts.h

__function__ PARTITION(void\* _base_, size_t _nmem_, size_t _size_, _int(\*compar)(const void\*, const void\*)_) __returns__ pivot data  
&emsp;&emsp;_pivot_ &larr; 1  
&emsp;&emsp;__for__ i in range(1,_nmem_)  
&emsp;&emsp;&emsp;&emsp;__if__ _compar(base + i \* size, base)_ < 0 __then__  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;SWAP(_base_, i, _pivot_, _size_)  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;_pivot_ &larr; _pivot_ + 1  
&emsp;&emsp;SWAP(_base_, 0, _pivot_, _size_)  
&emsp;&emsp;__returns__ _pivot_  

__function__ QSORT-ORIG(void\* _base_, size_t _nmem_, size_t _size_, _int (\*compar)(const void\*, const void\*)_) __returns__ sorted _data_  
&emsp;&emsp;__if__ nmem is not 0 __then__  
&emsp;&emsp;&emsp;&emsp;_pivot_ &larr; PARTITION(_base_, _nmem_, _size_, _compar_)  
&emsp;&emsp;&emsp;&emsp;QSORT-ORIG(_base_, _pivot_, _size_, _compar_)  
&emsp;&emsp;&emsp;&emsp;QSORT-ORIG(_base_ + (_pivot_ + 1) \* _size_, _nmem_ - _pivot_ - 1, _size_, _compar_)  

__function__ INSERTION-SORT(void\* _base_, size_t _nmem_, size_t _size_, _int (\*compar)(const void\*, const void\*)_) __returns__ sorted data  
&emsp;&emsp;__for__ i in range(1,_nmem_)  
&emsp;&emsp;&emsp;&emsp;j &larr; i - 1  
&emsp;&emsp;&emsp;&emsp;_tmp_ &larr; [_base_ + i \* _size_]  
&emsp;&emsp;&emsp;&emsp;__while__(j &ge; 0 __and__ _compar(base + j \* size, tmp)_ > 0)  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;[_base_ + (j + 1) \* _size_] &larr; [_base_ + j \* _size_]  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;j &larr; j - 1  
&emsp;&emsp;&emsp;&emsp;[_base_ + (j + 1) * _size_] &larr; _tmp_  

__function__ QSORT-MEDIAN-INSERT(void\* _base_, size_t _nmem_, size_t _size_, _int (\*compar)(const void\*, const void\*)_) __returns__ sorted _data_  
&emsp;&emsp;__if__ _nmem_ &le; 5 __then__ __return__  
&emsp;&emsp;_pivot_ &larr; MEDIAN(_base_, _base_ + (_nmem_ - 1) \* _size_, _base_ + (_nmem_ / 2) \* _size_)  
&emsp;&emsp;SWAP(_base_, _base_ + _pivot_ \* _size_)  
&emsp;&emsp;PARTITION(_base_, _nmem_, _size_, _compar_)  
&emsp;&emsp;QSORT-MEDIAN-INSERT(_base_, _pivot_, _size_, _compar_)  
&emsp;&emsp;QSORT-MEDIAN-INSERT(_base_ + (_pivot_ + 1) \* _size_, _nmem_ - _pivot_ - 1, _size_, _compar_)  
&emsp;&emsp;INSERTION-SORT(_base_, _nmem_, _size_, _compar_)

__function__ QSORT-MEDIAN-INSERT-ITER(void\* _base_, size_t _nmem_, size_t _size_, _int (\*compar)(const void\*, const void\*)_) __returns__ sorted _data_  
&emsp;&emsp;__if__ _nmem_ &le; 5 __then__ __return__  
&emsp;&emsp;_pivot_ &larr; MEDIAN(_base_, _base_ + (_nmem_ - 1) \* _size_, _base_ + (_nmem_ / 2) \* _size_)  
&emsp;&emsp;SWAP(_base_, _base_ + _pivot_ \* _size_)  
&emsp;&emsp;PARTITION(_base_, _nmem_, _size_, _compar_)  
&emsp;&emsp;__if__ _pivot_ < _nmem_ / 2 __then__  
&emsp;&emsp;&emsp;&emsp;QSORT-MEDIAN-INSERT-ITER(_base_, _pivot_, _size_, _compar_)  
&emsp;&emsp;__else__  
&emsp;&emsp;&emsp;&emsp;QSORT-MEDIAN-INSERT-ITER(_base_ + (_pivot_ + 1) \* _size_, _nmem_ - _pivot_ - 1, _size_, _compar_)  
&emsp;&emsp;

__function__ QSORT-FINAL(void\* _base_, size_t _nmem_, size_t _size_, _int (\*compar)(const void\*, const void\*)_) __returns__ sorted _data_  
&emsp;&emsp;QSORT(_base_, _nmem_, _size_, _compar_)  

---
