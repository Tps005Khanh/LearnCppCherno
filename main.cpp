#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_name;
    int m_age;

public:
    // Constructor that accepts a string name
    //explicit Entity(const std::string& name) 
    Entity(const std::string& name) 
    : m_name(name), m_age(20) {}

    // Constructor that accepts an integer age
    //explicit Entity(int age)
    Entity(int age)
        : m_name("Name"), m_age(age) {}

    ~Entity() {}

    void Print() const {
        std::cout << "Name: " << m_name << ", Age: " << m_age << '\n';
    }
};

void PrintEntity(const Entity& entity)
{
    entity.Print();
}

int main()
{
    PrintEntity(22);                          // Call constructor from int
    PrintEntity(std::string("Cherno"));       // Call constructor from std::string

    Entity a = std::string("Cherno");         // OK
    Entity b = 20;                            // OK

    a.Print();
    b.Print();

    return 0;
}
