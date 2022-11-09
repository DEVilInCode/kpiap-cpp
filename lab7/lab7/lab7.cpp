#include <iostream>

template<class Type, size_t N>
Type _max(Type(&Array)[N])
{
    Type tmp = Array[0];
    for (size_t i = 0; i < N; i++)
    {
        if (Array[i] > tmp)
            tmp = Array[i];
    }
    return tmp;
}

template<class Type, size_t N>
void _swap(Type(&Array)[N], Type from, Type to)
{
    for (size_t i = 0; i < N; i++)
    {
        if (Array[i] == from)
            Array[i] = to;
    }
}


template <typename T>
class SimpleArray {
public:
    SimpleArray(size_t numOfElements) :elements(new T[numOfElements]), size(numOfElements) {}

    ~SimpleArray() {
        delete[] elements;
    }

    void setElement(size_t index, T value) {
        elements[index] = value;
    }

    T getElement(size_t index) const {
        return elements[index];
    }

    size_t getSize() {
        return size;
    }

    void setSize(size_t size) {
        this->size = size;
    }

protected:
    T* elements = nullptr;
    size_t size = 0;
};

template <>
class SimpleArray<std::string>
{
    SimpleArray(size_t numOfElements) :elements(new std::string[numOfElements]), size(numOfElements) {}

    ~SimpleArray() {
        delete[] elements;
    }

    void setElement(size_t index, std::string value)
    {
        elements[index] = value;
    }

    std::string getElement(size_t index, std::string value) {
        elements[index] = value;
    }

    size_t getSize() {
        return size;
    }

    void setSize(size_t size) {
        this->size = size;
    }

protected:
    std::string* elements = nullptr;
    size_t size = 0;
};

int main()
{
    SimpleArray<int> array{ 4 };
    array.setElement(0, 1);
    array.setElement(1, 2);
    array.setElement(2, 3);
    array.setElement(3, 4);

    for (size_t i = 0; i < 4; i++)
    {
        std::cout << array.getElement(i) << std::endl;
    }

    int a[9] = { 1, 2, 7, 3, 9, 0, 5, 11, 13 };
    std::cout << _max(a) << std::endl;
    _swap(a, 13, 15);
    std::cout << _max(a) << std::endl;

    char b[3] = { 'b','c','a' };
    std::cout << _max(b) << std::endl;

    double c[3] = { 1.1, 1.3, 1.2 };
    std::cout << _max(c) << std::endl;

    return 0;
}