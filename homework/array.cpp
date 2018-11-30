#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <cmath>

template<typename T, size_t N>
class array
{
private:
    T *myarray;
public:

    array(){myarray = (T*) std::malloc(N*sizeof(T));}

    array(std::initializer_list<T> mylist): array(){
        size_t index{0};
        for (auto value : mylist){
            myarray[index] = value;
            ++index;
        }
    }


};

array<double, 10> a_default; // call default ctor
array<double, 10> a_init_list{1,2,3,4,5,6,7,8,9,10}; // call the one that takes an initializer list
