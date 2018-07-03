// This is an example for a header-only class, 
// which does not have a corresponding C++ file. 
#include<iostream>

// This is called a include guard
#ifndef CPP_CMAKE_EXAMPLE_HEADER_ONLY_CLASS
#define CPP_CMAKE_EXAMPLE_HEADER_ONLY_CLASS

class HeaderOnlyClass {
public: 
    int a;
   
    // This is a constructor with an initializer list
    HeaderOnlyClass(int a) : a(a) { }

    void sayA() {
        std::cout << "Your A is: " << a << std::endl;
    }
};

#endif