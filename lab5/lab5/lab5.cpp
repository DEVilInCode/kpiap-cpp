#include <iostream>
#include <string>

class student
{
public:
    student(int _age, std::string _name, int _group)
    {
        if (_age >= 0)
            this->age = _age;
        else
            this->age = _age * -1;
        this->name = _name;
        if (_group >= 0)
            this->group = _group;
        else
            this->group = _group * -1;
    }
    ~student()
    {
        std::cout << "Student destroyed" << std::endl;
    }

    friend std::ostream& operator <<(std::ostream& os, student& s)
    {
        return os << "Name: " << s.name << std::endl
            << "Age: " << s.age << std::endl
            << "Group: " << s.group << std::endl;
    }

protected:
    std::string name;
    int age;
    int group;
};

class goodStudent :student
{
public:
    goodStudent(int _age, std::string _name, int _group, int _averageMark) :student(_age, _name, _group)
    {
        if (_averageMark >= 0)
            this->averageMark = _averageMark;
        else
            this->averageMark = _averageMark * -1;
    }
    ~goodStudent()
    {
        std::cout << "GoodStudent destroyed" << std::endl;
    }
    friend std::ostream& operator <<(std::ostream& os, goodStudent& gs)
    {
        student s = student(gs);
        return os << s << "Average mark: " << gs.averageMark << std::endl;
    }

protected:
    int averageMark;
};

class veryGoodStudent :goodStudent
{
public:
    veryGoodStudent(int _age, std::string _name, int _group, int _averageMark, int _bonus) :goodStudent(_age, _name, _group, _averageMark)
    {
        if (_bonus >= 0)
            this->bonus = _bonus;
        else
            this->bonus = _bonus * -1;
    }
    ~veryGoodStudent()
    {
        std::cout << "VeryGoodStudent destroyed" << std::endl;
    }

    friend std::ostream& operator <<(std::ostream& os, veryGoodStudent& vgs)
    {
        goodStudent gs = goodStudent(vgs);
        return os << gs << "Bonus: " << vgs.bonus << std::endl;
    }

protected:
    int bonus;
};

class specialist :student
{
public:
    specialist(int _age, std::string _name, int _group, std::string _degree) :student(_age, _name, _group)
    {
        this->degree = _degree;
    }
    ~specialist()
    {
        std::cout << "Speciialist destroyed" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, specialist& spec)
    {
        student s = student(spec);
        return os << s << "Degree: " << spec.degree << std::endl;
    }

protected:
    std::string degree;
};

class worker :specialist
{
public:
    worker(int _age, std::string _name, int _group, std::string _degree, std::string _work) :specialist(_age, _name, _group, _degree)
    {
        this->work = _work;
    }
    ~worker()
    {
        std::cout << "Worker destroyed" << std::endl;
    }

    friend std::ostream& operator <<(std::ostream& os, worker& w)
    {
        specialist spec = specialist(w);
        return os << spec << "Work: " << w.work << std::endl;
    }

protected:
    std::string work;
};

class best :worker, veryGoodStudent
{
public:
    best(int _age, std::string _name, int _group, std::string _degree, std::string _work, int _averageMark, int _bonus, int _free) :worker(_age, _name, _group, _degree, _work), veryGoodStudent(_age, _name, _group, _averageMark, _bonus)
    {
        this->free = _free;
    }
    ~best()
    {
        std::cout << "Best destroyed" << std::endl;
    }

    friend std::ostream& operator <<(std::ostream& os, best& b)
    {
        worker w = worker(b);
        veryGoodStudent vgs = veryGoodStudent(b);
        return os << w << vgs << "Free: " << b.free << std::endl;
    }

protected:
    int free;
};

int main()
{
    best one(18, "Img", 1500, "Magistr", "Programmer", 9, 300, 1);
    std::cout << one;
}