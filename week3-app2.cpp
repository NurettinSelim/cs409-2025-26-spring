// core language definitions:
// - C++ reference vs pointers
// - l-value / r-value
// - chain assignment
// - constness: east/west const, pointers and const

// --- OOP basics
// ctor/dtor
// copy-ctor, copy-assignment
// move-ctor, move-assignment (not covered in CS321)
// inheritance (not covered in CS321)

// --- Functional Programming Basics
// function / operator overloading

// reflection
//   auto, sizeof, sizeof..., typeid (RTTI), decltype, ...

// Generics / Templates:
// function, class, variable, type templates

#include <iostream>
#include <string>


using namespace std;

// can work with only l-value stuff at call-site
// why? references are pointers under the hood
// temporary values cannot be pointed since they don't have a variable name
void func(int& a) {
    // a++;

}

// this one can bind to both l-value and r-value variables
// because of the read-only promise we gave to the compiler
void func2(const int& a) {

}

void func3(int&& a) {

}


void dosmt(string&& str) {
    auto s = str;
    // ...

}

// struct STRING {
//     char* data;
//     STRING(const STRING& other) {
//         // do necessary memory allocations and cloning from other
//     }

//     // stealing version is called move c-tor
//     STRING(STRING&& other) : data(...) {
//         // here directly steal data attribute to ourselves from other's data

//     }
// };

int main(int argc, char* argv[])
{
    // func(10); // will not be allowed

    int a = 10;
    func(a); // will be allowed

    auto s = std::string("Hi there");
    dosmt((string&&)s);

    func3(10);

    return 0;
}
