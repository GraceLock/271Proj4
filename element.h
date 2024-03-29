#include <iostream>
#include <string>
#include <chrono>

using namespace std;

// Header guards
#ifndef ELEMENT_H
#define ELEMENT_H

// Declaring element template class
template <class D, class T>
class Element 
{
private:
        D data;
        T key;

public:
    Element( void ); // empty constructor
    Element( const D data, const T k ); // parameter constructor

    T     get_key( void ) const;
    D       get_data( void ) const;
    string  to_string( void ) const;
};

#endif
