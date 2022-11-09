#include <iostream>

using namespace std;

class Integer
{
public:
    Integer(int num)
    {
        if (num >= 0)
            number = num;
        else
            number = num * -1;
    }

    int get()
    {
        return number;
    }

    void set(int num)
    {
        if (num >= 0)
            number = num;
        else
            number = num * -1;
    }

    void show()
    {
        cout << number << endl;
    }

    Integer operator ++()
    {
        number += 5;
        return *this;
    }

    Integer operator --()
    {
        number -= 5;
        if (number < 0)
            number = 0;
        return *this;
    }

    Integer operator=(Integer a)
    {
        number = a.number;
        return *this;
    }

    Integer operator()(int a)
    {
        if (a >= 0)
            number = a;
        else
            number = a * -1;
        return *this;
    }

    friend ostream& operator << (ostream& os, const Integer& a)
    {
        return os << a.number;
    }

    friend bool operator==(const Integer& a, const Integer& b)
    {
        return a.number == b.number;
    }

    friend const bool operator<(const Integer& a, const Integer& b)
    {
        return a.number < b.number;
    }

    friend const bool operator>(const Integer& a, const Integer& b)
    {
        return a.number > b.number;
    }

    friend const Integer operator+(const Integer& a, const Integer& b)
    {
        return Integer(a.number + b.number);
    }

    friend const Integer operator-(const Integer& a, const Integer& b)
    {
        int res = a.number - b.number;

        if (res < 0)
            return Integer(0);

        return Integer(res);
    }

    friend Integer operator+=(Integer& a, const Integer& b)
    {
        a.number += b.number;
        return a;
    }

    friend Integer operator-=(Integer& a, const Integer& b)
    {
        a.number -= b.number;

        if (a.number < 0)
            return Integer(0);

        return a;
    }

    operator int() const
    {
        return number;
    }



private:
    int number;
};

int main()
{
    Integer in(5);
    cout << in << endl;
    ++in;
    in.show();
    --in;
    in.show();

    Integer an(3);

    an = an + in;
    an.show();
    an += in;
    an -= in;
    an(27);
    an.show();
    cout << int(an) + 3;
    if (an > in)
        cout << "YES";
}