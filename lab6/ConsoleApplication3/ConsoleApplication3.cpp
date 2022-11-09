#include <iostream>

class student
{
public:
    student(int age = 18, std::string name = "Default_name", int group = 0)
    {
        if (age >= 0)
            this->age = age;
        else
            this->age = age * -1;
        this->name = name;
        if (age >= 0)
            this->group = group;
        else
            this->group = group * -1;
    }

    virtual ~student()
    {
        std::cout << "Student destroyed" << std::endl;
    }

    virtual int income()
    {
        return group;
    }

protected:
    int age;
    std::string name;
    int group;
};

class studentA1 :student
{
public:
    studentA1(int age, std::string name, int group, int level) :student(age, name, group)
    {
        this->level = level;
    }
    virtual ~studentA1()
    {
        std::cout << "StudentA1 destroyed" << std::endl;
    }

    int income() override
    {
        return group * level;
    }

protected:
    int level;
};

class studentA2 :studentA1
{
public:
    studentA2(int age, std::string name, int group, int level, int special) :studentA1(age, name, group, level)
    {
        this->special = special;
    }
    ~studentA2()
    {
        std::cout << "StudentA2 destroyed" << std::endl;
    }

    int income() override
    {
        return special * level;
    }

protected:
    int special;
};

class worker :student
{
public:
    worker(int age, std::string name, int group, std::string work) :student(age, name, group)
    {
        this->work = work;
    }
    virtual ~worker()
    {
        std::cout << "Worker destroyed" << std::endl;
    }

    int income()override
    {
        return group * 2;
    }

protected:
    std::string work;
};

int main()
{
    student** obj = new student * [4];
    obj[0] = new student(21, "3.14", 10); // group
    obj[1] = (student*)(new studentA1(22, "Door", 11, 2)); // group * level
    obj[2] = (student*)(new studentA2(25, "GG", 14, 3, 12)); // special * level
    obj[3] = (student*)(new worker(28, "Worker", 111, "Prog")); //group * 2

    for (int i = 0; i < 4; i++)
    {
        std::cout << obj[i]->income() << std::endl;
    }

    return 0;
}