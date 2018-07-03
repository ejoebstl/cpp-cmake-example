// This is an example for a class that
// is backed by a cpp file. 

// Note that we did not include iostream here!

// This is called a include guard
#ifndef CPP_CMAKE_EXAMPLE_REGULAR_CLASS
#define CPP_CMAKE_EXAMPLE_REGULAR_CLASS

class RegularClass {
public: 
    int a;
   
    // This is a constructor with an initializer list
    RegularClass(int a) : a(a) { }

    void sayA();
};

#endif