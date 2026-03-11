#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct Vector {
    T* data;
    size_t size;

    Vector(size_t size) : data(new T[size]), size(size) { }
    ~Vector() {
        delete[] data;
    }

    void operator=(const Vector<T>& other) { // copy assignment
        delete[] this->data;
        this->data = new T[other.size];
        this->size = other.size;

        cout << "Copy assignment got called" << endl;
        auto src_ptr = &other.data[0];
        auto dest_ptr = &this->data[0]; // (data + 0)
        for(auto i=0; i<this->size; i++)
            *dest_ptr++ = *src_ptr++;
    }

    Vector(const Vector<T>& other) : data(new T[other.size]), size(other.size) { // copy c-tor
        cout << "Copy c-tor got called" << endl;
        auto src_ptr = &other.data[0];
        auto dest_ptr = &this->data[0]; // (data + 0)
        for(auto i=0; i<this->size; i++)
            *dest_ptr++ = *src_ptr++;
        // *this = other;
    }

    void operator=(Vector<T>&& other) { // move assignment
        delete[] this->data;
        this->data = other.data;
        this->size = other.size;

        other.data = nullptr;

        cout << "Move assignment got called" << endl;
    }

    Vector(Vector<T>&& other) : data(other.data), size(other.size) { // move c-tor
        cout << "Move c-tor got called" << endl;
        other.data = nullptr;
    }


    Vector(std::initializer_list<T> il) : data(new T[il.size()]), size(il.size()) {
        auto src_ptr = il.begin();
        auto dest_ptr = &data[0]; // (data + 0)
        for(auto i=0; i<il.size(); i++)
            *dest_ptr++ = *src_ptr++;
            // data[i] = il.begin()[i];
            // data[i] = *(il.begin() + i);
        // cout << il.begin() << endl;
        // cout << il.size() << endl;
    }

    T& get(size_t index) const {
        // auto t = TypeDisplay<T>();
        return data[index]; // *(data + index);
    }

    // T& get(size_t index) const {
    //     return data[index]; // *(data + index);
    // }

    T& operator[](size_t index) const {
        return data[index]; // *(data + index);
    }

    void print() const {
        for(auto i=0; i<this->size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};


// template<typename T>
// void ConstructVector(Vector<T>* ptr, size_t size) {
//     ptr->size = size;
//     ptr->data = new T[size];
// }

template<typename T>
struct TypeDisplay;

int main(int argc, char* argv[])
{
    auto v0 = Vector<float>{10, 20};
    auto v1 = Vector<float>{1, 2, 30};
    auto value = v1.get(1);
    // v1.get(2) = 50;
    v1[2] = 50;
    v1.operator[](2) = 50;

    // v1[2] = 50;

    // a + b;
    // -c;
    // +c;
    // operator+(a, b);

    v1.print();
    cout << value << endl;

    // Vector<float> v2(v1); // old c++ syntax, copy c-tor
    auto v2 = v1; // new c++ syntax, copy c-tor

    v2.print();
    v2 = v0; // copy assignment
    // v2.operator=(v0);

    v2.print();

    auto v3 = (Vector<float>&&)v2;
    v3.print();

    // v3 = (Vector<float>&&)v1; // from now on v1 cannot be used. v1 is emoty anyway.
    v3 = std::move(v1); // from now on v1 cannot be used. v1 is emoty anyway.
    v3.print();

    // auto v2 = Vector<int>(5);
    return 0;
}
