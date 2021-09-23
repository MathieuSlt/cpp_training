#include <iostream>
#include <cassert>

// Only modify this class!
class vector{
private:
    int* data; // The buffer
    // Attributes to keep track of capacity and size? 
    int capacity;
    int current;
    // Call this to increase capacity
    // while preserving the elements already stored
    void alloc_(){
        this->capacity *= 2;
        int *tmp = new int[capacity];
        for (int i = 0; i <= this->current; i++)
            tmp[i] = this->data[i];
        delete[] data;
        this->data = tmp;
    }

public:
    //Ctor
    vector() {
        //todo
        capacity = 10;
        current = 0;
        data = new int[capacity];
    }
    
    //Dtor
    ~vector() {
        //todo
        delete[] data;
    }

    // Current number of elements in the vector
    unsigned size() const {
        //todo
        return this->current;
    }

    // Remove last element
    void pop_back() {
        this->current--;
    }

    // Add an element at the back of the vector
    void push_back(int v) {
        //todo
        if (current >= capacity) {
            alloc_();
        }
        data[current] = v;
        current++;
    }

    // Read access
    int operator[](int i) const {
        //todo
        return data[i % size()];
    }

    // Read-Write access
    int& operator[](int i) {
        //todo
        if (i < 0)
            i += this->current;
        return this->data[i];
    }
};

bool test_pb()
{
    vector v;
    //Testing push_back
    for (int i = 0; i < 1000; ++i)
        v.push_back(i);
    return v.size() == 1000;
}

bool test_acc_read()
{
    vector v;
    for (int i = 0; i < 100; ++i)
        v.push_back(i);
    const vector& vr = v;
    return (vr[10] == 10) && (vr[22] == 22) && (vr[92] == 92);
}

bool test_acc_write()
{
    vector v;
    for (int i = 0; i < 100; ++i)
    {
        v.push_back(i);
        v[i] *= 2;
    }
        
    const vector& vr = v;
    return (vr[10] == 2*10) && (vr[22] == 2*22) && (vr[92] == 2*92);
}

bool test_acc_neg()
{
    vector v;
    for (int i = 0; i < 100; ++i)
        v.push_back(i);
    std::cout << v[99]<< " should equal " << v[-1] << std::endl;
    std::cout << v[49]<< " should equal " << v[-51] << std::endl;
    return (v[99] == v[-1]) && (v[49] == v[-51]);
}

int main()
{
    if (!test_pb())
        return 1;
    std::cout << "test_pb passed\n";
    if (!test_acc_read())
        return 1;
    std::cout << "test_acc_read passed\n";
    if (!test_acc_write())
        return 1;
    std::cout << "test_acc_write passed\n";
    if (!test_acc_neg())
        return 1;
    std::cout << "Your vector passed the tests!";
    return 0;
}
