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
### algorithm.h

__function__ QSORT-ORIG(void\* _base_, size_t _nmem_, size_t _size_, _int (\*compar)(const void\*, const void\*)_) __returns__ sorted _data_  
&emsp;&emsp;__if__ nmem is not 0 __then__ _pivot_ &larr; PARTITION(_base_, _nmem_, _size_, _compar_)  
&emsp;&emsp;



__function__ QSORT-MEDIAN-INSERT(void\* _base_, size_t _nmem_, size_t _size_, _int (\*compar)(const void\*, const void\*)_) __returns__ sorted _data_  
&emsp;&emsp;



__function__ QSORT-MEDIAN-INSERT-ITER(void\* _base_, size_t _nmem_, size_t _size_, _int (\*compar)(const void\*, const void\*)_) __returns__ sorted _data_  
&emsp;&emsp;



__function__ QSORT-FINAL(void\* _base_, size_t _nmem_, size_t _size_, _int (\*compar)(const void\*, const void\*)_) __returns__ sorted _data_  
&emsp;&emsp;


---
