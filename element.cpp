#include <sstream>
#include <iostream>
#include "element.h"

//=========================================================================
// base constructor
// Parameters: none
// Returns:	new Element object
// Creates an empty Element object
//=========================================================================
template <class D, class T>
Element<D,T>::Element() : data(D()), key(T()) {
    // Default constructor of T is used to initialize item
    // For int, it initializes to 0 (using std::numeric_limits), for std::string, it initializes to empty string
}

//=========================================================================
// parameter constructor
// Parameters: 
//  d - data value for the element
//  k - key for the element
// Returns:	none
//=========================================================================
template <class D, class T>
Element<D,T>::Element( D d, T k )
// Pre condition: d and k are valid entries for the element type
// Post condition: an element is created with d as the data and k as the key 
{
	data = d;
	key = k;
}


//=========================================================================
// get_key
// Parameters: none
// Returns:	
//  key - int value of the element's key 
//=========================================================================
template <class D, class T>
T Element<D,T>::get_key( void ) const
// Pre condition: element exists 
// Post condition: correct key vlaue of the element is returned  
{
    return key;
}


//=========================================================================
// get_data
// Parameters: none
// Returns:	
//  item - data value of the element 
//=========================================================================
template <class D, class T>
D Element<D,T>::get_data( void ) const
// Pre condition: element exists 
// Post condition: correct data value of the element is returned 
{
    return data;
}

//=========================================================================
// to_string
// Parameters: none
// Returns:	
//  string - the string containing the data and key of an element 
//=========================================================================
template <class D, class T>
string Element<D,T>::to_string() const 
// Pre condition: element exists 
// Post condition: string contains correct data and key value of the element
{
    ostringstream out;
    out << "(" << data << "," << key << ")";
    return out.str();
}
