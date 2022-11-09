#include <iostream>

class Exception
{
public:
    std::string E_err;
    Exception():E_err("\nError detected: "){}
    virtual const std::string getError() = 0;
};

class DevZero: public Exception {
public:
    std::string Z_err;
    DevZero():Z_err("Divided by zero."){}
    virtual const std::string getError() override
    {
        return E_err + Z_err;
    }
};

class MemErr: public Exception {
public:
    std::string Mem_err;
    MemErr():Mem_err("Memory error."){}
    virtual const std::string getError() override
    {
        return E_err + Mem_err;
    }
};

class NullErr :public Exception {
public:
    std::string Null_err;
    NullErr():Null_err("Null pointer error."){}
    virtual const std::string getError() override {
        return E_err + Null_err;
    }
};

template <typename T>
class Stack
{
public:
    Stack():head(nullptr), next(nullptr), size(0), data(NULL) {}

    ~Stack() {
        Stack*tmp1, * tmp = head;
        while (tmp)
        {
            tmp1 = tmp;
            tmp = tmp->next;
            delete tmp1;
        }
    }

    void push(T data) {
        Stack* tmp;
        size++;
        if (head != nullptr) {
            tmp = new Stack;
            tmp->next = head;
            tmp->data = data;
            head = tmp;  
        }
        else {
            head = new Stack;
            head->data = data;
        }
    }

    void display()
    {
        Stack* tmp = head;
        try
        {
            if (tmp == nullptr)
                throw NullErr();
        }
        catch (const std::exception&)
        {
            std::cout << ex.getError() << std::endl;
        }
        
        do
        {
            std::cout << tmp->data << ' ';
            tmp = tmp->next;
        } while (tmp != nullptr);
            std::cout << std::endl;
        
    }

    T operator[](size_t position)
    {
        T data = NULL;
        try {
            if (head == nullptr)
                throw NullErr();

            data = head->data;
            Stack* tmp = head;
       
            if (position > size - 1) 
                throw MemErr();
            
            for(;position > 0; position--)
                tmp = tmp->next;
            data = tmp->data;
        }
        catch (Exception& ex)
        {
            std::cout << ex.getError() << std::endl;
        }

        return data;
    }

protected:
    Stack* head;
    Stack* next;
    size_t size;
    T data;
};

int main()
{
    Stack<int> stack;
    stack.push(2);
    stack.push(3);
    stack.push(4);
    std::cout << stack[3] << std::endl;
    stack.display();
}