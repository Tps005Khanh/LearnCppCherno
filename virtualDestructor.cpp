#include <iostream> 


class Entity
{
public:
  ~Entity() noexcept {std::cout << "Entity" << std::endl;} 
};
class Base
{
public:
    Base(){std::cout << "Base Constructor" << std::endl;};
    virtual ~Base(){std::cout << "Base Destructor" << std::endl;} //Remove and add virtual to see what difference
};

class Derived : public Base
{
//private:
    Entity *m_entity;
public:
    Derived(){m_entity = new Entity[5]; std::cout << "Derived Constructor" << std::endl;};
    ~Derived() {delete[] m_entity; std::cout << "Derived Destructor" << std::endl;}
};

int main()
{
    Base *base = new Base();
    delete base;
    std::cout << "-------------------------------------" << std::endl;
    Derived *derived = new Derived();
    delete derived;
    std::cout << "-------------------------------------" << std::endl;
    Base *baseDerived = new Derived();
    delete baseDerived;
    return 0;
}