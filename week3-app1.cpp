// OOP as folders, primitives/objects files

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

struct Vector2d {
    int a;
    int b;
};

struct Real2d {
    double d; // offset 0
    float c; // offset 8
    // 4 byte padding

    // Real2d() : d(), c() { }
    // Real2d(double d, float c) : d(d), c(c) {}
};

// void foo(int a, int b, float c, double d, char e) {
void foo(Vector2d ab, Real2d cd, char e) {

}

// void bar(float c, double d, char e, int f) {
void bar(Real2d cd, char e, int f) {

}



void initReal2d(Real2d& x) { // pass by value

    // auto value = *x; // dereferencing operator *
    // x++;

    x.c = 10;
    // (*x).c = 10;
    x.d = 20.0;
}



using namespace std;

int func(int a) {
    if (a > 100)
        return 10;
    cout << "hi" << endl;
    return 0;
}


int main(int argc, char* argv[])
{
    // Real2d r2d;
    auto r2d = Real2d();

    std::cout << r2d.c << std::endl;

    initReal2d(r2d);

    std::cout << r2d.c << std::endl;

    auto x = r2d; // copy construction

    auto a = 10;
    func(200);
    10;

    // l-value: left value
    // r-value: right value



    return 0;
}
