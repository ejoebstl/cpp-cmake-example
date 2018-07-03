// System includes

// Standard IO and streams
#include <iostream>
// Algorithms, like sorting
#include <algorithm>
// String
#include <string>
// Vector container
#include <vector>
// For shared ptr
#include <memory>

// Local includes
#include "../lib/headerOnlyClass.hpp"
#include "../lib/regularClass.hpp"

#pragma region allocation 
void allocation() {
    // Declaration of any object already allocates the memory for it, hence we needed to pass the appropriate param already. 
    RegularClass a(3);
    // Member access for instances: .
    a.sayA();

    // This is a raw pointer. You should never do this!
    RegularClass *b = NULL;
    b = new RegularClass(2);
    // Member access for pointers: ->
    b->sayA();
    // Or explicit dereferencing
    (*b).sayA();
    // Don't forget to free your memory. 
    delete b;

    // When you use dynamic allocations, rather use a shared_ptr.
    std::shared_ptr<RegularClass> c = std::make_shared<RegularClass>(1);
    c->sayA();
    // Feels like a pointer but will automatically release the memory when ref count goes to zero or the shared ptr is resetted. 
    c.reset();
}
#pragma endregion

#pragma region callingAndTypeInferrence 

// This are templated functions. 
// Templated functions have to be in the header to 100%, 
// as the compiler generates a new method for each type used. 

// Passes a copy
template<typename T>
void callCopy(T x) {
    x.sayA();
}

// Passes a compiler managed pointer
template<typename T>
void callReference(T& x) {
    x.sayA();
}

// Passes a raw pointer
template<typename T>
void callPointer(T* x) {
    x->sayA();
}

void callingAndTypeInferrence() {
    HeaderOnlyClass h(2);

    // Different ways to call. 
    // Type inferrence is done by the compiler. 
    callCopy(h);
    callReference(h);
    callPointer(&h);
}

#pragma endregion

#pragma region stlContainers

void stlContainers() {
    // This is a vector containing ints. 
    std::vector<int> intVector;

    for(int i = 0; i < 10; i++)
        intVector.push_back(i);

    int elementTwo = intVector[1];

    // Careful, this ref breaks when we resize or move the vector!
    int& refToElementTwo = intVector[1];
    refToElementTwo = 10;

    std::cout << "Manipulated vector element: " << intVector[1] << std::endl;

    // Sort the vector using a lambda comperator
    std::sort(intVector.begin(), intVector.end(), [](const int a, const int b) {
        return a < b;
    });

    // Sort the back half of the vector using a lambda comperator
    std::sort(intVector.begin() + (intVector.size() / 2), intVector.end(), [](const int a, const int b) {
        return a < b;
    });

    int sum1 = 0;

    // Iterate over the vector
    // Use auto as iterater type as iterator types are loooong
    for(auto it = intVector.begin(); it != intVector.end(); it++) {
        // It "behaves" like a pointer. 
        sum1 += *it;
    } 

    int sum2;

    // We can also do for each
    for(const int& a : intVector) {
        sum2 += a;
    }

    std::cout << "Sum 1: " << sum1 << ", sum 2: " << sum2 << std::endl;
}

#pragma endregion

int main() {

    allocation();
    callingAndTypeInferrence();
    stlContainers();
    return 0;
}