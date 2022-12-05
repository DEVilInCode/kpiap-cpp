#include <iostream>

class Animal
{
public:
    Animal(std::string name, int age):name(name), age(age)
    {

    }
    virtual ~Animal()
    {
        std::cout << "Base destructor" << std::endl;
    }

    virtual void show()
    {
        std::cout << name << " " << age << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, Animal an)
    {
        os << an.name << " " << an.age;
        return os;
    }

protected:
    std::string name;
    int age;
};

class Chicken : public Animal
{
public:
    Chicken(std::string name, int age, int eggSize):Animal(name, age), eggSize(eggSize)
    {

    }
    ~Chicken() override { std::cout << "Chicken destructor" << std::endl; }

    void show() override final
    {
        std::cout << this->name << " " << this->age << " " << this->getSize() << std::endl;
    }

    int getSize() { return eggSize; }

private:
    int eggSize;
};

class Wolf :public Animal
{
public:
    Wolf(std::string name, int age, std::string victim):Animal(name, age), victim(victim){}
    ~Wolf() override 
    {
        std::cout << "Wolf destructor" << std::endl;
    }

    void show() override final
    {
        std::cout << this->name << " " << this->age << " " << this->victim << std::endl;
    }

    std::string getVictim() { return victim; }

private:
    std::string victim;
};

class Sheep:public Animal
{
public:
    Sheep(std::string name, int age, int grass) :Animal(name, age), grass(grass)
    {

    }
    ~Sheep() override
    {
        std::cout << "Sheep destructor" << std::endl;
    }

    void show() override final
    {
        std::cout << this->name << " " << this->age << " " << this->grass << std::endl;
    }

    int getGrass() { return grass; }

private:
    int grass;
};

int main()
{
    auto a = new Animal*[4];

    a[0] = new Animal("Animal", 1);
    a[1] = dynamic_cast<Animal*>(new Chicken("Chicken", 2, 3));
    a[2] = dynamic_cast<Animal*>(new Wolf("Wolf", 3, "Sheep"));
    a[3] = dynamic_cast<Animal*>(new Sheep("Sheep", 4, 3));

    auto* p = dynamic_cast<Chicken*>(a[1]);
    std::cout << p->getSize() << std::endl;

    for (size_t i = 0; i < 4; i++)
    {
        a[i]->show();
    }
    
    for (size_t i = 0; i < 4; i++)
    {
        delete a[i];
    }
    delete[] a;
    return 0;
}
