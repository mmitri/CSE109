// Inside of library source file

// template instances

// Node<int>
// Node<char>
// Node<short>

#include "linkedlist.hpp"
#include <stdio.h>
#include <string>

template class List<char>;
template class List<int>;
template class List<std::string>;
template class List<short>;
template class List<float>;
template class List<long>;
template class List<void>;
template class List<wchar_t>;
template class List<long int>;
template class List<short int>;
template class List<signed long int>;
template class List<unsigned long int>;
template class List<bool>;


