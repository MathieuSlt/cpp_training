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
        //todo
        data = (int *)realloc(data, sizeof(int) * capacity * 2);
    }

public:
    //Ctor
    vector() {
        //todo
        capacity = 1;
        current = 0;
        data = (int *)malloc(sizeof(int) * capacity);
    }
    //Dtor
    ~vector() {
        //todo
        free(data);
    }

    // Current number of elements in the vector
    unsigned size() const {
        //todo
        return current;
    }

    // Remove last element
    void pop_back() {
        current--;
    }
        

    // Add an element at the back of the vector
    void push_back(int v) {
        //todo
        if (current >= capacity) {
            data = (int *)realloc(data, sizeof(int) * capacity * 2);
            capacity *= 2;
            if (data) {
                *(data + current) = v;
                current++;
            }
        } else {
            *(data + current) = v;
            current++;
        }
    }

    // Read access
    int operator[](int i) const {
        //todo
        return data[i];
    }

    // Read-Write access
    int& operator[](int i) {
        //todo
        return *(this->data + i);
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